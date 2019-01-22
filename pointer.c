#include <stdio.h>

int main(){
    int int1 = 10;
    float float1 = 10.0;
    char char1 = 'c';

    //step 1: int1, float1, char1の値、サイズ、アドレスは？
    printf("### Step1\n");
    printf("int1 = %d, size = %lu, address = %p\n",int1,sizeof(int1),&int1);
    printf("float1 = %f, size = %lu, address = %p\n",float1,sizeof(float1),&float1);
    printf("char1 = %c, size = %lu, address = %p\n",char1,sizeof(char1),&char1);

    //step 2: ポインタ変数が指す先の確認
    printf("### Step2\n");
    int *pointer_int = &int1;
    printf("*pointer_int = %d, size = %lu, address = %p\n",*pointer_int,sizeof(*pointer_int),&(*pointer_int));

    //step 3: ポインタ変数そのものの確認
    printf("### Step3\n");
    printf("pointer_int = %p, size = %lu, address = %p\n",pointer_int,sizeof(pointer_int),&pointer_int);

    //step 4: *pointer_floatについて
    printf("### Step4\n");
    float *pointer_float = &float1;
    printf("*pointer_float = %f, size = %lu, address = %p\n",*pointer_float,sizeof(*pointer_float),&(*pointer_float));

    //step 5: pointer_floatについて
    printf("### Step5\n");
    printf("pointer_float = %p, size = %lu, address = %p\n",pointer_float,sizeof(pointer_float),&pointer_float);

    //step 6: *pointer_charについて
    printf("### Step6\n");
    char *pointer_char = &char1;
    printf("*pointer_char = %c, size = %lu, address = %p\n",*pointer_char,sizeof(*pointer_char),&(*pointer_char));

    //step 7: pointer_charについて
    printf("### Step7\n");
    printf("pointer_char = %p, size = %lu, address = %p\n",pointer_char,sizeof(pointer_char),&pointer_char);
}
