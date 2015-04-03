
■コンパイルの方法

(1) すべてのソースコード（サフィックスが .cc/.cpp）あるいはオブジェクト（サフィックスが .o）ファイルを直接コンパイラの引数にして、実行ファイルを a.out として出力（リンク）する。
c++ Card.cc CardSet.cc Dealer.cc Player.cc LittleThinkPlayer.cc ThinkTA1.o main.cc 

(2) c++ Card.cc CardSet.cc Dealer.cc Player.cc LittleThinkPlayer.cc ThinkTA1.o main.cc -o daifugou
ソースコードやオブジェクトファイルの指定は (1) と同じだが、実行ファイルを daifugou の名前でリンクする。

(3) make daifugou [RETURN]
Makefile にある定義をつかって、更新などの依存関係も make コマンドにまかせてソースコードごとにオブジェクトファイルをコンパイルし、実行ファイルを daifugou としてリンクする。変更のあったファイルとそのオブジェクトに依存するファイルのみコンパイルを行う。
注意：自分でソースコードファイルやヘッダファイルを追加したり、名称変更した場合は、Makefile ファイルの OBJS = 以降のファイル名＋.o のリスト、HEADERS = 以降の .h ファイルのリストを編集する必要がある。

