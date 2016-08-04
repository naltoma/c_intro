#include <stdio.h>

void fizzbuzz(int);

void fizzbuzz(int num){
    if ((num % 3 == 0) && (num % 5 == 0)){
        printf("FizzBuzz\n");
    }else if (num % 3 == 0){
        printf("Fizz\n");
    }else if (num % 5 == 0){
        printf("Buzz\n");
    }else{
        printf("%d\n",num);
    }
}

int main(){
    for(int i=1; i<=15; i++){
        fizzbuzz(i);
    }
    return 0;
}
