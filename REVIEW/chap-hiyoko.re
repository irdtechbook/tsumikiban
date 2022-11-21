= とある初心者の動的Lチカ（Blink）


hiyoko Prod. せかいい(@Jewel_Flash)

== はじめに


とある日の深夜、とあるDiscordサーバにて同人誌に一節書いてみないかと誘われ、初心者でもいいならということでヒョコヒョコとやって参りました、hiyokoと申します。初心者の視点から表題にもある私の積み基板を使いつつ、一風変わったLチカをしたときの体験を書いていきます。

== 作りたいもの


その日、傘が必要かどうかを、なんらかの形で告知してくれるデバイスを作りたいと思い、とりあえずブレッドボード上に試作しようと思いました。とりあえず今回は天気のとおりに光るところまでで、定時取得などは後日にしようと思います。

=== インサイト

 * 技術的に難しいものでないこと
 * こちらが何もしなくても近くにさえいればわかるもの
 * 関係ないときに、音や見た目がうるさくないこと
 * 傘が必要かわかること


=== 実は、完成済みの作例がある


実はすでにネット上には各種LCDやマトリックスLEDに天気や気温などを表示するような、完成形のものが存在します。実は今回私が作りたいものにとても近いものが6年ほど前に作られています@<fn>{cl2015}。また、スイッチサイエンス様のECサイトには、キットの販売ページが存在します@<fn>{switchscience2017}(次回入荷のステータスが未定となっていますが）。

//footnote[cl2015][『ESP-WROOM-02で玄関お出かけ天気カラー照明灯 - M.C.P.C. (Mamesibori Creation Plus Communication)』@<href>{https://cl.hatenablog.com/entry/esp-wroom-02-weather-light, https://cl.hatenablog.com/entry/esp-wroom-02-weather-light} (2021年11月19日閲覧)]

//footnote[switchscience2017][『i-Weather（アイウェザー）～玄関先で天気を知らせてくれるIoT～ - スイッチサイエンス』@<href>{https://www.switch-science.com/catalog/3270/, https://www.switch-science.com/catalog/3270/} （2021年11月19日閲覧）]


GAFAMのG社やA社から発売されている画面付きスマートスピーカーも、必要な機能としては条件を満たすかもしれません。


しかしそれらは、真似するには技術や設備が明らかに足りなかったり、私の用途にはオーバースペックであったりするものでした。なので、動作の流れなどをパク……リスペクトしつつ進めていきました。

=== 計画


以上を踏まえ、実際に試みる仕様を決めました。


まず、天気予報の取得には気象庁のAPIっぽいもの@<fn>{toyoda2021}またはそれをLivedoor Weather Hacksと互換性のあるようにラッピングしているToroshima様（tsukumi様）作のAPI@<fn>{tenkiyohoapi2020}をGoogleAppScript（以下、GAS）からfetchし、必要な情報のみにします。どこまでGAS側で処理し、どこからマイコン側で処理するかは、作りながら検討することとしました。マイコン側のデータ取得はGASのプログラム側にdoGet()を用意しておくつもりです。

//footnote[toyoda2021][TOYODA Eizi（2021）『TOYODA Eizi on Twitter: "一番伸びてるのはこれかしら。仕様の継続性や運用状況のお知らせを気象庁はお約束していないという意味で、APIではないと申し上げざるをえないのですが、一方で政府標準利用規約に準拠してご利用いただけます。" / Twitter』@<href>{https://twitter.com/e_toyoda/status/1364504338572410885, https://twitter.com/e_toyoda/status/1364504338572410885} （2021年11月19日閲覧）]

//footnote[tenkiyohoapi2020][天気予報 API（livedoor 天気互換） (2020)『天気予報 API（livedoor 天気互換）』@<href>{https://weather.tsukumijima.net/, https://weather.tsukumijima.net/} （2021年11月19日閲覧）]


使う部材についてはESP-WROOM-02と単色LED2〜3本を中心に作ることにし、LEDの光り方で表示することにしました。3本足のRGB LEDなども考えましたが、必要な時間帯以外はそもそも光っていなくてよく、IOも余裕があることからわざわざプログラムを煩雑にせずともよかろうと考え、LEDの数を増やして対応しました。また、消費電力の観点から常時点灯機能も作りません。LED部分に単色でいいので、カラーのものを導入すればCL様の作品@<fn>{cl2015}のように既成品の照明器具の中にも組み込めますし、電子ペーパーを導入すれば電源供給なしで提示し続けることもできるでしょう。


インターネットアクセスのためのSSIDなどの情報はハードコーディングせず、何らかの形であとから設定する形にしました。

== 作業開始


まずはESP-WROOM-02をブレイクアウトボードにはんだ付けします。このとき、IO16のグランドを剥がしてしまいました。まさかの2極目でこの失敗、先が思いやられます。面倒くさがらずにペーストハンダやハンダ吸い取り線を買いに行けばよかったなと後悔しましたが、特別なピンではないと思っていたため、@<fn>{io16}続行しました。最後に修復を試みましたが、被害が拡大しそうだったため諦めそのままにし、他のピンのハンダ付けを完了しました。

//footnote[io16][実際にはdeep sleep時にマイコンがマイコンをリセットするためのとても大切なピン。]


次に、ブレッドボードに装着します。しかし、ここでも問題が発生します。手持ちのブレッドボードではその全幅を使ってしまうのです。今までは立体的なタイプしか買わずに横着していたため、ブレッドボード用の平たいタイプのジャンパーワイヤは在庫がありません。ブレッドボード同士のみで合体させようにも、なぜか歪んでしまいます。最終的にはちょうどいい大きさの茶色い板@<fn>{universalboard}にふたつ固定することにしました。

//footnote[universalboard][ユニバーサル基板とも言う。新品。]


その後は平和に回路を作成していき、ついにコンピュータとシリアル変換越しに接続でき、ESP恒例の文字化けしたBootメッセージもシリアルモニタから確認できました。ようやく動作確認にこぎつけました。


フラッシュモードでの起動を確認できたため、試しに@<code>{AT}と送ってみました。

=== ATコマンドが通らない


今までも問題しか起きていませんが、更に問題が発生します。いいえ、些細なことを私の技量不足が問題にします。


送信したATがどこかに消えるのです。しかも、よく見たらreadyの表示も出ていません。考えられる原因としては、よく聞く電流不足かと思いました。そのときはただのATコマンドぐらいなら無線も使わないだろうしFTDIのシリアル変換からの電源でも問題ないだろうと考え、そこから電源をとっていたのです。


ダイソーの最安マンガン電池２本に切り替えたところ、うまくいきました。ちゃんとReadyが表示されたのです。また、ATと打ったらモニタ側にもATと表示されました。これは快挙だったはずでした、その後にOKでなくErrorが送られてくるということさえなければ。


電源電圧を測ったところ2.9Vまで落ちていたり、謎にリセットがかかったりしていたことが原因と推測しました。そこで、アルカリ２本の直列をふたつ並列にした４本体制にもしましたが、電源電圧こそ3.1v以上に回復したもののあまり状況は変わらず…。その他にCH340系など別のシリアル変換なども用いてみましたが、結局解決しませんでした。インターネットで検索してみてもそこで詰まったという投稿は見られなかったため、おそらく書くまでもなく対処してしまうか、普通は発生しないということなのかなと思いました。なお、AT以外のATコマンド、AT+GMRなども試してみましたが、ことごとく無慈悲なErrorが帰ってくるのみでした。


//image[IMG_3535_no-exif][その時のマイコンの様子]

=== 動作確認リベンジ


次の日、特に何か考えがあったわけではなくただ、前の日と同じようにつないでみたところ、なぜか動いたのです。これは大変不思議でした。しかし、このマイコン自体少々動作に不思議な点のあるものなので、気にしないことにしました。


確認したコマンドはすべてATコマンドで、最終的にWi-Fiネットワークへ参加したり、SoftAPを立ち上げて普通のデバイス(Apple iPod touch)をそこへ参加させることまでできました@<fn>{atコマンドの動作確認}。

//footnote[atコマンドの動作確認][@<code>{AT}の他に、@<code>{AT+GMR}、@<code>{AT+CIPSTAMAC}、@<code>{AT+CWMODE}、@<code>{AT+CWLAP}、@<code>{AT+CWJAP}、@<code>{AT+CWQAP}を確認しました。]


この後はArduinoのスケッチを書き込んでいくのですが、私はここで初期ファームのバックアップを忘れてしまいました。他に予備があったりネット上にあったりするので、どうしても困ることはないと思いますが、個人的にはこういう系はとっておく派だったため、少しショックでした。

=== GoogleAppsScript


気を取り直して、今度はGAS上でうごかすプログラムを作ります。また、天気予報の取得は気象庁のサーバから直接取得することにしました、傘が必要かどうかを機械的に判断するプログラムを基本的には自力で作ることにしたので、Livedoor互換である必要がないためです。しかし、読みにくいJSONなのでLivedoor互換の方を利用するのも賢い選択のひとつだと思います。セルフホストもできるようです@<fn>{tsukujima2020}。

//footnote[tsukujima2020][『天気予報 API（livedoor 天気互換） GitHub - tsukumijima/weather-api』　　　　　 @<href>{https://github.com/tsukumijima/weather-api, https://github.com/tsukumijima/weather-api} （2021年11月22日閲覧）]


今回はGAS上で処理できる部分はなるべくGASで処理をし、気象庁からデータを取得する部分とマイコンからの問い合わせに答える部分は、別のfuntionとすることにしました。ミスをしたときにより直しやすいのはGASの方であること、午前中に出かけるときに傘が必要かを判断するのみであり、内部的な天気の取得は１日に一回、朝5時の予報で十分であると判断しました。また、テストがてらマイコン側は何回も試行したい、一緒にする意味がない、ひとつのことをうまくやるの精神が好きなどの理由もあります。

=== Arduino/ESP-WROOM-02


はじめにWi-Fiの設定のためスケッチを拝借してきました。WiFi Managerというライブラリもあるらしいのですが、それらを使うと処理が完全に追えなくなるため、スケッチ内で処理するものをそのままコピペして利用しました@<fn>{exabugs2016}。また、GASを使ってSpreadsheetのデータを取り出すという主旨の作例があり、今回は考え方は異なるもののやりたいことは同じなため、それも拝借してきました@<fn>{abk282021}。ここまではほぼコピペです。最終的には定時実行できるようにしたいですが、とりあえず今回は@<code>{delay}で300,000ミリ秒遅延させることで連続リクエストしないようにしています。

//footnote[exabugs2016][『ESP8266 (ESP-WROOM-02) でWi-Fi使用時のSSID/パスワードをブラウザで設定できるように - Qiita 』 @<href>{https://qiita.com/exabugs/items/2f67ae363a1387c8967c, https://qiita.com/exabugs/items/2f67ae363a1387c8967c} （2021年11月22日閲覧）]

//footnote[abk282021][『Google Spreadsheetを管理テーブルにした、ESP8266タイマースイッチ（AC） - Qiita』 @<href>{https://qiita.com/ABK28/items/60aef868b61a48e0e715, https://qiita.com/ABK28/items/60aef868b61a48e0e715} （2021年11月22日閲覧）]


ここからが唯一の自分でちゃんと書いたArduinoのスケッチ部分です。LEDのピン番号を（constの）変数としておいて、@<code>{pinMode}と@<code>{digitalWrite}でともに@<code>{OUTPUT}と@<code>{LOW}をセットする関数、GASから帰ってきた情報をもとにLEDを光らす関数をセットし、それぞれ@<code>{void setup()}と@<code>{void loop}の中に置きました@<fn>{ifを使ってないのがこだわり}。記念に下記に記しておきます。

//footnote[ifを使ってないのがこだわり][ifを使ってないのがこだわり。思ったよりも簡潔に書けて満足している。]

//listnum[chap-hiyoko-000][]{
void hage_setup(){
  pinMode(ledRain, OUTPUT);
  pinMode(ledSunny, OUTPUT);
  digitalWrite(ledRain, LOW);
  digitalWrite(ledSunny, LOW);
}
void hage(){
  umbrella = (body.indexOf("t")) + 1;
  digitalWrite(ledRain, umbrella);
  digitalWrite(ledSunny, !umbrella);
}
//}


ちなみに、判定方法がおかしいのはtrue/falseの前後に謎のゴミ@<fn>{gomi}がついてきてしまい、取得時の処理が理解できない私には取り除けなかったためです。初心者コピペの弊害です。

//footnote[gomi][何度か見たところ、「ゴミを含まない文字数（改行）本文（改行）０」っぽかったです。何でしょうかこれ。]

== 部品をセット〜動作


@<strong>{動いた！！}はんだ付けが必要な箇所も前章で終わっており、ブレッドボードに刺しただけでさすがに書くこともないので、完成した写真と回路図のようなものを部品中心に書き起こしてみたものを下に示しておきます。


//image[IMG_3540-no-exif][完成し、光っている様子]
//image[3d4412946d48e813-no-exif2][回路図]

== 今後の計画


今後、これを完成形に近づけるにあたって、いくつか実装しなければいけない機能があるためそれを考えようと思います。


まずひとつ目は現在時刻の把握です。これはそこまで正確な時間が要求されるわけではないため、可能であればGASからの返答に現在時刻を混ぜてしまいたいなと考えています。しかし、謎のゴミの規則性を見つけなければちょっと難しいのではないかと考えています。どのような形で送信するかなどはそのときに考えたいと思いますが、データの数が決まっているので、カンマ区切りで羅列でいいかなと思っています。


ふたつ目は動いていない間のスリープです。しかし、はんだ付けに失敗してブレイクアウトボードの16番のランドが剥がれていて、自分で復帰するdeep sleepが使えなさそうです。また、deep sleepの制限時間@<fn>{deep-sleep-time-limit}を考えてもすこし今回の用途には合っていなさそうだったため、RTCのアラーム機能などでなんとかRSTピンをGNDに落とせないか考え中です。可能ならいっそのこと動く間だけ給電してもいいかもしれないとも考えています。また、完成版は新しいブレイクアウトボードを用い、70分おきに起動してもいいかもしれません@<fn>{gasnara}。

//footnote[deep-sleep-time-limit][2^32-1 (ms)=4294967295 ms ≒71.5 min]

//footnote[gasnara][GASなら罪悪感もないですし。]

== 感想など


作例じゃないから、感想も主題なのだ！


今回チャレンジしたものは、作りはじめの時点では「原因不明の何かにより失敗」に終わると思っていました。実際、この原稿の最初の版ではATコマンドが通らなかったところで終わっています。しかし、原因不明の何かは原因不明に解決し、最終的に動作までこぎつけました。もうすこし取得間隔を伸ばせば実用も不可能ではないようなものができあがり、私自身も驚いています@<fn>{tuiito}。部品と時間が足りていないため完成には至っておりませんが、いくつかの部品（メスピンヘッダ等）が届き次第、完成形にしたいと思います。


//image[tweet_icon_modified][その時のツイート]

//footnote[tuiito][『せかいい on Twitter: "え、ちょっと待って完成したんだけど！？え！？！？" / Twitter』 @<href>{https://twitter.com/Jewel_Flash/status/1462814517910405120, https://twitter.com/Jewel_Flash/status/1462814517910405120} （2021年11月23日閲覧）]


また、今回のチャレンジは電子工作のみならず、それ以上にこの原稿がとてもチャレンジングな試みでした。「本は読むもの」で暮らしてきた私にとって、このような原稿を書くというのは、どうにも実感が沸きません。しかし、初心者目線での話であればなんとか書けてしまうということが今回わかり、作例や新しい話は難しいという方もぜひ書いてみてほしい、そのような本を読んでみたいと思いました。もともと同人誌というのは権威のある科学誌などとは異なり同好の士が集い、作り上げ消費するものがあってもいいはずです。もちろん高度な内容のものやとてもニッチなものもありますし、単独発行が（内容や採算的に）難しいのは私も同じです。しかし、誰か信頼できそうな人に誘われたときは（可能であれば）断らずにぜひ参加してみてほしいと初参加者の感想として思います。ソロには限界があるから@<fn>{saoのパクリ}。超初心者向けの本と、一通りのことはマスターしていることが前提の中上級者向けの本、その間を埋めるチLチカの次の本としてとても意味のあるものだと私は思います（もちろん、中上級以上のみはもちろん、超初心者向け同人誌もいいと思います）。

//footnote[saoのパクリ][TVアニメ『ソードアート・オンライン』１期第２話のキリトのセリフのパクリ]


なお本論とは関係ないですが、今回、最初の注意書き@<fn>{maegaki}のおかげで登録商標や会社名を気にせず書けるのがとても気が楽でした。

//footnote[maegaki][まえがきの免責事項。「会社名、商品名については、一般に各社の登録商標です。TM表記等については記載しておりません。また、特定の会社、製品、案件について、不当に貶める意図はありません。」]

=== 追伸


分圧回路って、その電圧になる仕組みはわかるけど、マイコンとかの動力源にしていいものなのでしょうか。あと、いい加減ちゃんとした大きさのブレッドボードがほしくなってきたので、おそらく近いうちに買います。たぶん。

==== 参考文献


ABK28(2021)『Google Spreadsheetを管理テーブルにした、ESP8266タイマースイッチ（AC） - Qiita』 @<href>{https://qiita.com/ABK28/items/60aef868b61a48e0e715, https://qiita.com/ABK28/items/60aef868b61a48e0e715} （2021年11月22日閲覧）


CL(2015)『ESP-WROOM-02で玄関お出かけ天気カラー照明灯 - M.C.P.C. (Mamesibori Creation Plus Communication)』@<href>{https://cl.hatenablog.com/entry/esp-wroom-02-weather-light, https://cl.hatenablog.com/entry/esp-wroom-02-weather-light} (2021年11月19日閲覧)


exabugs(2016)『ESP8266 (ESP-WROOM-02) でWi-Fi使用時のSSID/パスワードをブラウザで設定できるように - Qiita 』 @<href>{https://qiita.com/exabugs/items/2f67ae363a1387c8967c, https://qiita.com/exabugs/items/2f67ae363a1387c8967c} （2021年11月22日閲覧）


せかいい(2021)『せかいい on Twitter: "え、ちょっと待って完成したんだけど！？え！？！？" / Twitter』 @<href>{https://twitter.com/Jewel_Flash/status/1462814517910405120, https://twitter.com/Jewel_Flash/status/1462814517910405120} （2021年11月23日閲覧）


SWITCH SCIENCE(2017)『i-Weather（アイウェザー）～玄関先で天気を知らせてくれるIoT～ - スイッチサイエンス』@<href>{https://www.switch-science.com/catalog/3270/, https://www.switch-science.com/catalog/3270/} （2021年11月19日閲覧）


天気予報 API（livedoor 天気互換） (2020)『天気予報 API（livedoor 天気互換）』@<href>{https://weather.tsukumijima.net/, https://weather.tsukumijima.net/} （2021年11月19日閲覧） 


TOYODA Eizi（2021）『TOYODA Eizi on Twitter: "一番伸びてるのはこれかしら。仕様の継続性や運用状況のお知らせを気象庁はお約束していないという意味で、APIではないと申し上げざるを得ないのですが、一方で政府標準利用規約に準拠してご利用いただけます。" / Twitter』@<href>{https://twitter.com/e_toyoda/status/1364504338572410885, https://twitter.com/e_toyoda/status/1364504338572410885} （2021年11月19日閲覧）


tsukujima (2020) 『GitHub - tsukumijima/weather-api: 天気予報 API（livedoor 天気互換）』 @<href>{https://github.com/tsukumijima/weather-api, https://github.com/tsukumijima/weather-api} （2021年11月22日閲覧）


他、各種データシート等。
