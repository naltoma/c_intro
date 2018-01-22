/* sample_func_array.c: 関数で配列を受け取るコード例 */

#include <stdio.h>

// 引数として型を指定する際に、配列ならば変数名に[]を加えて指定する。
void print_array(int array[], int size);
void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        printf("data[%d] = %d\n",i,array[i]);
    }
}


int main(){
    const int SIZE = 5; //定数として配列のサイズを宣言
    int scores[SIZE] = {0, 60, 70, 100, 90};

    // 関数呼び出し時には、引数として配列名をそのまま記述する。
    print_array(scores, SIZE);

    return 0;
}
