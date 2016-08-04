#include <stdio.h>

int main(){
    char data[5] = "hoge";
    char result[5];
    int num;
    int i, index;

    num = sizeof(data)/sizeof(char) - 1; // ヌル文字を除いて、実際の文字数をカウント。

    //printf("num=%d\n",num);
    index = 0;
    for(i=num-1; i>=0; i--){
        result[index] = data[i];
        //printf("data[%d] = %c, result[%d]=%c\n",i,data[i],index,result[index]);
        index++;
    }
    result[index] = '\0';
    printf("data = %s\n",data);
    printf("reversed = %s\n",result);
}
