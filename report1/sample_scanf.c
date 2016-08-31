/* sample_scanf.c: scanf()を用い、ユーザ入力を読み込むコード例 */

#include <stdio.h>

int main(){
    char input[100]; //読み込んだユーザ入力を格納する配列を用意。
        //本来は読み込む文字数を決め打ちせず、必要な分だけの配列を用意するべきだが、入門編では大きめのサイズで用意しておくことにする。

    printf("Please input some strings: "); //入力を促す説明文を出力。
    scanf("%s", input); //inputにユーザ入力を保存する。
    printf("Your input is %s\n",input); //正常に読み込めたか出力して確認する。

    return 0;
}

