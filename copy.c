#include <stdio.h>

int main(){
    char data[5] = "hoge";
    char result[5];
    int num;
    int i;

    num = sizeof(data)/sizeof(char) - 1; // ヌル文字を除いて、実際の文字数をカウント。

    //printf("num=%d\n",num);
    for(i=0; i<num; i++){
        result[i] = data[i];
        printf("data[%d] = %c, result[%d]=%c\n",i,data[i],i,result[i]);
    }
    result[i] = '\0';
    printf("data = %s\n",data);
    printf("reversed = %s\n",result);
}
