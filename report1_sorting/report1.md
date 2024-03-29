# 課題レポート7（C言語レポート1）: 点数が高い順に並べよう

- 前期からの変更点
  - 課題説明は「課題概要」のみで十分です。
  - 今回のレポートについては「最大4ページ」に収めるようにして下さい。

<ul>
<lh>＜目次＞</lh>
<li><a href="#abst">課題概要</a>
<li><a href="#details">詳細仕様</a>
<li><a href="#output_example">実行例</a>
<li><a href="#hints">ヒント</a>
<li><a href="#goal">課題の達成目標</a>
<li><a href="#report">取り組み方</a>
<li><a href="#submit">提出方法</a>
</ul>

<hr>

## <a name="abst">課題概要</a>
複数人の点数が配列として用意されている。これを点数が高い順に並べよう。

<hr>

## <a name="details">詳細仕様</a>
- 配列は次のように、main関数上部で用意されるものとする。
```C
int main(){
    const int SIZE = 5; //定数として配列のサイズを宣言                          
    int scores[SIZE] = {0, 60, 70, 100, 90};
    //処理コード
    return 0;
}
```
- 上記はあくまでも一例であり、SIZEやscoresを書き換えても（他の点数集合）でも並び替えられるようにすること。
  - 配列の要素数（点数の個数）は2個以上の整数とする。
  - 点数は、0〜100の間の整数とする。
- 並び替えを実装する際、scores[]を直接操作する（要素を入れ替える）形での実装でも良いし、新しい配列を用意しそこに並び替えた点数を保存する形でも良い。少なくとも、「並び替えた後の配列」は用意すること。
  - 例えば、「scores[]から1番目に高い点数を探してprintf出力。2番めに高い点数を探してprintf出力。...」という処理は、ターミナル出力上は並び替えてるように見えるが、実際には並び替えた配列が存在しないため、NGとする。
- 上記以外の仕様は自由に決めて構わないが、**自作の関数1つ以上を含むこと**。

<hr>

## <a name="output_example">実行例</a>
- 実行例1（int scores[5] = {0, 60, 70, 100, 90};とした場合の結果）
```
oct:tnal% gcc -Wall sorting.c
oct:tnal% ./a.out
scores = 0 60 70 100 90
results = 100 90 70 60 0
```

- 実行例2（int scores[6] = {100, 60, 70, 100, 90, 80};）
```
oct:tnal% gcc -Wall sorting.c
oct:tnal% ./a.out
scores = 100 60 70 100 90 80
results = 100 100 90 80 70 60
```

<hr>

## <a name="hints">ヒント</a>
- C言語では、配列を宣言する際に*変数*でサイズ指定することはできない。定数で指定する必要がある。定数を利用するためには定数宣言を用いよ。
  - コード例: [sample_const.c](sample_const.c)
- 関数で配列を受け取るためには次のように記述する。
  - 関数呼び出し時: 変数名をそのまま記述。
  - 関数定義時: 引数が配列であることを明記。
  - コード例: [sample_func_array.c](sample_func_array.c)


<hr>

## <a name="goal">課題の達成目標</a>
- [達成目標](https://github.com/naltoma/c_intro/blob/master/C_intro.md#goal)
  - 本課題では、構造体は不要です。

<hr>

## <a name="report">取り組み方</a>
- ペアや友人らと話し合って取り組んで構わないが、コード解説を加えるなど「自分自身の報告書」となるように取り組むこと。試して分かったこと、自身で解決できなかった部分等についてどう取り組んだか、といった過程がわかるように示すこと。（考えを図表や文章を駆使して表現して報告する練習です）
- レポート作成は好きなツール（ソフトウェア）を使って構わない。ただし下記を含めること。
  - タイトル
    - 今回は「**プログラミング2、課題レポート7（C言語レポート1）: 「点数が高い順に並べよう」**」。
  - 提出日: yyyy-mm-dd
  - 報告者: 学籍番号、氏名
    - 複数人で相談しながらやった場合、相談者らを「**協力者: 学籍番号、氏名**」として示そう。
  - 課題説明（概要のみでOK）
  - **結果と考察**
    - 実行例1と実行例2を実現していることを示す実行結果。
    - 自作した関数のコードおよびその解説。
      - レポート内で言及するコードは、実行例1もしくは実行例2どちらか片方のみで良い。
    - 課題への取り組みを通し、課題の意義、課題から分かったこと、今後の展望などを述べる。失敗やつまづきがあれば、それらについての失敗分析を含めること。
  - その他
    - 参考リンク: [実験レポートの書き方](http://www.report.gusoku.net/jikken/jikkenreport.html)
    - 通常は感想等をレポートには含めませんが、練習なので課題に取り組みながら何か感じたこと、悩んでいること等、書きたいことがあれば自由に書いてください。（なければ省略OK）

<hr>

## <a name="submit">提出方法</a>
- 提出物は「レポート」、「作成したソースファイル」の2点である。
  - GitHub を使用している場合には、レポート内にGit URLを掲載することでソースファイル提出の代替と見做す。
- レポートは電子ファイルで提出するものとする。
- 提出先:
  - Googleドキュメントのreport7。
- 締切: 調整中。
