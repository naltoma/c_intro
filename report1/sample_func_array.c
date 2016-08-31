/* sample_func_array.c: 関数で配列を受け取るコード例 */

#include <stdio.h>

// 引数として型を指定する際に、配列ならば変数名に[]を加えて指定する。
void print_string(char data[]);


void print_string(char data[]){
    printf("print_string(): data = %s\n",data);
}


int main(){
    char strings[100] = "This is test";

    // 関数呼び出し時には変数名をそのまま記述する。
    print_string(strings);
    return 0;
}

