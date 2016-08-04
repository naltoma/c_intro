# 演習

- 利用する機能
  - 基本的な型(int, float, char)、構造体、配列、関数、条件分岐、ループ
  - ポインタは使わない。
- 全体を通して
  - コンパイル時には「-Wall」オプションを付けて、warningsが出なくなるように修正することを心がけよう。（warningsはエラーではないが、何らかの理由のある警告。）

<ul>
<lh>＜目次＞</lh>
<li><a href="#fizzbuzz">演習1: FizzBuzz</a>
  <ul>
  <li><a href="#fizzbuzz_a.out">演習1の実行例</a>
  <li><a href="#fizzbuzz_code">演習1の解答例（先に見てもいいですが、書けるようになろう）</a>
  </ul>
<li><a href="#reverse">演習2: 文字列の反転</a>
  <ul>
  <li><a href="#reverse_a.out">演習2の実行例</a>
  <li><a href="#reverse_code">演習2の解答例（先に見てもいいですが、書けるようになろう）</a>
  </ul>
<li><a href="#struct">演習3: 成績の評価</a>
  <ul>
  <li><a href="#struct_a.out">演習3の実行例</a>
  <li><a href="#struct_a.out">演習3の実行例（先に見てもいいですが、書けるようになろう）</a>
</ul>

<hr>

## <a name="fizzbuzz">演習1: FizzBuzz</a>
1から順に数を出力していく。但し、以下の条件を満足するものとする。
- (1) 数が3で割り切れるならば数字の代わりにFizzと出力せよ。
- (2) 数が5で割り切れるならBuzzと出力せよ。
- (3) 数が3でも5でも割り切れるならばFizzBuzzと出力せよ。
上記を満足するように、1から順に最低15まで出力するプログラムを作成せよ。
- ヒント
  - ここではシンプルにprintf()出力することだけを考えよう。（数を文字や文字列への変換、関数の戻り値として返す、、、といった事を考えだすと、ここでは教えていないポインタの概念が必要になってきます）

### <a name="fizzbuzz_a.out">演習1の実行例</a>
```
oct:tnal% gcc fizzbuzz.c -Wall
oct:tnal% ./a.out
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
```

### <a name="fizzbuzz_code">演習1の解答例（先に見てもいいですが、書けるようになろう）</a>
- [fizzbuzz.c](./fizzbuzz.c)

<hr>

## <a name="reverse">演習2: 文字列の反転</a>
```
char data[5] = "hoge";
```
- 上記のように文字列が保存されてるとする。この文字列を反転した結果を保存し、出力せよ。（単に出力するだけではなく、文字列として保存すること）

### <a name="reverse_a.out">演習2の実行例</a>
```
oct:tnal% gcc reverse.c -Wall
oct:tnal% ./a.out
data = hoge
reversed = egoh
```

### <a name="reverse_code">演習2の解答例（先に見てもいいですが、書けるようになろう）</a>
- [reverse.c](./reverse.c)

<hr>

## <a name="struct">演習3: 成績の評価</a>
```
struct student_score students[3] = {{"e175701", 100, 'A'}, {"e175702", 70, '\0'}, {"e175703", 50, '\0'}};
```

- 上記のように構造体が初期化されているものとする。
  - 構造体student_scoreは「学生のアカウント名(文字列)、点数(int)、評価(文字)」からなる構造体である。
  - アカウント名は最大7文字(e.g., "e175701")とする。
  - 各々変数名は account, score, eval とする。
  - ``'\0'`` とは「何もない状態（未評価）」を意味する。文字列ではない点に注意。
  - 学生scores[0]は評価がAと判定済みであるが、二人目以降はまだ判定がなされていないためNULLが代入されている。
- 構造体student_scoreを宣言し、上記のように初期化した上で「評価が'\0'になっている学生についてA〜F判定するプログラムを作成せよ。

### <a name="struct_a.out">演習3の実行例</a>
```
oct:tnal% gcc struct.c -Wall
oct:tnal% ./a.out
データ初期値
account=e175701, score=100, eval=A
account=e175702, score=70, eval=
account=e175703, score=50, eval=
評価結果
account=e175701, score=100, eval=A
account=e175702, score=70, eval=C
account=e175703, score=50, eval=F
```

### <a name="struct_a.out">演習3の実行例（先に見てもいいですが、書けるようになろう）</a>
- [struct.c](./struct.c)
