#include <stdio.h>
#define BOOKNAME_LENGTH 10

struct list{
    char bookname[BOOKNAME_LENGTH];
    int price;
    struct list *next; //自己参照
};

/* 構造体listを見やすく出力する関数 */
void print_list(struct list *data);
void print_list(struct list *data){
    printf("list(address=%p): %s, %d, %p\n",data,data->bookname,data->price,data->next);
}


/* アドレス参照先がNULLでない(=存在する)間、
   その先を参照し続け、出力する関数 */
void print_list_all(struct list *data);
void print_list_all(struct list *data){
    if( data != NULL ){
        print_list(data);
        if( data->next != NULL ){
            print_list_all(data->next);
        }
    }
}


int main(){
    printf("## step 0\n");
    printf("sizeof(struct list) = %lu\n",sizeof(struct list));
    struct list item1 = {"book1", 1000, NULL};
    struct list item2 = {"book2", 2000, NULL};
    struct list item3 = {"book3", 3000, NULL};
    print_list(&item1);
    print_list(&item2);
    print_list(&item3);

    //step 1: item1.nextにitem2のアドレスを保存
    printf("## step 1\n");
    item1.next = &item2;
    print_list(&item1);

    //step 2: item2.nextにitem3のアドレスを保存
    printf("## step 2\n");
    item2.next = &item3;
    print_list(&item2);

    //step 3: .nextがNULLになるまで参照し続ける
    printf("## step 3\n");
    print_list_all(&item1);

    return 0;
}
