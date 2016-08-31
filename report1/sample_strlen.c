/* sample_strlen.c: strlen()を用い、格納されてる文字数をカウントするコード例 */

#include <stdio.h>
#include <string.h>

int main(){
    char data[100] = "test";
    int len1, len2;

    len1 = sizeof(data) / sizeof(char); //変数dataに格納できる文字数上限を確認
    len2 = strlen(data); //変数dataに格納されている文字数を確認

    printf("sizeof()の結果 = %d\n",len1);
    printf("strlen()の結果 = %d\n",len2);

    return 0;
}

