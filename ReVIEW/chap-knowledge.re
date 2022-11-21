= 知っておくとよいこと

//flushright{
おやかた@oyakata2438
//}

ボード、マイコンを使った電子工作を行うにあたって、知っておくとよいことは様々あります。本章では、それらについて取り上げます。


他の章の内容とも重複する部分がある場合もありますが、そのときはそれが重要な内容であるとご理解ください。

 * オームの法則
 * 直列と並列
 * データシートを読む
 * USB/シリアル変換
 * さらに知りたくなったら…


== オームの法則


@<strong>{オームの法則}は覚えていますか？名称は中学校で習ったはずです。忘れていたら思い出してください。ある回路に流れる電流は、電圧に比例し、抵抗に反比例する、という関係、法則です。


電圧=電流×抵抗　E=IR　といった式が出てきます。実は、マイコン工作においてオームの法則を使うことはめったにありません。LEDなどの電流制限抵抗を決めるときに使うこともありますが、それ以外で抵抗値を選ぶことはあまりありません。


理由はいくつかあり、駆動するもの(負荷ともいいます)はたいていの場合非常に低消費電力なので、電流のことを考える必要がなく、指定された電圧を印可するだけで動作します。もうひとつの理由は、LEDのように電流電圧特性が非線形なものが多く、かつ動作マージンが広いものが多いので、多少適当なものを入れても大丈夫です。


したがって、LEDの電流制限抵抗などは、おまじないのように「とりあえず1kΩ入れておくか」、といった感じで決めてしまうことも少なくありません。もちろん理論、計算方法を知っておくことは重要ですが、マージンが広いので、トライ＆エラーで差し支えない場合も多いのです。


電源電圧が5V、順方向電圧が3V、LEDの最大電流値(IF)が10mAだから、(5V-3V)÷0.01A=200Ωを入れよう、といったように計算することもできますが、とりあえず1kΩでいいや、とやっても、大事故にはなりません。電流制限抵抗は大きめにしておいた方が安全です。作例もたくさんあります。そういったものをうまくつまみ食いしながら、初めて使うときには自分で計算して確認しつつ、それでも壊れちゃったときはあきらめる、次に活かすくらいの気持ちでやるのがよいでしょう。


ここではオームの法則の例ですが、それ以外にも電気回路などに関する法則、基本原理はある程度把握しておくと、部品を壊すリスクは下がります。もちろんミスや不具合で壊すこともあるのですが。

== 直列と並列


こちらも小学校で、乾電池の直列と並列で学びましたね。電池のプラス極とマイナス極を接続し、数珠つなぎにすることを直列繋ぎ、あるいは豆電球をふたつ使うときに、赤の線と青の線をつなぐときを直列とよび、乾電池を直列つなぎにすると豆電球が明るくなり、豆電球を直列繋ぎにすると暗くなるというような実験をしました。


さて、最近の電子工作において直列つなぎ、並列つなぎを意識することは、これまためったにありません。接続する先は、たいていの場合、複数ある入出力ポートにそれぞれ接続します。電源などには、並列につなぎます。


先ほど、負荷が低消費電力であるということを述べました。直列接続にすると分圧されてしまい、動作可能な電圧を下回ってしまい動作しなくなってしまうことが十分に考えられます。マニュアルなどに書いてある接続を守ることは必要ですが、そうでなくともたいていは並列接続で、直列接続を使うことはあまりない、と考えてもよいでしょう。


明確に直列に繋ぐ場合というのは、電流制限抵抗を使う場合と、電圧を稼ぐために乾電池を直列接続する場合くらいです。回路図などを考えたときに直列接続になってしまう場合は、何か間違っているかも、と一瞬確認した方がいいくらいです。

== Vcc、Vdd、Vss、他いろいろな表記


電源電圧、あるいはGNDレベルを表記するのに様々な表記があります。


たいていの場合、Vcc、Vddはプラス電源を指します。Vee、Vssはマイナスです。GNDという表記を見ると、基準電位(Ground Level)と思ってほぼ間違いありません。Vccはトランジスタ(バイポーラトランジスタの)のコレクタを接続するための電源電圧を意味し、VddはFET(電界効果トランジスタ)のドレインを接続するための電源電圧を意味します。同じくVeeはトランジスタのエミッタ、VssはFETのソースを意味します。ですが、VccとVddを区別する必要があるかというと、当面はありません。また、正負電源を使うことすら稀ですから、GNDとVssを区別することすら稀です。


ただし、メモを取る場合、自分で端子名を使って作る場合など、VccやGNDという言葉を勝手なところにつけるのはやめましょう。予約語のようなものだと思ってもいいかもしれません。予約語を勝手に使うと大きな混乱を生じます。


たとえば手書きの回路図を引くとき、電源電圧につながる端子にGNDと書き、出力端子にVssと書いたらどうでしょう？次に見かけたとき、大きな混乱を生じます。


オペアンプの図を引くときを考えます。片電源のオペアンプを使いましょう。信号入力があり、出力があります。プラス電源があり、負電源は不要（GND接続)とします。それを普通に図にすると、左側のようになります。手書きなら確かに名前の付け方は自由です。


//image[img-name][非直観的な命名]


自由だからといって、正電源にGND、出力にVdd、GNDにVccと名前を付けたらどうでしょう？数日後の自分、あるいは他の人が見たらどうでしょう？混乱しか生みません。やめましょう。出力はちゃんと出力とわかる名前にしましょう。

== データシートを読む


データシートを読む癖をつけましょう。


データシートには様々な情報が載っています。


以下に、抵抗などのパッシブ部品と、オペアンプなどのアクティブ部品を例として見ながら、どのようなポイントについてみるのかの例について確認してみます。


データシートには、たいてい以下の情報が載っています。後ろの英語表記は典型的な表記例です。国内通販サイトであっても、また国内メーカーのデバイスであっても、データシートは英語のことが少なくありません。

 * 部品名・シリーズ名
 * 特長（Features）
 * 寸法（Mechanical Dimensions）
 * 定格（Ratings）
 * 供給形態（Packaging/Taping）



オペアンプなどのアクティブな、あるいは電源を必要とするような部品の場合は、

 * 端子配列（Internal Block Diagram）
 * 絶対最大定格(Absolute Maximum Ratings)
 * 電気的特性(Electric Characteristics)
 * 特性例(Typical Performance Characteristics)
 * 品種(Ordering Iinformation)
 * 回路例、サンプル回路
 * 通信仕様



などが追加されます。


様々な情報がある中で、どこを読むのか迷ってしまうこともあるでしょう。


まずは、「抵抗」のデータシートを見てみましょう。秋月電子や千石電商、マルツなど有名な電子部品の通販サイトで適当な抵抗を探してみてください。


@<href>{https://akizukidenshi.com/download/ds/koa/mf.pdf, https://akizukidenshi.com/download/ds/koa/mf.pdf}


ここでは、秋月の　金属皮膜抵抗1/4W4.7KΩ　100本入り　
@<href>{https://akizukidenshi.com/catalog/g/gR-03391/, https://akizukidenshi.com/catalog/g/gR-03391/}　のページにあるデータシートを例にします。

 * 寸法（Mechanical Dimensions）
 * 定格（Ratings）



このなかで特に見るべきは寸法と定格です。


抵抗なんてどれも同じじゃないか、と思われるかもしれませんが、抵抗値以外に、寸法と定格電力は異なります。電子工作において1/4W以上の発熱が生じる用途は稀ですが、消費電力は一応確認しておきましょう。電流制限抵抗として使うときなどには効いてきます。オームの法則から計算することができます。


寸法は案外見落としがちですが、十分にチェックしましょう。特にプリント基板に部品を実装するときなど、寸法制約がある場合、素子の大きさに留意する必要があります。物理的に入りません。もちろん想定する部品があって作ったプリント基板ですから、適切なものを選べば問題ありません。また、多少なら無理くり押し込むこともできますが…


抵抗などのパッシブ部品であれば、データシートに書いてある情報やデータも項目がほそれほど多くありませんが、オペアンプなどのアクティブ部品となると、その項目は一気に増えます。また、限られたデータシートの範囲内に必要な情報を詰め込むため、説明が端折ってある場合が少なくありません。


オペアンプの場合は、以下の項目について確認します。秋月電子で取扱のあるオペアンプNJM458DDDを例に取り上げます。


２回路入ＨｉＦｉオペアンプ　ローノイズ選別品　ＮＪＭ４５８０ＤＤ　30円/個


@<href>{https://akizukidenshi.com/catalog/g/gI-00069/, https://akizukidenshi.com/catalog/g/gI-00069/}


@<href>{https://akizukidenshi.com/download/ds/njr/NJM4580_j.pdf, https://akizukidenshi.com/download/ds/njr/NJM4580_j.pdf}

 * 端子配列（Internal Block Diagram）



どういう風に接続するのかを記載しています。


オペアンプなら、入力が2本、電源とＧＮＤ（場合によっては負電源）、出力と5～6本の接続が必要です。単体で動作するセンサでも、電源、ＧＮＤ、出力となりますし、I2CやSPIなどの通信をするタイプのデバイスならその端子も必要です。抵抗などでは2本しかなかった接続部分が一気に増えることがわかりますね。


それに応じて、イメージしやすいIC然とした（黒いゲジゲジ）の形状を持つICが増えてきます。また、DIP部品と表面実装用部品が同じデータシートで記載されるなど、パッケージの差も出てきます。パッケージを間違えると、取付できない、あるいは変換基板を使う必要があるなど面倒もありますから、寸法、パッケージについてもここで確認するとよいでしょう。同じICだけど8PINのDIPパッケージと16ピンのSOICパッケージのものがあるという例もあります。また、「オペアンプ」のように同じ種類の素子なら同じピン配置になっていることが多いのですが、異なることもあります。それを確認する必要があります。

 * 絶対最大定格(Absolute Maximum Ratings)



この値は、絶対に超えてはいけない定格を示すものです。即故障しても仕方ない条件を示すもので、供給電圧、入力電圧、温度や印可可能な時間（Duty比）について記載されています。


Supply Voltageは電源電圧として印可できる電圧を示します。例として、±15V用のオペアンプにおいて、絶対定格が±18Vと定められているとします。このとき、電源端子を含むすべての端子にそれを超える電圧をかけてはいけません。


また、動作温度や保管温度に関する記載もあります。Operating temperature range -25~85 degreeとあれば、動作中にその温度を超えないように設計する必要があります。85℃って相当高い温度だし大丈夫じゃない？と思うかもしれませんが、近くにパワートランジスタや（大きめの）CPUなどの発熱する部品があれば、割と簡単に超えてしまう可能性のある温度です。


また、臭いセンサなどに多いのですが、間歇動作が必須なデバイスにおいては、最大Duty比が定められていることもあります。臭いセンサは電極を加熱し、その温度変化や抵抗の変化などで化学物質を検知する原理ですが、連続通電すると比較的簡単に壊れてしまいます。

 * 電気的特性(Electric Characteristics)



読むべきパラメータはデバイスの種類によって異なります。


オペアンプであれば、周波数帯域に関する情報はチェックしておくとよいでしょう。そのほかのデバイスでも、必要なスペックを満たしているか、ありていにいえば今必要な用途に合致する特性があるかを確認するためのシートです。


まず見るべきはスルーレートと利得帯域幅積(GB積）です。スルーレートは信号の立ち上がりの速さを示す値で、単位はV/us、要するに1usの間に何Vの立ち上がりが得られるかという指標です。基本的にはスルーレートは高いほうが「高性能」なオペアンプといえます。同様に、増幅率(ゲイン)と周波数の積を利得帯域幅(Gain-Bandwidth積)と呼びます。たとえば、10倍のゲインが維持できる周波数帯域が2MHzだったとき、GB積は20MHzとなります。100倍のアンプが欲しいとき、信号が10kHzだったらGB積は1MHzで十分ですが、信号が1MHzのときは、100MHzのGB積を持つオペアンプを選ぶ必要があります。


GB積は数MHz～数十MHzがせいぜいですので、データシートとにらめっこしながら素子選定・設計を行う必要があります。


他の項目はたくさんありますが、一通り眺めておくくらいでよいでしょう。

 * 特性例(Typical Performance Characteristics)



様々な特性（の典型値）をグラフで示したものです。典型的な横軸は周波数や温度、電源電圧です。電気的特性と異なるのは、横軸の値によって変わるものであること。オペアンプやセンサなど、入力と出力のあるデバイスが周囲環境等によってどう変化するのかを示すものです。


センサであれば、直線性の確認などにも用いられます。たとえば、指示温度を電圧として出力する温度センサがあったとき、温度とセンサ出力の関係を示すために使われます。


周囲温度に応じて、1V/10℃という関係で電圧出力を行うセンサがあったとしましょう。なおこのセンサは架空のものです。


さて、その出力はどこまで保証されるのでしょうか？データシートに図のようなグラフがあったとしましょう。


//image[img-tempsensor][温度センサの温度―電圧出力特性イメージ。実在のセンサとは異なります]


理想的な特性は点線ですが、75℃くらいを超えたあたりでずれてきていますね。


このデータをどう使うか、という例をさらに説明しましょう。「室温計」を作るときを考えます。室内が零下になること、50℃を超えることはまずないと考えられますね。そのときは、このセンサは使えます。


燻製器や低温調理器などを作るときを考えます。60℃とか70℃といった温度を扱います。ちょっと高くなってしまったとき、沸騰温度の100℃になることもありえますね。このときにこのセンサは使えるでしょうか？使えないことはないですが、高温側の精度(直線性)がイマイチですね。もっといいセンサを探した方がよさそうです。


これはあくまでも架空の特性をもとにザックリと選定した例ですが、用途と要求精度から選定するにあたって参照すべきデータがデータシートに書いてあります。


様々な作品例では、それぞれ適切な素子が選択されているでしょう。必要な精度、入手性、特性、価格、実装の容易さなど、様々な要素が絡みます。その中で、精度や特性、実装のための情報がデータシートに書いてあります。最初は内容盛りだくさん過ぎて「どこを読めばいいのか…」となりがちですが、読んでみると、案外読むべきところはそれほど多くないことに気付けるでしょう。そして、慣れてくればしめたもの。

 * 品種(Ordering Information)



同じ素子でもバリエーションがある場合があります。たとえば、耐久性テストを実施した軍事用、宇宙用の選別品、また車載用にパッケージを変更したものなど、「同じ型番」でも用途が異なるデバイスを用意している場合があります。そのとき、型番の最後1桁2桁が異なったり、特別な記号が付く場合があります。また、リールでの購入と、バラでの購入で型番が違うこともあります。ただし、個人での購入はたいていの場合、1個や2個、5個といった単位で購入するので、あまり気にする必要はないでしょう。こういう情報もあるということを知っていれば十分です。

 * 回路例、サンプル回路



標準的な使い方である回路図が載っている場合があります。参考にしましょう。


ノイズ対策としてのパスコンが省略されていたり、オペアンプのゲインの設定が異なったりしますが、それでも実装の参考になるでしょう。メーカー推奨の使い方、回路構成ですから、まずはここを基準に考えるのがゴールへの近道です。


また、本やWebページ、ブログなどの実装例を参考にしてつくってみたもののうまく動かないときは、データシートの回路例と対比して確認してみることをおすすめします。

 * 通信仕様



通信仕様についての情報です。通信コマンド、送信書式、受信データの変換の方法、タイミングチャートなどが記述されます。


MCP3425という16bitのADコンバータのデータシート例を示します。


@<href>{https://akizukidenshi.com/download/ds/microchip/mcp3425.pdf, https://akizukidenshi.com/download/ds/microchip/mcp3425.pdf}


何か難しそうな情報がたくさん書いてありますね。読み込んで、使い物になる実装をするのはかなり大変です。もちろん得るものは大きいですが、時間も労力もかかります。


まずはあきらめて適切なライブラリを使うのが手っ取り早いです。


本書はタイトル通り「入門」書です。ですから、一から自分でやることを否定するものではありませんが、本書のスコープ外となります。もちろん全部自分でやるといった「縛りプレイ」も電子工作をはじめとしたモノづくりの醍醐味ではありますが、まずは先人の成果にありがたく乗っかって、面白いものをさっくり作り上げるほうに注力しましょう。

== 更なる情報を得たい


電子工作で軽く遊ぶ分には付け焼き刃やちょい足し情報でも構わないケースも多いのですが、もう少し本格的にやりたくなったときに何をやればいいのかわからない、体系的にもう少し掘ってみたい……という方もおられるかもしれません。そういった方に向けての参考情報も記載します。


電子回路設計、実装に関する分野を体系的に学ぶために、色々と方法はあるのですが、筆者的にオススメなのは資格試験の受験対策書籍です。もちろん、受験しても更にいいですね！　ただこの本の本筋からは外れちゃいますのであまり詳しくは書きません。色々と筆者が取得したものを中心に書いておきますので、参考にしてくださいね。

=== 総務省系　(主に第四級アマチュア無線技士関連)


たとえば、第四級アマチュア無線技士の試験範囲は電子回路を中心に、基本的なアナログ回路周りのところが大体揃います。無線機の設計には電源とかも含むので、電源周りの知識などもつきます（実はこの本の電源周りの章は、筆者が理論的なベースを第４級アマチュア無線技士の試験対策で覚え、その後に色々実装して遊んでいた内容を元に書いています）。


なお、第四級アマチュア無線技士の試験対策書籍は、大きく分けて２種類あります。「第四級アマチュア無線技士用　アマチュア無線教科書（無線従事者養成課程用教科書）〔法規・無線工学〕」と、それじゃないやつです。

==== 第四級アマチュア無線技士標準教科書って？


第四級アマチュア無線技士の取得コースには２通りあって、試験を受けて通るコースと、養成課程を受けてそこで試験を受けて通るコースがあります。


この後者の養成課程で使われる教科書が、「第四級アマチュア無線技士標準教科書」です。


養成課程は２日の講習で資格を一気に取っちゃうコース(しかも無線の国家資格なので電波法関連の法規もある)なので、結果として内容がめちゃくちゃ簡単でして、それに伴ってこの標準教科書も大変見やすい(極めて平易に書いてあります)です。電子回路設計を始める際に０から学ぶなら、真っ先に読んでみていい内容です。内容が薄すぎるかもしれない懸念はありますが。


なお、養成課程は小学生ぐらいのキッズが普通に受講して受かる内容になっているそうです。

==== 第四級アマチュア無線技士標準教科書じゃないものって？


前項で出てきた「試験を受けて通るコース」の試験対策書籍になります。


これについては、色んな出版社からアマチュア無線技士国家試験の試験対策書籍が出ています。なお、ＣＱ出版社さんのが一番鉄板ですね（アマチュア無線の専門雑誌を出してる出版社さんなので）。こちらの試験対策書籍はちゃんと試験対策になるよう、ある程度しっかりした内容が展開され、結構歯ごたえもあります。ちゃんと学びたいならこっちもアリですね。


なお、アマチュア無線技士は第一級から第四級まであり、数字が少なくなるとどんどん難しくなります（かくいう筆者も第三級までしか持ってません。もうちょっと上のやつ受けたいのですが、いかんせん時間が取れず…）。

=== 経済産業省系　情報処理技術者関連

==== 情報処理技術者試験のITSSレベル1～3のやつ


マイコンボードやそういったソリューションが関わるシステムは、「エンベデッドシステム」と総称されがちですが、経済産業省もそういった資格試験制度を情報処理技術者試験として実施しています。エンベデッドシステムに関連する試験制度でいうと、やさしいものから順にITパスポート試験、基本情報技術者試験、応用情報技術者試験などがありますが、エンベデッドシステムに関するところはちょっとある……だけなので、マイコンを学ぶために使うという観点でいえば、あまり嬉しくないと筆者は考えています(ITの統合的な知識、判断力がつくことから遠回りに見えて近道、というのは事実としてあるので、業務レベルぐらいまでしっかりやりたいのであれば避けずにやったほうがいいのですが)。

==== エンベデッドシステムスペシャリスト試験


これ、電子回路メインの方にはどういう試験かよくわからないと思いますので、試験のHP@<fn>{エンベデッドスペ試験}から引用します。

//footnote[エンベデッドスペ試験][@<href>{https://www.jitec.ipa.go.jp/1_11seido/es.html, https://www.jitec.ipa.go.jp/1_11seido/es.html}]


//quote{
２．業務と役割
IoTを含む組込みシステムに関するハードウェアとソフトウェアの要求仕様に基づき、組込みシステムの開発工程において、開発・実装・テストを実施する業務に従事し、次の役割を主導的に果たすとともに、下位者を指導する。


　(1)　IoTを含む組込みシステムを対象として、機能仕様とリアルタイム性を最適に実現する @<em>{ハードウェアとソフトウェアのトレードオフ} に基づく機能分担を図り、設計書・仕様書の作成を行う。
//}


専門的でよくわかんない人も多いですよね……　@<em>{ハードウェアとソフトウェアのトレードオフ}　がこの試験の肝なんですけど、ちょっと難しい言葉なので平易な言葉に直すと、この試験は「ソフトの世界とハードの世界を（ソフトウェア側から）つなげられる」能力を求める内容になっています。


このため、エンベデッドシステムスペシャリスト試験の試験対策書籍は、組み込みに関するソフトウェア技術の基本的なところを学ぶのにピッタリです（逆に電子回路系は基本的なところと概念的な話が多く、実装観点でみると明らかに弱いので、回路として高度なことをやりたければ別の本が要るのですが）。

==== 電気工事士


電気工事士(2種)は電気系の登竜門的な資格ですが、電気の基本を学び、回路図や部品について知ったり、電気工作の基本を学ぶには適当な資格です。電子工作とは少し趣が違いますが…


@<href>{https://www.shiken.or.jp/, https://www.shiken.or.jp/}


また、少しステップアップして、100V電源を電子工作により制御するようになったりすると、ぜひ持っておきたいものです。コンセントから先を扱う場合なら資格が必須というわけではありませんが、知識としては必要だったり、危険ですからね。


試験は年2回ありますし、たくさん対策本、実技の工具セットなども売ってます。


なお、電気主任技術者試験も知識としては類似する部分もありますが、こちらはペーパーテストのみだったり、管理側、あるいは計算が多かったりと、少し趣が異なります。ですから、電子工作の先にある資格としては電気工事士をお勧めします。


ほら、ちょっと何か作れるようになったら、AC100Vを扱ってみたくなるじゃないですかー

== その他でこういう情報源もあるよ


他にも、色々と学べる月刊誌などもあります。代表的なところだけ触れておきましょう。

 * トランジスタ技術(CQ出版社) @<href>{https://toragi.cqpub.co.jp/, https://toragi.cqpub.co.jp/}



電子回路関連の専門誌ですね。真っ先に思い浮かべるのがこれ！って人も多いはず。月によっては付録がついてくる号もあったりします。

 * Interface(CQ出版) @<href>{https://interface.cqpub.co.jp/, https://interface.cqpub.co.jp/}



ラズパイなどのボードを用いて何かを作るとき、非常に参考になります。トラ技がアナログ回路を含む場合もあるのに対し、ほぼデジタルに限定している気がしますが、(広義の)マイコンを使った工作ならむしろ、Interfaceの方が刺さる記事が多いかもしれません。

 * CQ ham radio(CQ出版社) @<href>{https://ham.cqpub.co.jp/, https://ham.cqpub.co.jp/}



上で軽く触れていたアマチュア無線の専門誌です。電源とかラジオなどの設計だとこっちのほうが載ってるかな？

 * 月刊I/O(工学社) @<href>{https://www.kohgakusha.co.jp/io/, https://www.kohgakusha.co.jp/io/}



結構色んな話がごった煮的に載っていて、参考になります。記事毎の話の振れ幅が大きいので、端から端まで読んで楽しめるようになると、横断的な能力が大分身についた状態になってるんじゃないかな～という気がします。


自分にあった情報源をうまく使って、いろんな形で積み基板を消費して遊んでいけるといいですね。
