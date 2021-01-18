# VSCode + gcc (clang) で開発する流れ
- 参考
  - [Using Clang in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)
- ＜目次＞
  - <a href="#new-project">プロジェクト作成方法</a>

<hr>

## <a name="new-project">プロジェクト作成方法</a>
- step 1: プロジェクトディレクトリを作成。
  - 例えば ``~/prog2/`` がすでに存在していて、そこに ``week14`` というプロジェクトを作るなら、``mkdir ~/prog2/week14`` で作成。以下はこの想定でのコマンド例。
- step 2: 作成したディレクトリに移動。
  - ``cd ~/prog2/week14``
- step 3: 空のソースファイルを作成。（後からも可能）
  - ``touch sample1.c``
- step 4: VSCodeでプロジェクトを開く。
  - ``code .``
- step 5: ファイル編集して保存する。
  - sample1.cを開き、例題1なり何かしらCのコードを記述して保存する。
  - 初めての場合だけ、C言語のためのExtensionをインストールするかどうかを尋ねられるので、インストールする。失敗する場合にはアプリ側でどうするかについて提案が出るので、提案通りに進める。
- step 6: ビルド用設定ファイル tasks.json の作成。
  - `` Terminal > Configure Default Build Task`` を選択し、そこから``gcc``を選択する。
  - 特に設定変更不要のハズだが、念の為コンパイラが正しく指定されていることを確認しよう。
    - 使いたいコンパイラは、ターミナルから``which gcc``で確認。``/usr/bin/gcc``が出力されるはず。
    - tasks.jsonの "command" に、上記と同じgccが指定されていることを確認できればOK。
- step 7: ビルド。
  - case 1: VSCodeでビルド。（コンパイルのみ）
    - vscodeでプログラムに戻り、``Terminal > Run Build Task...`` を実行。
      - ソースコードに問題がなければコンパイルが通り、実行可能ファイル（バイナリファイル）とデバッグ用ファイル群が生成される。
      - 実行可能ファイルは``sample1``、デバッグ用ファイル群は``sample1.dSYM``のように、ソースコードのファイル名に沿った名前で生成される。
  - case 2: ターミナルで手動コンパイル。
    - ``gcc -o hoge sample1.c``
    - ``-o`` は、コンパイル後に生成する実行ファイル名を指定するためのオプション。上記ではhogeと指定している。指定しなかった場合には ``a.out`` というファイル名になる。
- step 8: 実行。
  - 理由はよくわからないが現時点でvscodeから直接実行することはできない。代わりに、ターミナルから ``./hoge`` のようにパス付きでバイナリファイルを指定して実行する。
- step option: デバッグ実行。
  - Javaと同様の流れで可能。
