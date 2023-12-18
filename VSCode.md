# VSCode + gcc (clang) で開発する流れ
- 参考
  - [Using Clang in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)
- ＜目次＞
  - <a href="#code-runner">自動実行するための拡張インストール</a>
  - <a href="#new-project">プロジェクト作成方法</a>

<hr>

## <a name="code-runner">自動実行するための拡張インストール</a>
- VSCodeを起動し、``⌘+シフト+x`` を入力して拡張機能メニューを表示する。歯車アイコンから拡張機能を選んでも良い。以下の機能拡張をインストールする。
  - 検索窓に ``c`` と入力し、「C/C++」をインストールする。
  - 検索窓に ``c`` と入力し、「C/C++ Extension Pack」をインストールする。
  - 検索窓に ``c`` と入力し、「C/C++ Themes」をインストールする。
  - 検索窓に ``c`` と入力し、「CMake」をインストールする。
  - 検索窓に ``c`` と入力し、「CMakeTools」をインストールする。
  - 検索窓に ``code`` と入力し、「C/C++ Runner」をインストールする。

参考: [【M1以降の Mac, Windows対応】Visual Studio CodeでC/C++を実行する環境を構築する方法](https://www.edp-ken.com/post-8/#m2)

<hr>

## <a name="new-project">プロジェクト作成方法</a>
- step 1: プロジェクトディレクトリを作成。
  - 例えば ``~/prog2/`` がすでに存在していて、そこに ``c-test`` というプロジェクトを作るなら、``mkdir ~/prog2/c-test`` で作成。
- step 2: 作成したディレクトリをVSCodeで開く。
- step 3: 空のソースファイル（新規ファイル）を作成し、``sample1.c``という名前で保存。
- step 4: ファイル編集して保存する。
  - sample1.cを開き、以下のコードを記述して保存する。
```C
//コード例
#include <stdio.h>

int main(){
    int a = 1;
    printf("hello");
    return 0;
}
```
- step 5: ビルド＆実行。
  - 手動でやる場合：
    - ターミナルで手動コンパイル。
      - ``gcc -o hoge sample1.c``
      - ``-o`` は、コンパイル後に生成する実行ファイル名を指定するためのオプション。上記ではhogeと指定している。指定しなかった場合には ``a.out`` というファイル名になる。
    - ターミナル上で実行ファイルを指定して実行。hogeと指定したなら下記のように実行する。
      - ``./hoge``
  - 自動でやる場合：
    - 実行。
      - ウィンドウ下部の ▷ をクリック。実行結果が出力されない（ターミナル上にhelloと出力されない）なら、Extention内のCode Runnerの設定を確認しよう。
- step option: デバッグ実行。
  - Javaと同様の流れで可能。
