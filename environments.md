# 環境構築
- 2024年1月6日版。

## macOS
### 動作確認方法
ターミナルから ``gcc --version`` と実行。以下のように Apple clang のバージョンが出力されるならOK。

```shell
(base) oct:tnal% gcc --version
Apple clang version 16.0.0 (clang-1600.0.26.6)
Target: arm64-apple-darwin23.6.0
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
