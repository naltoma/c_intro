# ポインタ変数入門: ポインタ、アドレス参照（逆参照）

- ＜目次＞
  - <a name="#intro">用語説明と問題意識</a>
  - <a name="#code1">コード例1: ポインタ変数とアドレスのサイズ確認</a>
  - <a name="#code2">コード例2: 配列のアドレスの確認</a>
  - <a name="#code3">コード例3: ポインタ変数を介した動作の確認</a>

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

## <a name="code1">コード例1: ポインタ変数とアドレスのサイズ確認</a>
- step 0: 以下のコードを実行し、char型とint型のリテラルサイズ、ポインタ変数のサイズ、アドレスのサイズを確認せよ。
```C
/* pointer1.c */
#include <stdio.h>

int main(void)
{
    char a, *pa;
    int b, *pb;

    printf("size of char  = %lu byte\n", sizeof(a));  //変数のサイズ
    printf("size of *char = %lu byte\n", sizeof(pa)); //ポインタ変数のサイズ
    printf("size of &char = %lu byte\n\n", sizeof(&a)); //アドレスのサイズ

    printf("size of int  = %lu byte\n", sizeof(b));
    printf("size of *int = %lu byte\n", sizeof(pb));
    printf("size of &int = %lu byte\n\n", sizeof(&b));

    return (0);
}
```
- step 1: double型についてもリテラルサイズ、ポインタ変数のサイズ、アドレスのサイズを確認するように編集し、実行結果を観察せよ。
  - どこが同じだろうか？
  - どこが異なるだろうか？

<hr>

## <a name="code2">コード例2: 配列のアドレスの確認</a>
- step 0: 以下のコードを実行し、動作を確認せよ。各リテラルが保存されているアドレスは、どのような傾向があるだろうか？
```C
/* pointer2.c */
#include <stdio.h>

int main(void)
{
    const int num = 5;
    int a[5] = {1, 2, 3, 4, 5};

    for(int i=0; i<num; i++){
        printf("&a[%d] = %p\n",i,&a[i]);
    }

    return (0);
}
```

<hr>

## <a name="code3">コード例3: ポインタ変数を介した動作の確認</a>
- step 0: 以下のコードを実行し、動作を確認せよ。ステップ毎にどの処理がどう影響するのか観察しよう。
```C
/* pointer3.c */
#include <stdio.h>

int main(void)
{
    int a, b = 0;
    int *p = NULL;

    printf("# step 1: 初期値\n");
    printf("a=%d, &a=%p\n",a,&a);
    printf("b=%d, &b=%p\n",b,&b);
    printf("p=%p\n",p);
    //printf("*p=%d\n",*p);  //=> segmentation fault

    a = 100;
    p = &a;
    printf("\n# step 2: 変数aのアドレスを、ポインタ変数pに代入。\n");
    printf("a=%d, &a=%p\n",a,&a);
    printf("b=%d, &b=%p\n",b,&b);
    printf("p=%p, *p=%d\n",p,*p);

    a = 50;
    printf("\n# step 3: 変数aを変更。\n");
    printf("a=%d, &a=%p\n",a,&a);
    printf("b=%d, &b=%p\n",b,&b);
    printf("p=%p, *p=%d\n",p,*p);

    b = *p;
    printf("\n# step 4: ポインタ変数pが参照するリテラルを、変数bに代入。\n");
    printf("a=%d, &a=%p\n",a,&a);
    printf("b=%d, &b=%p\n",b,&b);
    printf("p=%p, *p=%d\n",p,*p);

    b = 5;
    printf("\n# step 5: 変数bを変更。\n");
    printf("a=%d, &a=%p\n",a,&a);
    printf("b=%d, &b=%p\n",b,&b);
    printf("p=%p, *p=%d\n",p,*p);

    return (0);
}
```
