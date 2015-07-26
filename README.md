# DotWar
仮の名前。

----

## Architecture

![Architecture](/Users/tamakiryu/Dropbox/スクリーンショット/スクリーンショット 2015-07-21 16.03.21.png)
[mind node](/Users/tamakiryu/Library/Mobile Documents/W6L39UYL6Z~com~mindnode~MindNode/Documents/DotWar.mindnode)

### Entity
自分のキャラクターや敵の基底クラス。
何をしたいかを state machine に伝えて、それの返答を見て実際に自分を update する役割をもつ。

### StateMachine
Entity から来た state 変更の要求を、許可するか拒否するかを保証している。
state を管理すること以外は何もしない。
delegate を持っており、state が変化する**直前**と**直後**に、Entity に対して報告をする。

### Field
Entity 同士の関わりを管理している。
実際は GameScene に乗っかってるだけで、オブジェクト化はしてない（今後するかも）。
multiplayer モードの際、Entity が送信してきたデータをどうハンドリングするかもこいつが担ってる（**ここは要修正**）

## Synchronization through network
各自が**自分のことのみ**を気にするようにした。
送るタイミングは、**何かしらの state に変化があった時**。

- move
- attack 
- hp
- position


### position synchronization
キャラクターの移動に関しては、向きの情報を頼りに、クライアントで計算させてる。
**ただし** state が変化した際、実際の posision 情報を渡していて、それを使って補正してる。
そのため、state の変化時に若干のトビが存在する。

### attack synchronization
今回のシステムでは、以下の2点のみがわかれば、あとは気にしないでいいように作った。
1. 攻撃をするということ（関数呼び出し）
2. どの攻撃をするか（引数）

**現状**
1種類しか攻撃がないため、1 だけわかればクライアント側で攻撃することを伝えてやれば、 state の情報は正確に再生される。
そのため、ready (攻撃に入る state) のみを detect し、そのタイミングで各クライアントから、attack() を呼んでやってる

**今後**
攻撃の種類を増やすため、送信する情報に、攻撃の種類を示す文字列（coocs studio の animation 名）を追加したい。
文字列を送るのがきつそうであれば、enum かなんかでラップしてやればいいかなと思ってるが、その辺はパフォーマンスとラグとの相談


### TODO

### コントローラーがわかりにくい。
みんなただただスワイプするだけか、片手でやろうとしちゃう。
そもそも両手でプレイするゲームに慣れてない人がプレイできない感じがする。

### iPhone6に最適化する
現状、iPhone4に最適化されてるので、これをiPhone6に最適化するよう、修正する