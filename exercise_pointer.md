# ポインタと構造体の演習
- イントロダクション
  - ポインタを使うことで変数を「参照」することができ、より柔軟に使うことができる。例えばPythonのlist.appendのようなことを、構造体＋ポインタで実現することができる。実際にはmalloc()も含めより深い知識が必要になるが、ここでは時間のある範囲でポインタについて取り組んでみよう。
  - より具体的な導入は、後続講義「アルゴリズムとデータ構造」でやります。
- ＜目次＞
  - <a href="#pointer1">演習4: int, float, charのポインタ変数を使ってみよう</a>
  - <a href="#pointer2">演習5: 自己参照ポインタを使ってみよう</a>
  - <a href="#pointer3">演習6: Pythonのリストのように、データを後から追加してみよう</a>

<hr>

## <a name="pointer1">演習4: int, float, charのポインタ変数を使ってみよう</a>
- 以下にように int, float, char 型のリテラルを保存した変数があるとする。

```C
#include <stdio.h>

int main(){
    int int1 = 10;
    float float1 = 10.0;
    char char1 = 'c';
}
```

- Step 1: int1, float1, char1の「値、メモリサイズ、アドレス」の3点を確認するコードを書け。
  - 動作確認項目
    - int型, float型は4バイト。char型は1バイトと出力されるはず。（コンパイラ依存）
- Step 2: int型変数を保存しているアドレスを指すためのポインタ変数を用意せよ。ポインタ変数名は ``pointer_int`` とする。このポインタ変数が指す先につて、「値、メモリ、アドレス」の3点を確認するコードを書け。
  - ヒント
    - ここでは「ポインタ変数が指す先」について確認したいので、``*pointer_int`` を変数名と見做し、Step 1 と同じ処理を書いてみよう。
    - ``*pointer_int`` のアドレスを確認する際には、``&(*pointer_int)`` として、カッコで括った上で冒頭に ``&`` を付けよう。
  - 動作確認項目
    - int1と*pointer_intは3項目（値、サイズ、アドレス）とも一緒になっているはず。
- Step 3: ポインタ変数が指す先ではなく、ポインタ変数そのものについて「値、メモリサイズ、アドレス」を確認してみよう。
  - ヒント
    - ここでは「ポインタ変数そのもの」について調べたいので、``pointer_int`` を変数名と見做し、Step 1と同じ処理を書いてみよう。
  - 動作確認項目
    - ポインタ変数そのもの値は、保存したポインタ（int1のアドレス）と同一のはず。
    - int型は4バイトなのに対し、ポインタ変数は8バイトになっているはず。
    - ポインタ変数のアドレスは、他変数のアドレスとは異なっているはず。

- Step1〜3の実行イメージ
  - 具体的なアドレスは状況依存で異なる。
  - 各変数がアドレス上にどのように並んでいるのか、確認してみよう（同じ順序になるとは限らないが、なるべく連続したメモリ上を使うように最適化されているはず）。

```
oct:tnal% ./a.out
### Step1
int1 = 10, size = 4, address = 0x7ffeec86a2fc
float1 = 10.000000, size = 4, address = 0x7ffeec86a2f8
char1 = c, size = 1, address = 0x7ffeec86a2f7
### Step2
*pointer_int = 10, size = 4, address = 0x7ffeec86a2fc
### Step3
pointer_int = 0x7ffeec86a2fc, size = 8, address = 0x7ffeec86a2e8
```

- Step 4: float型変数を保存しているアドレスを指すためのポインタ変数を用意せよ。ポインタ変数名は ``pointer_float`` とする。このポインタ変数が指す先について、「値、メモリ、アドレス」の3点を確認するコードを書け。
  - float1と同じになることを確認しよう。
- Step 5: pointer_floatそのものについて、「値、メモリ、アドレス」の3点を確認するコードを書け。
- Step 6: char型変数を保存しているアドレスを指すためのポインタ変数を用意せよ。ポインタ変数名は ``pointer_char`` とする。このポインタ変数が指す先について、「値、メモリ、アドレス」の3点を確認するコードを書け。
  - char1と同じになることを確認しよう。
- Step 7: pointer_charそのものについて、「値、メモリ、アドレス」の3点を確認するコードを書け。

- Step4〜7の実行イメージ

```
### Step4
*pointer_float = 10.000000, size = 4, address = 0x7ffee7b2a2f8
### Step5
pointer_float = 0x7ffee7b2a2f8, size = 8, address = 0x7ffee7b2a2e0
### Step6
*pointer_char = c, size = 1, address = 0x7ffee7b2a2f7
### Step7
pointer_char = 0x7ffee7b2a2f7, size = 8, address = 0x7ffee7b2a2d8
```

- 回答例: [pointer.c](./pointer.c)

<hr>

## <a name="pointer2">演習5: 自己参照ポインタを使ってみよう</a>
- 以下のように構造体が定義＆初期化されているとする。
  - 補足
    - list構造体について。list型.nextは、list型を参照している。このように、自分自身の構造体を指すポインタを「自己参照ポインタ」と呼ぶ。
    - print_list関数について。構造体の変数を関数に渡す際には、呼び出し側からアドレスを渡し、関数側からポインタ変数で受け取っている点に注意。

```C
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
    printf("list(address=%p): %s, %d, %p\n",data,data->bookname,data->price,dat\
a->next);
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

    return 0;
}
```

- Step 1: item1.nextに、item2のアドレスを保存せよ。
  - 動作確認項目
    - print_list()を使い、item1.nextとitem2のアドレスが同一であることを確認しよう。
- Step 2: item2.nextに、item3のアドレスを保存せよ。
- Step1〜2の実行イメージ

```
oct:tnal% ./a.out
## step 0
sizeof(struct list) = 24
list(address=0x7ffee16612e0): book1, 1000, 0x0
list(address=0x7ffee16612c8): book2, 2000, 0x0
list(address=0x7ffee16612b0): book3, 3000, 0x0
## step 1
list(address=0x7ffee16612e0): book1, 1000, 0x7ffee16612c8
## step 2
list(address=0x7ffee16612c8): book2, 2000, 0x7ffee16612b0
```

- Step 3: 以下の関数を追加し、main関数でitem1を渡して実行してみよう。
  - ここでは動作確認し、コードを理解してみるだけで良い。

```C
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
```

- 回答例: [list.c](list.c)

<hr>

## <a name="pointer3">演習6: Pythonのリストのように、データを後から追加してみよう</a>
- Step 0: [list.c](list.c) をベースとし、編集していこう。
- Step 4: 構造体listを指すためのポインタ変数を用意せよ。ポインタ変数名は ``pointer_list`` とする。このポインタ変数が item1 のアドレスを参照するように設定し、print_list_all関数でポインタ変数を出力せよ。
  - 動作確認項目
    - item1からの結果と同一であることを確認しよう。
- Step 5: Pythonにおける「リストの最後に要素を追加する ``list.append(data)``」に相当する関数を実装せよ。
  - 追加する要素はmain関数上部のコードを参考に、新しい変数を設定して用意するものとする。
  - 関数プロトタイプは ``
void append_list(struct list *pointer_list, struct list *new_data);`` とする。
    - この関数は、``pointer_list`` を確認し、nextがNULLであるならばそこに新しいデータを追加する。NULLでないならばその先を参照し、同様にnextを確認して処理するものとする。
    - 今回は、すでに3つ分の要素があるので、以下のようになっているはず。チェック3回目でNULLが見つかるので、nextを更新しよう。
      - チェック1回目: pointer_list->bookname = "book1", next=次の要素。
      - チェック2回目: pointer_list->bookname = "book2", next=次の要素。
      - チェック3回目: pointer_list->bookname = "book3", next=NULL

- Step4〜5の実行イメージ

```
## step 4
list(address=0x7ffeeb6cc2e0): book1, 1000, 0x7ffeeb6cc2c8
list(address=0x7ffeeb6cc2c8): book2, 2000, 0x7ffeeb6cc2b0
list(address=0x7ffeeb6cc2b0): book3, 3000, 0x0
## step 5
list(address=0x7ffeeb6cc2e0): book1, 1000, 0x7ffeeb6cc2c8
list(address=0x7ffeeb6cc2c8): book2, 2000, 0x7ffeeb6cc2b0
list(address=0x7ffeeb6cc2b0): book3, 3000, 0x7ffeeb6cc298
list(address=0x7ffeeb6cc298): book4, 500, 0x0
```

- 回答例: [list_append.c](list_append.c)
