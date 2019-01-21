#include <stdio.h>
#include <string.h>

#define ACCOUNT_LETTER_SIZE 8 //アカウント文字数

//アカウント、点数、採点結果(A〜F)を保存するための構造体
struct student_score{
    char account[ACCOUNT_LETTER_SIZE];
    int score;
    char eval;
};

/*
  student_score配列を出力するための関数

  Note: 引数 *students について。
  構造体の配列を関数側で引数利用する際には、
  　(case 1) 関数呼び出し時に「変数名そのもの」を指定する。
  　(case 2) 関数呼び出し時に「&変数名[0]」のように、変数名冒頭に&を付け、インデックス指定しよう。
  配列を受け取る時には「*変数名」のように、変数名冒頭に*を付け、ポインタを受け取ろう。
*/
void print_student_score(struct student_score *students, int student_num);
void print_student_score(struct student_score *students, int student_num){
    printf("## current student_score\n");
    for(int i=0; i<student_num; i++){
        printf("%s, %d, %c\n",students[i].account,students[i].score,students[i].eval);
    }
}

/*
  student_score配列の二人を入れ替えるためのスワップ関数

  Note: 「->」演算子について。
  通常の構造体変数ならば、「構造体名.変数名」として参照できる。
  *により逆参照してるならば、「構造体名->変数名」として参照できる。
*/
void swap(struct student_score *student1, struct student_score *student2);
void swap(struct student_score *student1, struct student_score *student2){
    struct student_score temp;
    strcpy(temp.account, student1->account);
    temp.score = student1->score;
    temp.eval = student1->eval;
    
    strcpy(student1->account, student2->account);
    student1->score = student2->score;
    student1->eval = student2->eval;

    strcpy(student2->account, temp.account);
    student2->score = temp.score;
    student2->eval = temp.eval;
}


int main(){
    //3人分の点数を評価結果を準備。
    const int student_num = 3;
    struct student_score scores[student_num] = {{"e175790", 100, 'A'}, {"e175791", 70, 'C'}, {"e175792", 50, 'F'}};

    //scoresの中身を確認。
    print_student_score(scores, student_num);
    //print_student_score(scores[0], student_num);//NG
    //print_student_score(&scores[0], student_num);//OK, scoresと同じ結果。
    //print_student_score(&scores[1], student_num-1);//OK, 二人目から出力。

    //一人目と二人目を入れ替える。
    //&scores[0]は、scores[0]のアドレス（メモリ上の位置）を示している。（参照渡し）
    //アドレスを受け取る側（関数側）では、*valueとすることでアドレス先を参照できる。
    swap(&scores[0], &scores[1]);
    print_student_score(scores, student_num);

    return 0;
}

