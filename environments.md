# 環境構築
- 2020年1月5日版。

## macOS
### 動作確認方法
ターミナルから ``gcc --version`` と実行。以下のように Apple clang のバージョンが出力されるならOK。

```shell
(base) oct:tnal% gcc --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 11.0.3 (clang-1103.0.32.62)
Target: x86_64-apple-darwin19.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```

インストールされていない（Command not foundのようにエラーが出て、バージョン番号が出力されない）ならば、下記いづれかの方法でインストールしよう。インストール後、動作確認すること。
- case 1: command line developer tools のインストール。
  - ``xcode-select --install`` と実行し、command line developer toolsをインストールしよう。
- case 2: brewでgccのインストール。
  - ``brew install gcc``

<hr>

## Windows
- case 1: WSL2でUbuntu等Linux系OSを動かすための仮想環境を構築し、そこにgccをインストール。
  - 参考
    - [Windows 10 用 Windows Subsystem for Linux のインストール ガイド](https://docs.microsoft.com/ja-jp/windows/wsl/install-win10)
- case 2: MinGWのようなgccコンパイラのみをインストール。
  - 参考
    - [WindowsにC言語開発環境（gccコンパイラ）を導入する](https://dianxnao.com/windowscgcc/)
