#include <stdio.h>

int main(){
    const int size = 3;
    int data[size] = {100, 90, 80};

    //data[0]〜data[size]までアクセス
    for(int i=0; i<=size; i++){
        printf("data[%d] = %d\n",i,data[i]);
    }
}
