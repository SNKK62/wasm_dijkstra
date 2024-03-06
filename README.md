# wasm_dijkstra
ダイクストラ法を用いて入力された東急沿線２駅間の最短経路を表示するソースコードです．
wasmを用いてC言語で実装したdijkstraのアルゴリズムをJavascriptから呼び出しています．

## 事前準備
C言語のソースをwasmに変換するためにemscriptenをinstallします．<br>
[こちら](https://emscripten.org/docs/getting_started/downloads.html)からインストールできます．

次に, http-serverをインストールします．
```
$ npm install -g http-server
```

## ビルド
```
$ make build
```

## ローカルで実行
```
$ http-server
```
[http://localhost:8080](http://localhost:8080)でアクセスできるはずです．
