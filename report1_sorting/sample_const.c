/* sample_const.c: 定数を宣言するコード例 */

#include <stdio.h>

int main(){
    const int SIZE = 5; //定数として配列のサイズを宣言
    int scores[SIZE] = {0, 60, 70, 100, 90};
    for(int i=0; i<SIZE; i++){
        printf("%d\n",scores[i]);
    }
}
