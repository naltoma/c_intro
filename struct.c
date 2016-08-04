#include <stdio.h>

struct student_score{
    char account[8];
    int score;
    char eval;
};

void print_struct(struct student_score); //構造体を出力するための関数。
char evaluation(int score); //点数をA~F判定する関数。

void print_struct(struct student_score stu){
    printf("account=%s, score=%d, eval=%c\n",stu.account,stu.score,stu.eval);
}

char evaluation(int score){
    char eval = 'F';
    if( score >= 90 ){
        eval = 'A';
    }else if ( score >= 80 ){
        eval = 'B';
    }else if ( score >= 70 ){
        eval = 'C';
    }else if ( score >= 60 ){
        eval = 'C';
    }else{
        eval = 'F';
    }
    return eval;
}

int main(){
    struct student_score students[3] = {{"e175701", 100, 'A'}, {"e175702", 70, '\0'}, {"e175703", 50, '\0'}};
    int i, num;

    num = sizeof(students)/sizeof(struct student_score);
    printf("データ初期値\n");
    for(i=0; i<num; i++){
        print_struct(students[i]);
    }

    printf("評価結果\n");
    for(i=0; i<num; i++){
        if( students[i].eval == '\0' ){
            students[i].eval = evaluation(students[i].score);
        }
        print_struct(students[i]);
    }
}
