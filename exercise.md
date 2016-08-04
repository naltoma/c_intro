# 演習

- 利用する機能
  - 基本的な型(int, float, char)、構造体、配列、関数、条件分岐、ループ
  - ポインタは使わない。
- 全体を通して
  - コンパイル時には「-Wall」オプションを付けて、warningsが出なくなるように修正することを心がけよう。（warningsはエラーではないが、何らかの理由のある警告。）

<hr>

## <a name="fizzbuzz">演習1: FizzBuzz</a>
1から順に数を出力していく。但し、以下の条件を満足するものとする。
- (1) 数が3で割り切れるならば数字の代わりにFizzと出力せよ。
- (2) 数が5で割り切れるならBuzzと出力せよ。
- (3) 数が3でも5でも割り切れるならばFizzBuzzと出力せよ。
上記を満足するように、1から順に最低15まで出力するプログラムを作成せよ。
- ヒント
  - ここではシンプルにprintf()出力することだけを考えよう。（数を文字や文字列への変換、関数の戻り値として返す、、、といった事を考えだすと、ここでは教えていないポインタの概念が必要になってきます）

### <a name="fizzbuzz_a.out">実行例</a>
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

### <a name="fizzbuzz_code">解答例（先に見てもいいですが、書けるようになろう）</a>
- [fizzbuzz.c](./fizzbuzz.c)

<hr>

## <a name="reverse">演習2: 文字列の反転</a>
```
char data[5] = "hoge";
```
- 上記のように文字列が保存されてるとする。この文字列を反転した結果を保存し、出力せよ。（単に出力するだけではなく、文字列として保存すること）

### <a name="reverse_a.out">実行例</a>
```
oct:tnal% gcc reverse.c -Wall
oct:tnal% ./a.out
data = hoge
reversed = egoh
```

### <a name="reverse_code">解答例（先に見てもいいですが、書けるようになろう）</a>
- [reverse.c](./reverse.c)
