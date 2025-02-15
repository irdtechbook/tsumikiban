# ペットフードディスペンサーをIoT化　～製作レシピ例～

IoTLTでの懇親会で「外出や出張・旅行で家を不在にする際のペットのエサやりどうしてる？！」という話題になったことを思い出した。うちにも野良ネコ(ゆき)が一匹いるので、旅行の際はいつも悩んでいる。

![ゆき](images/Recipe-IoTCatFoodDispenser/cat.png)

選択肢としては、

* ペットシッター
* ペットホテル
* 留守番

がある。

普段の外出や短期間(1泊2日程度)の出張・旅行であれば留守番となり、中位・低位機種のデジタルタイマーのペットフィーダー[^feeder1] やアナログタイマーのトレイタイプ[^feeder2]を併用している。上位機種はカメラ付きスマホ遠隔操作自動給餌器[^feeder3]もある。

[^feeder1]: ペット用自動給餌器ルスモ　http://www.lusmo.com/
[^feeder2]: PetSafe おるすばんフィーダー2食分 https://store.intl.petsafe.net/ja-jp/2-meal-pet-feeder
[^feeder3]: カメラ付き自動給餌器”ビストロわんにゃん”スマートペットフィーダー https://bestanswer.shop-pro.jp/?pid=133686464


ペットおよび飼い主にとって最適な方法を考えてみる。

* エサやりは確実に行いたい
    * 停電時でも電池式のデジタルタイマーまたはアナログタイマーでエサやり
    * 足りなさそうなときは遠隔からエサやり
* ネコの様子を見たい
    * カメラの映像を遠隔(スマホまたはタブレット)から確認
* 一緒に遊んであげたい
    * ネコじゃらしで遊ぶ
* はんだを使わずに電子工作をする
* ノンコーディングで実現する

## 構成
外出先からスマホまたはタブレットのブラウザ操作で自宅のネコの様子を確認したり、ネコじゃらしで遊んだり、エサやりを行えるようにする。自宅のラズパイにカメラ、ペットフィーダー(LUSMO)を接続し、ラズパイへインストールされたソフトウェア(Node-RED)をインターネットから制御することで実現する。NAT越え問題[^nat]を解決するためにngrokのサービスを利用する。

[^nat]: 家庭内ネットワーク(LAN)とインターネット(WAN)の間に境界(NAT)が存在し、セキュリティを確保する目的でWAN→LANのアクセスは基本的に制限されている。

![技術要素と構成](images/Recipe-IoTCatFoodDispenser/components.png)

### 材料
* LUSMO x 1
* ラズパイ(Raspberry Pi 3 Model B または B+) x 1
    * microSDHCカード(16GB Class10) x 1
    * ラズパイ用ACアダプター(5V / 3.0A) x 1
    * カメラモジュール(Raspberry Pi Camera v1.3 または v2.1) x 1
* サーボモーター(SG-90) x 2
    * SG-90サーボ用2軸カメラマウント x 1
    * ジャンパーケーブル(オス - メス) x 6
    * Grove リレー x 1
    * Grove ジャンパー(メス)ケーブル x 1
    * ワニ口クリップコード x 2
* ドライバーセット

### 配線
ラズパイは有線LANまたは無線Wi-Fiでネットワークへ接続する。カメラモジュールはラズパイのCAMERA端子へ接続し、サーボモーターとGroveリレーはラズパイのGPIO端子へ接続する。

![結線ブロック図](images/Recipe-IoTCatFoodDispenser/connection.png)

![GPIO端子の結線](images/Recipe-IoTCatFoodDispenser/GPIO.png)

### LUSMO内の配線
ペットフードを入れるトレーを外し、(+)ドライバーでネジ(5箇所)を緩めてカバーを外す。

![LUSMOの分解1](images/Recipe-IoTCatFoodDispenser/LISMO1.png)

![LUSMOの分解2](images/Recipe-IoTCatFoodDispenser/LISMO2.png)

モーターの(-)電極と乾電池の(-)電極へワニ口クリップコードを接続し、コードの反対側をGroveリレーのスクリューターミナルへ接続する。スクリューターミナルはマイナスドライバーで開け締めを行う。

![モーターの接続](images/Recipe-IoTCatFoodDispenser/motor1.png)

![リレーへの接続](images/Recipe-IoTCatFoodDispenser/relay1.png)


### 使用するソフトウェア
* OS (Raspbian Stretch with desktop 2018-11-13)
* Node-RED v0.18.6-alpha.8 (enebular)
* Node-REDの追加ノード (メニュー → パレットの管理から行う)
    * node-red-contrib-camerapi
    * node-red-contrib-line-messaging-api
    * node-red-contrib-multipart-stream-decoder
    * node-red-contrib-ngrok
    * node-red-dashboard
    * node-red-node-base64
    * node-red-node-pi-gpiod
* uv4l-raspicam

### インストール手順

```sh
$ curl http://www.linux-projects.org/listing/uv4l_repo/lpkey.asc | sudo apt-key add -
$ echo 'deb http://www.linux-projects.org/listing/uv4l_repo/raspbian/stretch stretch main' | sudo tee -a /etc/apt/sources.list
$ sudo apt-get update
$ sudo apt-get install uv4l uv4l-raspicam uv4l-raspicam-extras
```

### 利用するサービス
* AWS IoT Core[^aws] 

→AWS IoT用IAMユーザーを作成し、アクセスキーIDとシークレットアクセスキーを取得する。

* enebular[^enebular]

→アカウントを作成し、Projectとflowを作成する。ラズパイへenebular AWS IoT agentをインストール[^AWSonRP]し、enebular editorからflowを編集/デプロイできるようにする。

* ngrok[^ngrok]

→アカウントを作成し、authトークンを取得する。

* LINE Notify[^linebot] 

→アカウントを作成し、アクセストークンを発行する。


[^aws]: AWS IoT Core https://aws.amazon.com/jp/iot-core/
[^enebular]: enebular  https://enebular.com
[^AWSonRP]: 参考手順 https://qiita.com/TakedaHiromasa/items/b6828e4ac434bf99325d
[^ngrok]: ngrok https://dashboard.ngrok.com/user/signup
[^linebot]: line Notify https://notify-bot.line.me/ja/

## Node-REDフローとダッシュボード
フローはenebularに公開しています[^noderedflow]ので、フロー作成を省略する場合はImportで取り込んでください。

![Node-REDフロー全体](images/Recipe-IoTCatFoodDispenser/noderedall.png)


### リレースイッチフローの設定
ダッシュボードのスイッチ「BUTTON」を押すと、msg.payloadに1が設定されてpi-gpiod outノード「リレースイッチ」がONになる。また、同時にdelayノードで1秒遅延させた後、changeノードでmsg.payloadに0が設定されてpi-gpiod outノード「リレースイッチ」がOFFになる。結果としてLUSMOのモーターが1秒間動作する。
 
![リレーのフロー](images/Recipe-IoTCatFoodDispenser/relayflow.png)


### カメラ遠隔操作フローの設定
ダッシュボードの「PAN / TILT」スライダーを左右に操作すると、msg.payloadに0〜100が設定されてchangeノードに入力される。changeノードで入力値を反転(100〜0)させた後、pi-gpiod outノード「PAN」または「TILT」に入力される。

サーボモーターはパルス幅(Duty Cycle)に応じて回転軸の制御を行うため、pi-gpiod outノードのTypeは「Servo output」を設定し、Limitsは500〜2400μs(0.5〜2.4ms)[^SG-90spec]に設定する。changeノードで入力値を反転(100〜0)させるのは、スライダーの動きとカメラマウントの動きを合わせるためです。

![カメラとGPIOの接続](images/Recipe-IoTCatFoodDispenser/remotecam.png)

![サーボ設定](images/Recipe-IoTCatFoodDispenser/servosetting.png)


[^noderedflow]: neko-no-moribito Flow by kitazaki published: Mar 5th 2019, 1:30 PM https://enebular.com/discover/flow/b6ffe2c9-ce5b-4896-b803-611b3ac890fd
[^SG-90spec]:  SG-90サーボの仕様　http://akizukidenshi.com/download/ds/towerpro/SG90_a.pdf


### 静止画の設定
ダッシュボードの「TAKE A PHOTO」を押すと、カメラモジュールで撮った写真が表示される。ui_templateノードのHTMLコードにHTMLを入力する。

![静止画の設定](images/Recipe-IoTCatFoodDispenser/photosetting.png)

```html
<script>
var value = "1";
// or overwrite value in your callback function ...
this.scope.action = function() { return value; }

function updateF() {
  var source = '/photo1.JPEG',
  timestamp = (new Date()).getTime(),
  newUrl = source + '?_=' + timestamp;
  document.getElementById("photo").src = newUrl;
}
</script>

<md-button ng-click="send({payload:action()})" onclick="setTimeout(updateF, 2500);
" style="padding:20px; margin-bottom: 20px;" >
 <ui-icon icon="camera"></ui-icon>
 Take a photo<br>
</md-button>

<div style="margin-bottom:0px;">
 <img src="/photo1.JPEG" id="photo" width="100%" height="100%">
</div>
```

写真の保存先のディレクトリを作成し、Node-RED設定ファイル(ふたつ)にディレクトリの情報を追加する(enebularユーザーで実施する)。

#### ディレクトリの作成 

```sh
$ mkdir /home/enebular/Pictures
```

#### 設定ファイル(通常起動用)

/home/enebular/enebular-runtime-agent/node-red/.node-red-config/settings.js


```sh
const fs = require('fs')
const path = require('path')

module.exports = {
  userDir: __dirname,
  flowFile: 'flows.json',
  httpStatic: '/home/enebular/Pictures/',　　　　　　　　　　　　　(←追加)
  httpAdminRoot: false
};
```

#### 設定ファイル(enebular editor起動用)
/home/enebular/enebular-runtime-agent/node-red/.node-red-config/

```sh
enebular-editor-settings.js
const fs = require('fs')
const path = require('path')

module.exports = {
  userDir: __dirname,
  flowFile: 'flows.json',
  verbose: true,
  httpStatic: '/home/enebular/Pictures/',　　　　　　　　　　　　　(←追加)
  httpAdminRoot: '/',
  httpNodeRoot: '/',
  storageModule: require('../enebularStorageModule'),
  credentialSecret: false,
  editorTheme: {
	userMenu: false,
	page: {
  	title: '',
  	favicon: path.join(__dirname, 'img', 'favicon.ico'),
  	css: path.join(__dirname, 'css', 'index.css')
	},
	header: {
  	title: '',
  	image: path.join(__dirname, 'img', 'enebular_logo.svg')
	},
	deployButton: {
  	type: 'simple',
  	label: 'Save'
	},
	palette: {
  	editable: true
	}
  }
}
```

### 外部公開、URL通知
ngrokは無償プランではURLが毎回変わり、8時間で無効化されます。外出先からダッシュボードを確認するためにLINE Notifyを利用してURLを通知する。LINE NotifyノードのAccessTokenにアクセストークンを入力する。

![Line notifyの設定](images/Recipe-IoTCatFoodDispenser/linenotify.png)


### 動画の設定
ダッシュボードの「START」を押すとmulti-decoderノードがuv4l-raspicamと通信を行い動画(Motion JPEG)データを取得する。取得したデータをbase64ノードでエンコードし、ui_templateノードでHTMLへエンコードされたデータを埋め込むことでダッシュボードに動画が表示される。ダッシュボードの「STOP」を押すとchangeノードでmsg.stopにtrueが設定されて、multi-decoderノードの動作が停止する。
  
![動画の設定](images/Recipe-IoTCatFoodDispenser/moviesetting.png)


multipart-decoderノードのURLに
http://localhost:8090/stream/video.mjpeg
を入力する。
 
![multiPart-decoderの設定](images/Recipe-IoTCatFoodDispenser/decodersetting.png)



![ui_templateノードのHTMLコードにHTMLを入力する](images/Recipe-IoTCatFoodDispenser/uitemplate.png)

```html
<img width="16" height="16" src="data:image/jpg;base64,{{msg.payload}}" />
```

 
![changeノードでmsg.stopにtrueを設定する](images/Recipe-IoTCatFoodDispenser/stop.png) 

## まとめ

カメラマウントにネコじゃらしを付けてみました。サーボモーターを動かしてカメラマウントを上下左右に振るとネコが寄ってくるので、タイミングを合わせてカメラで写真を撮ったり、動画で遊んでいる様子を見ることができる。やり過ぎてネコに装置を破壊されないように、くれぐれもご注意を！

![ネコじゃらしをつけてみた](images/Recipe-IoTCatFoodDispenser/moving.png)
