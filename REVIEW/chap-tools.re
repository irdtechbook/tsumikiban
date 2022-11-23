= 持っているとよいもの（工具とか）

//flushright{
おやかた@oyakata2438、ふーれむ@ditflame
//}

楽しい電子工作を行うためには、いろいろ持っていると便利なものがあります。最初からすべてをそろえる必要はありませんが、順次そろえていけるとよいです。最初からよいものを買うか、最初は安いやつで使い勝手のいいものに順次変えていくかといったところに議論はあります。個人的には、最初は安いやつで、順次入れ替えていくことをおすすめします。使うかわからないのに最初に高いものを買って挫折すると、必要以上にメンタルに負荷をかけてしまいます。もちろんオシロのように、エントリーモデルでもそこそこの値段する場合も少なくないですが…。


ただし、よいものを買うことが無駄であるというつもりは、全くありません。よいものはやはり使い勝手もよい場合が多いのです。はんだごてやニッパーなどは、価格2倍でも10倍使いやすい、といったことはザラにあります。


以下に電子工作を楽しむ上で必要になることが多いツールを列挙します。具体的に「このメーカーのこれがよい」という例はあまりありませんが、参考にしてみてください。そして最終的には、あなたに合うものをぜひ見つけ出して下さい。

== テスタ


安価なものなら、秋月電子やAmazonで1000円程度から売っています。当面はこの程度で十分です。むしろ他に持っていないなら、ふたつみっつ購入してもよいでしょう。


機能としては、交流直流の電圧、抵抗、導通が基本中の基本で、どのテスタにも当たり前のように存在します。そして、これらはよく使います。


デジタルのものが便利です。また、オートレンジならなお便利です。ただし、オートレンジなものは機能が少なめなことが多くなります。コンパクトで便利なのですが。


価格が上がると、精度が上がる、計測可能な機能が増える、などのいいことが増えてきますが、あまり使わない可能性もあります。テスタの上位機種において追加される機能は、電流計測、周波数計測、容量（コンデンサ)、温度計測などがついたり、Bluetoothで通信ができたり、などがあります。


それ以外にも、安価なものと上位機種では分解能が異なります。確度(精度）も異なります。安価なものなら、3・1/2桁（1999が最大。小数点は変わる)なのに対し、据え置き型のデジタルマルチメータでは6・1/2桁なんていう機種もあります。また、レンジが細かくなったり、真の値と表示値のズレという意味での精度が向上するといったことも。ただ、本書で取り上げるマイコンを使った工作においては、ほとんどの部分はデジタル的に動作します。したがって、分解能にあまり意味がないという場合も多くなり、精度はあまり追求しなくてもよいでしょう。もちろん、オーディオアンプなどを扱う場合には"測定器の精度"も重要になります。本節ではこれ以上「精度」について深入りはしませんが、奥の深い分野ですので、興味があればぜひ調べてみてください。


さて、秋月電子でチェックするあれば、以下に示すようなものが安価かつ使いやすいでしょう。価格は本稿執筆時点(2021年9月)の税込み価格を参考として掲載します。


手帳型ポケットテスター　DT-10B　1200円


@<href>{https://akizukidenshi.com/catalog/g/gM-15911/, https://akizukidenshi.com/catalog/g/gM-15911/}


ポケット型ながら、基本的な電圧、抵抗、ダイオードチェックはもちろん、コンデンサ容量と周波数測定が可能です。


デジタルテスター　マニュアルレンジ　hFE測定機能 MAS830L(2017) 1400円


@<href>{https://akizukidenshi.com/catalog/g/gM-12542/, https://akizukidenshi.com/catalog/g/gM-12542/}


電流計測、トランジスタチェック機能つきです。前述の手帳型ポケットテスターよりは筐体も大きくなりますが、それでも机の上に置いておいて邪魔になるほどのサイズではありません。


トランジスタは少し発展した工作において使う可能性があります。具体的には、増幅やスイッチといった様々な用途がありますので、お守りとして持っておくとよいかもしれません。


なお、測定できる対象が少し増えたテスターは「デジタルマルチメータ」と呼ばれることがあります。導入される際は、こちらのキーワードでも探してみるのがオススメです。

== はんだごて


電子工作といえばはんだ付け、というイメージがあるかもしれません。実際、はんだ付けができると、できること、作れるものの幅は一気に広がります。


はんだごては使い勝手、作業性に直結するので、各メーカーから様々な特長を持ったはんだごてが出ています。


まず、容量/発熱量があります。よく言われるのは、20W～30Wは電子工作用（プリント基板など）、60Wクラスは電線をはんだ付けするとき、100Wやそれ以上は板金をはんだ付けするときに使う、ということです。


容量が大きすぎるものを電子工作用に使うと、こて先が高温すぎて、うまくはんだ付けできない、基板を焦がしてしまう、素子を壊してしまうなどの弊害が出てきます。容量が小さいものだと、はんだ不良を生じたり、逆に長い間当ててしまい基板を壊してしまうなど、やはり望ましくありません。


次に、温度調節ができるかどうか、という観点での選択があります。本体につまみがついていたりして、適温を選択することができます。


もうひとつ重要な特長が、こて先の形状です。尖っているものばかりではなく、少し太めになっているもの、太めの先を斜めに切り落としたもの、広幅なもの、その他さまざまな形状があります。よく見る抵抗のように、両側に針金（リード）が付いているものをはんだ付けするなら尖っているもので問題はありませんが、表面実装のICのように接近してはんだづけする必要がある場合などは、こて先の形状にも気を配ることで作業性と確実性が向上します。


さらに、温度調節ができるタイプのものですが、温度制御部が分離されているタイプのもの、こてホルダーが一体型になっているものなど、様々あります。


とりあえずこれを買っておけば外れることはない、という選択肢が、HakkoのFX-600です。


@<href>{https://www.hakko.com/japan/products/hakko_fx600.html, https://www.hakko.com/japan/products/hakko_fx600.html}


温度調節可能なタイプで、使用可能な温度になるまでも早く、先端が細いタイプで電子工作のたいていの用途に適します。価格はAmazonなどでも4000円前後で購入可能です。そういえば、過去にエヴァのコラボモデルもありましたっけ。


あとは、作るものに合わせてこて先の形状を変えたり、容量を選んだりしていきましょう（たとえば、アマチュア無線用のアンテナ端子のはんだ付けであれば、上記のハンダゴテでも厳しいコネクタというのが普通にあったりします。M型コネクタとか…）


ちなみに、プロフェッショナルな組み込みの現場ではRoHS対応しないといけないので、有鉛ハンダと無鉛ハンダではんだごてを完全に分離して運用していたりしますよ（家庭の電子工作ではそこまでしなくともいいと思いますが…）。

== はんだ


はんだ、正式名称は「半田」ですね（諸説あるらしいですが）。長らくは鉛と錫の合金にフラックス(松脂)を添加したものでしたが、昨今は鉛中毒に対する環境対応のため、鉛フリーハンダが一般化していますね。


なお、はんだを溶かしたときに薫り高い煙が一筋立ちますが、これはフラックス（松脂）によって発生する煙です（はんだはコテ程度の温度だと当然ながら気化しませんので…）。


基本的なはんだごてはストレートタイプ（１本の棒状）なので、はんだとはんだごてをお箸のような要領で持つことになります（利き手じゃない手は普通だと素子や基板を持つことになるので）。


このとき、普通にはんだの線を握ってもいいのですが、はんだ付けに慣れてない人は、以下の要領で（通称）はんだペンを作ってはんだ付けで試してもらえると、大分楽になるような気がします。

 * 使い切ったボールペンの芯を捨てて軸だけを確保。（なお先端が金属のものをお勧めします。樹脂だとはんだごてがあたって溶けます。）
 * ボールペンの芯ぐらいのサイズに糸ハンダを巻く
 * 芯のかわりに上記の巻いた糸はんだを挿入し、先から引き出す（はんだが足りなくなったら、利用都度引き出す）



で、はんだごてとはんだペンをお箸のように保持し、はんだ付けを行う、というスタイルになります。


これ、本当にめちゃくちゃ楽になります。はんだづけが苦手な方、ぜひ試してみてくださいね。

== オシロスコープ


波形を見るために必要なのが、オシロスコープです。オシロスコープであれば、時間変化に伴う測定値の変化が画面上で確認できます。測定した瞬間の値を測るテスタとの違いはそこにあります。


最近は、安価なデジタルオシロスコープが市販されています。10年くらい前はまだ10万円以上するものが多く高価な計測器でしたが、最近では3万円前後から新品が入手できます。帯域は50MHz～100MHzと個人ユースには十分ですし、このレベルの測定ができるのであれば、AMラジオやFMラジオの設計実装時の測定すらできますね。昨今のオシロスコープは優秀で、USBドライブへの波形保存、スクリーンショットなども標準搭載です。また、デジタルオシロですので、FFTなどの機能も標準搭載です。


10年前でしたら、「デジタルオシロへの乗り換えによって安価に放出されるようになったアナログオシロをヤフオクなど(いまはメルカリ？)で入手するのがよいでしょう」なんていう説明をしたかもしれません。ですが、今はもう新品のデジタルオシロを買ってしまってもいいでしょう。アナログオシロと比較して非常にコンパクトになっています。アナログオシロの表示装置はCRT(Cathode Ray Tube 陰極線管。昔のテレビで使われてたもの)でしたが、現在は液晶になっています。結果として前面の面積は大差なくとも、表示領域は大きくなり、奥行は大幅に（1/5以下?）短くなり、かつ大幅に軽量化されています。


それでも3万円は高いなーと思われる場合は、USB接続のPCオシロを使うことが第2の選択肢になります。1万円前後から購入でき、モニタや操作用のスイッチ・ボタンがない分、さらに小型なお弁当箱サイズになっています。


PCオシロは、データ処理部のみのデバイスで、表示や操作はPCから行います。電源もたいていの場合はUSBからの給電となります。波形を見る、データを保存する、といった用途には十分です。Amazonなどで「PCオシロ」と検索すれば見つけられるでしょう。


また、PCオシロは、その他の様々な機能を有していることが多く、信号発生（ファンクションジェネレータ）やロジックアナライザの機能も持つものもあります。


Analog Discovery アナログ回路万能測定ツール　27450円


@<href>{https://akizukidenshi.com/catalog/g/gM-07738/, https://akizukidenshi.com/catalog/g/gM-07738/}


卓上でこの機能を備えようと思ったときは、それぞれ個別にオシロ、ファンクションジェネレータ、ロジックアナライザと揃えるとか、オシロとロジアナ機能を有するMSO(Mixed Signal Osciloscope)を入手するなどが必要となります。MSOはオシロの上位互換のラインナップであることから、十万円を超える価格帯となってきます。簡易なロジアナ機能も含めて、PCオシロは十分に選択肢に入るでしょう。

== 金モシャ


金モシャは通称です。この呼び名はごく狭い界隈かもしれません。


白光(HAKKO) こて先クリーナー クリーニングワイヤータイプ 599B-01　567円　@<href>{https://www.amazon.co.jp/dp/B000AQQFMG/, https://www.amazon.co.jp/dp/B000AQQFMG/}


はんだ付けをしていると、はんだごての先にはんだやヤニのカスが付いたりします。そのままはんだ付けすると、はんだがうまく載らなかったりブリッジしたりで失敗する可能性が上がります。そこで、適宜こて先をきれいにしたいときにあると便利です。


金色のスチールウールのようなモノがケースに入っていて、ここにこて先をザクザク突き刺すと、こて先がキレイになります。


従来のこて先クリーナーは、水を含ませたスポンジを使うことが多かったのですが、水をつけることでこて先の温度が下がってしまいます。金モシャは温度低下が起こらないので、ちょっとしたことですが便利です。また、ちょっとしたこて台としても使えます。

== はんだごて置き台


前項で記載している「水を含ませたスポンジ」を含む、こて置き台です。


昔のはんだごてであれば、先にはんだごての所で説明があったような温度調節機能がついていないので、そういった頃は水を含ませたスポンジで　温度調節とある程度のざっくりとした温度測定を行っていたのです（こて先をスポンジに付けて、水分が勢いよく突沸して水蒸気になれば適温）。


温度調節機能がないはんだごてを使っている場合には、はんだごて置き台＋水を含ませたスポンジを利用することになるでしょう。

== はんだ吸い取り器


はんだ付けに失敗したときや、はんだをつけすぎたときに使います。


一番お手軽なのは、銅の網線に吸い取らせるやつです。「はんだ吸い取り線」などと検索してみてください。小さいものなら300円程度と、安価です。はんだを吸い取った部分は切って捨て、新しい部分を次々に使います。とはいえ、1巻で相当使えます。ただし、スルーホールの吸い取りは結構難しいです。


スルーホールものイケるやつとなると、ピストンタイプのものがあります。ピストンを押し込むとロックされ、はんだごてで温めておき、吸い込み口を近づけボタンを押すと、ピストンが戻るときに近くのはんだを一気に吸い取るものです。こちらは1000円～1500円くらい。スルーホールもいけるとはいえ、垂直に当てないと、きちんと溶かさないとうまく吸えないなどコツがあるので、慣れるまで頑張りましょう（別に一度に全部吸い取れ切らなくてもいいので、何度も吸うぐらいの気持ちのほうが楽な気はします）。


さらに上位となると、電動のはんだ吸い取り器があります。はんだごてに電動のポンプがついたようなもので、先を温めながら吸い込むため、スルーホールであっても容易にクリーニングできます。ネックはお値段。HAKKOやGootなどの有名なメーカーのものは18000円くらいします。ちょっとお高いですね…

== ブレッドボードとジャンパ線


試作のときに便利なのがブレッドボードです。等間隔に穴が開いていて、穴にICや素子を差し込み、ジャンパワイヤーを使って配線することで回路を組み上げることができます。穴にさすだけで導通するので、はんだ付けなどは不要ですし、ジャンパワイヤーを差し替えることで回路の変更、修正も容易です。穴ピッチはたいていの場合2.54㎜ピッチになっており、汎用ICの足間隔と一致しているので、そのまま差し込むことができます。また、小型の素子でも、ピッチ変換ボードのようなものが市販されていて、そのまま使うことができるようになります。

== 抵抗


抵抗は、LEDの電流制限、オペアンプのゲイン調整などに使います。とはいえ、最近のデバイスはたいてい繋ぐだけで使えますので、あまり数を使うことはないでしょう。ただ、抵抗のストックがないと、いざというときに困ってしまいます。


おススメの選択はふたつです。


ひとつは、1kΩ、10kΩあたりの定番品を数種類買っておき、必要な値に組み合わせること。1kΩから500Ωを作るときは2本並列に使います。2kΩは直列に使います。500Ωと1kΩを直列にすると1.5kΩになりますし、1kΩを3本並列にすると333Ωが作れます。


もうひとつは、「抵抗セット」を購入するという手があります。30種類程度の抵抗、各20本程度がセットになったものです。価格は1000円～1500円程度です。もちろん都度テスタで測ってもよいですが、テープの切れ端に値が書いてあるので、カラーコードが読めなくても困りません。


抵抗には、「頻繁に使うもの」と「めったに使わないもの」「ほぼ使わないもの」があります。使うものだけ購入するというのが無駄がないようですが、セットで持っておくことで、いざというときに便利に使えます。最初にセット品を買って、1セットを使い切る頃には、使用頻度が見えてきます。使う可能性の高いものだけ100本1袋100円で追加購入するとよいでしょう。あとはお守りとして残しておきます。

=== 抵抗のカラーコード


抵抗といえば、よく困るのは「抵抗のカラーコードが読めない！」というケースですね。


語呂合わせを以下に記載しておきますので、可能なら覚えてしまいましょう。


～～～～～～～～～～～～～～～～～～～～


黒　⇒　黒い礼（０）服


茶　⇒　小林一（１）茶


赤　⇒　赤ニ（２）ンジン


橙　⇒　オレンジみ（３）かん


黄　⇒　四（４）季（黄）の味　※ふりかけでありましたよね昔


緑　⇒　ご（５）み（みどり）


青　⇒　あおむ（６）し


紫　⇒　紫七（しち：７）部


灰　⇒　ハイヤー（８）


白　⇒　ホワイトク（９）リスマス


～～～～～～～～～～～～～～～～～～～～

== LED


LEDを光らせることで、入出力のチェックなどに使えます。ボードの最初の動作確認のためにLEDを点灯させるなど、様々な動作検証に使えますので、1袋持っておくとよいでしょう。入出力が意図した通りになっているかで光らせたり、一連の処理が終わったら光らせるなど、デバッグコンソールのように使うことができます。


赤でも緑でも構いません。赤のLEDなら10個200円とか100個350円とかいったレベルで売っています。短時間なら直結してもたいていの場合は問題ありませんが、おまじないの電流制限抵抗は忘れないようにしましょう。こういった使い方をするためにも、電流制限抵抗に使えるような抵抗をセットで持っておくのは有用です。


また、デバッグ用のLEDはレンズがスモークのものにすることをお勧めします。LEDは基本的に発光の指向性が高く、前に強く光ります。したがって、横から見えづらかったり、写真を撮るときに白飛びすることがあります。そこで、レンズがスモークタイプのLEDとすることで、横から（真正面以外から）も発光が見えやすく、また輝度が抑えられるので、記録用の写真や映像を撮るときに白飛びしづらくなります。

== 小型液晶


LEDよりも情報量を増やしたいとき、また実際に何かデータを表示するとき、小型の液晶モニタがあると便利です。


Ｉ２Ｃ接続小型ＬＣＤモジュール（８×２行）ピッチ変換キット　600円


@<href>{https://akizukidenshi.com/catalog/g/gK-06795/, https://akizukidenshi.com/catalog/g/gK-06795/}


これに限りませんが、（適切なライブラリを使えば）数行のコードで文字や数字を表示することができます。デバッグ用に使うこともできます。「動いているのか動いてないのかわからない」という状況のデバッグは非常に大変です。ステップごとに何かを表示する、などを行うために、すぐ使えるようにしておくと大変便利です。ピッチ変換キットを使うことで、ブレッドボードに直接接続して使うことができます。配線はわずかに4本くらいです。電源、GND、SDA、SCL（I2Cの2線）で使えます。手元に持っておくといろいろ使えます。ぜひ持っておきましょう。

== オペアンプ


オペアンプが手元にあると、信号を増幅したり、レベルシフトをしたり、様々に使えます。とりあえずは汎用のオペアンプで十分ですが、使ってみて性能が足りないなどがあれば、その特性に合わせたものをきちんと選定しましょう。


オペアンプが必要になるシチュエーションとしてよくあるのは、交流信号をデジタル値として取り込みたいとき、ADコンバータの特性が0～5Vしかないため、振幅を半分にしつつ、2.5V±2.5Vにレベルシフトする、といった用途です。入力信号の仕様をきちんと確認するためには、オシロがあるとよいですね。周波数と振幅はオペアンプ設計の上で重要なパラメータです。

== DC-DCコンバータ、三端子レギュレータ


最近ですと、電源はUSBから取ることが多くなっていますが、USB-Aの端子からは5Vしか取れません。オペアンプのように±15Vが必要な場合、あるいはセンサによっては別の電圧の電源が必要な場合、最近のマイコンのように全体が3.3Vで動作する場合など、別の電圧を作る必要があります。このとき、USBから取れる電圧では対応できないので、ACアダプタ等を使う場合か、DC-DCコンバーターで作ってやる必要があります。DC-DCコンバーターは、入力電圧と出力電圧を指定（または変更）して、ほしい電圧を作ります。入力電圧より低い電圧しか出せないタイプの電源と、入力電圧より高い電圧を取り出せる電源があります。電圧固定のものと可変のものがあります。可変のものは便利ですが、1個数百円程度する場合もあります。降圧だけでよければ、1個25円などといった程度で購入することができますので、数個持っておくと便利です。

== ACアダプタ


モーターなどの「重い」負荷を用いる場合のため、ACアダプタを別に持っておくのがよいです。USBから取れる電力は2.5W(5V500mA)ないしは10W程度(5V2A程度)です。小型のモーターの代表であるマブチモーターは最大で1A程度の電流が必要ですので、マイコンボード経由はいうまでもなく、USBから直接電源を取るのは避けましょう。マイコンボードのピンから取り出せる電流には限りがあります。データシートに載っていますが、通常数十mA程度です。LEDを光らせるには十分ですが、モーターなどを直接駆動することはできません。


モーターのような重い負荷をマイコンの出力端子に接続すると、定格を超える電流を引き出そうとして、マイコンを破損することがあります。Highレベルの端子をGNDに落とすようなものですので、注意しましょう。


ACアダプタとは若干別の話になりますが、重い負荷を用いる場合は、マイコンでリレーやトランジスタなどをスイッチとして駆動して、そのスイッチにより負荷を動かす必要があります。このとき、負荷を駆動するための電流源としてACアダプタが必要になります。


電圧は5V、12Vがあると、たいていの場合は事足ります。昔のHDDケース用やいろいろなデバイス用のACアダプタがそこらへんから出てくるのではないでしょうか？家に1個や2個、余ってるACアダプタはありますよね？動作チェックしたうえで、そういったものを流用することもできます。ついついたまってくるので、定期的に見直し、廃棄は行うとよいでしょう。


電圧でいくつかのバリエーションを持っておくとよいですが、前述のDC-DCコンバーターと組み合わせて使うこともできます。また、出力可能な電流にも（実際に作るときには）注意する必要があります。たとえば、1Aしか出せないACアダプタに5Aを食う負荷を接続すると、うまく動かなかったり、起動しないといったこともありえます。最悪ACアダプタが燃えます。ご注意を。


電源周りについては「電子工作における各種電源について」を別章として記載していますので、本章も併せてご覧ください。

== センサ各種


温度センサなどセンサ各種があるとちょっとした機能追加には便利なのですが、いかんせん何に使うか、何がほしいか、といったあたりがネックになり、無限に増えるか、帯に短したすきに長し…となるかのどちらかです。


センサの出力にも、アナログ出力、通信での出力があり、通信もI2C、SPIなどがあります。測定可能範囲もいろいろあり、パッケージ（足の数やピッチ）、電源電圧などなど、非常にたくさんの選定基準があります。「適当に持っておく」というのは、なかなかつらいものがあります。したがって、残念ながら都度購入する方が確実です。ただし、買うときは数個余分に買っておくと、壊したり次作る別のものに使えたりします。結果として、無限に増えるわけですが。

== USBケーブル


USBケーブルなんて、意図しなくても手元にあるでしょう。しかし、PCに接続する口の形状が異なることがあります。最近ではType-Cのものも多いですが、MicroUSBのもの、USB Type-Bのものなどあります。いざ使おうと思ったときにケーブルがないなど残念ですから、1本ずつはストックしておくとよいでしょう。


また、USBケーブルにも相性があります。USBという規格にのっとったコネクタなのでどれでもよいといいたいところですが、そういうわけでもありません。コネクタの微妙な個体差、中の線が細くて電流が取れない、他の機器では使えるのに特定の組み合わせだけ動かないといったことがありえます。「なぜか動かない」というときは、上流、手元からさかのぼってみましょう。あるマイコンを使って工作をしているとき、一番手元に近いものはPCです。次がUSBケーブル、マイコンという順番になります。したがって、USBケーブルがダメだと、その先が動きません。そんなとき、予備のUSBケーブルがあれば交換して試すことができます。交換して変わらなければそこは原因ではない、という切り分けができます。


なおUSB3.1 Type-C以降の端子には端子部分に機器とネゴシエーションをするためのチップが内蔵されているので、電子回路の電源としては辛いものになってしまいました…

== ミノムシクリップ/ワニ口クリップ/ICクリップ


両端がクリップになっている、10cm～1mくらいの銅線です。手軽に配線に使えます。塩ビのカバーが付いていて、ミノムシのような形のものをミノムシクリップ、絶縁カバーのないもの、あるいはもう少し大きいクリップをワニ口といったりもしますが、細かい名称は気にしなくて大丈夫です。これも数本持っておくと便利です。


また、ブレッドボードに部品を刺して使うことも含め、ミノムシクリップよりもICクリップの方が使いやすいかもしれません。ICクリップは、後ろを押すと先端が曲がった(フックになった)クリップが出てきます。これをICなどの部品の足にひっかけて配線することができます。


ミノムシクリップより小さいので、小さいICにも使いやすいですし、隣とショートする心配も減らせます。

== インシュロック


ケーブルタイなどとも呼ばれるやつです。ケーブルをまとめるのに使います。


透明、白いやつや色付きは紫外線に弱く、@<em>{黒は耐候性を持っているので屋外での使用に耐えがち}です(一応詳細仕様は確認したほうがいいけれど)。


また、特殊な使い方としては、ケーブルの被覆（カバー）を伝って屋内に水が侵入しないように、屋外に設置した機器やアンテナのすぐ側で一度ループを作ってやり、家に引き込むようにするとケーブルの中を伝っての家への水の侵入を防げるのですが、こういったケースにもインシュロックは役立ちます。

== 絶縁部材としてのテープやチューブ類


乾電池で動かす程度の電子工作であればなくとも構わないのですが、AC電源で常時給電したり、更に安定化電源を自作するなどAC100V電源が直接給電されるような場合において、絶縁確保をきちんとしたくなることがあります。


大まかな言い方をしてしまうと、絶縁を確保するためには絶縁体で導体をコーティングし、導体が他の導体と付かないようにしてあげれば(絶縁破壊が起きない限りは)大丈夫で、結構取れる選択肢も幅広い話ではあります。ですが、そのようなときに使いやすいものは、大きく３つほどの絶縁部材に収束するイメージがあります。

=== ビニールテープ


電気絶縁用ビニールテープは安くで@<em>{絶縁を確保できる}代表格ですね。


１本持っておくと色々と便利です。使い方は切って巻くだけなので直感的に使えるのもいいですね。ただし、テープの常としてテープの接着成分が線の被覆やケースなどに長時間貼り付いているとネトついてくるので、そういうのが嫌な人もいるかもしれませんね。


あと、老朽化すると剥がれてきたりします。

=== 熱収縮チューブ


熱収縮チューブというのは特殊な素材でできたチューブで、チューブを切って回路を組むまでにあらかじめ線に通しておき、その後@<em>{熱を与えると径の方向に縮み}ます（平易な言葉でいうと@<em>{細くなる方向に締まる}）。
専門的にはヒーティングガン（業務用のドライヤーみたいなやつ）を使って締めるのですが、そういうものがない@<em>{家庭などではヘアードライヤーを一番強い熱風モードで接射して締める}のが一般的です（なおライターなどでやってはダメです。高熱すぎると変形したり嬉しくない結果になりがち…）。


収縮率は一般的に50％といわれていて、半分の径になるまで締まります（あくまで一般的な値なので、厳密なところは製造元の公式な特性データを確認して下さいね）。LEDと線をラッピング上で巻いた後に細い熱収縮チューブを締めて一体化してみたり、線の保護などもできます。熱収縮チューブ自体には防水性能も一般的にあります。

=== 自己融着テープ


屋内での電子工作だけだと不要かもしれませんが、自己融着テープはちょっと特殊なテープで持っていると嬉しいケースがままあります。


このテープは引っ張りながら何重にも巻き、しばらく時間が経つと、その巻いた@<em>{テープ同士が一体化}します。


一体化することで、テープが剥がれてきたりすることを根本から防げますし、防水性能も得られます。更に前述のビニールテープと組み合わせることで、両方の特性をうまく組み合わせて使えます。ビニールテープを巻いて絶縁を確保した上で、そのビニールテープの上から自己融着テープを巻くことでビニールテープを保護しつつ防水性能を高めることができます。


ただ、自己融着テープは紫外線に弱い特性があり、強度が必要（なにかで擦れたりする）な箇所だと

 * まずビニールテープで巻いて絶縁
 * 次に自己融着テープで巻いてビニールテープをガードしつつ防水
 * 最後にビニールテープでもう一度巻いて自己融着テープを紫外線や擦れなどから守る

という施工パターンまであるそうです。ここまでやると完全にプロ仕様のような気はするのですが、たとえばアマチュア無線で屋外に自作アンテナを設置したり、IoT機器を屋外に設置したときの防水対策に困っている場合はこういった施工を検討してもよさそうですね。


== すべてを一気にそろえる必要はない


持っておくとよい、便利に使えますよ、という文脈で様々なツールを紹介しました。ただし、すべてを最初から揃えないといけないかというと、その必要はありません。まして、持ってないと開発・電子工作ができないというわけではありません。


特に計測器などは必要が生じたら検討するのがよいでしょう。一昔前に比べると安価になったとはいえ、数千円から数万円する装置はたくさんあります。買ってみたはよいが使わないというのももったいない話です。


また、部品なども、作りたいものがあるなら、それを作るのに必要な部品だけで十分なはずです。ただ、ちょっとしたミス、設計変更、機能追加などで追加部品が必要となってしまうことはよくあります。そういったときにいちいち通販や買い物に行くのも面倒です。予備があれば開発スピードは大幅に向上するでしょう。


ただし、そういうときのために、余った部品はストックしておくといった癖をつけたとして、その「そういうとき」というのはめったにきません。矛盾するようですが。
