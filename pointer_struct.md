# 構造体配列の利用: ポインタ、アドレス参照（逆参照）、->演算子

- ＜目次＞
  - <a name="#intro">用語説明と問題意識</a>
  - <a name="#code1">コード例1: ポインタとアドレス参照（外観）</a>
  - <a name="#code2">コード例2: 構造体配列を、関数に参照渡しで参照させる方法</a>

<hr>

## <a name="intro">用語説明と問題意識</a>
- 用語説明
  - アドレス: メモリ上の位置情報。「e.g., int型のリテラルを0x00番地に保存した」
  - ポインタ: アドレスを指す情報。「e.g., 0x00番地を参照したらint型のリテラルが保存されていた」
- 何故こんなことを考える必要があるのか？
  - 計算機（コンピュータ）の動作原理を理解して欲しい。詳細は「計算機アーキテクチャ」「オペレーティングシステム」「アルゴリズムとデータ構造」等の後続必修科目にて。
  - プログラミング言語によっては、アドレスやポインタを殆ど意識せずにプログラミング可能。一方で、このことを意識していないために混乱したり、リソース（計算機資源）を非効率的に使ってしまうことがある。
  - ここでは、ポインタとアドレス参照を意識しやすい（意識せざるを得ない）C言語を通して、演習してみよう。
    - 興味がある人は、[参考サイト](https://github.com/naltoma/c_intro/blob/master/C_intro.md#ref)を参考に学んでみよう。

<hr>

## <a name="code1">コード例1: ポインタとアドレス参照（外観）</a>
- step 0: 最低限のコードを用意。

```C
#include <stdio.h>

int main(){
  return 0;
}
```

- step 1: 本の名前(char[])と価格(int)を保存するための構造体bookを定義。
  - ``#define`` は、グローバルな定数と考えることもできる。（実際には大きく異なる。調べてみよう）

```C
#define BOOK_NAME_LENGTH 10

struct book{
    char name[BOOK_NAME_LENGTH];
    int price;
};
```

- step 2: main関数内でいくつかbookを用意し、book1の中身・サイズ・アドレスを確認してみる。
  - ``*book3``: 後で使うためのポインタ変数。
  - ``sizeof(book1)``: book1を保存するために確保したメモリサイズ。unsigned long型（print書式は``%lu``を指定）。
  - ``&book1``: book1を保存しているアドレス（pointer）。

```C
struct book book1 = {"book1", 1000};
struct book book2 = {"book2", 120};
struct book *book3; //ポインタ変数（アドレスを指す情報を保存するための変数）

//book1の中身、サイズ、アドレスを確認
printf("## step2\n");
printf("book1.name = %s, .price = %d\n",book1.name,book1.price);
printf("sizeof(book1) = %lu\n",sizeof(book1)); //%lu = unsigned long (int)
printf("%p\n",&book1); //%p = pointer
```

- step 3: step2を真似て、book2についても中身・サイズ・アドレスを確認するコードを書こう。
- step 4: book2のアドレスを、ポインタ変数 ``*book3`` に代入し、book3の中身を確認してみる。
  - book2のアドレスは、``&book2`` で参照できる。``&book2`` はアドレスのため、これを保持するためにはポインタ変数が必要。これが、step1で用意した ``struct book *book3``。
  - ``book3 = &book2``: アドレスをポインタ変数に保存。この時点ではポインタ変数冒頭に``*``が付いていない。
    - book2のアドレスを参照しているため、book3のアドレスも同じであることを確認しよう。
  - ``book3->name``: ポインタ変数に保存されているのが構造体の場合には、``.``演算子の代わりに、``->``演算子を使って構造体の中身を参照する。

```C
//book2のアドレスを、*book3に代入し、book3の中身を確認
printf("## step4\n");
book3 = &book2;
printf("book3->name = %s, .price = %d\n",book3->name,book3->price);
printf("sizeof(book3) = %lu\n",sizeof(book3));
printf("%p\n",&book3);
```

- step 5: book3->priceを変更し、book2.priceを確認
  - 同じアドレスのため、book3を変更したら、book2も変更されていることを確認しよう。

```C
printf("## step5\n");
book3->price = 3;
printf("book2.price = %d\n",book2.price);
```

<hr>

## <a name="code2">コード例2: 構造体配列を、関数に参照渡しで参照させる方法</a>
- case 1: 配列全体を渡す場合。
  - 関数呼び出し時に「変数名」をそのまま指定。関数側では「*変数名」のように、変数名冒頭に ``*`` を付ける。

- case 2: 配列の指定要素（インデックス指定）を渡す場合。
  - 関数呼び出し時に「&変数名[i]」のように、インデックスiで指定する際に冒頭に ``&`` をつける。関数側では「*変数名」のように、変数名冒頭に ``*`` を付ける。
- コード例: [swap.c](swap.c)
