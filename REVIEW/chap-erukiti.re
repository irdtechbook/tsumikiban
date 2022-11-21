= さぁ、お前の罪（基板）を数えろ！


erukiti


ここ2年くらいは電子工作をしてなくて、今更、罪基板の数なんて数え切れんわ！ってなってるerukitiと申します。そんな僕が寄稿するのもどうかと思いますが、何か参考になることがあればと思い、筆ならぬキーボードを取った次第です。

== about me


erukitiと申します。所持してるラズパイは無数です。ストックしてるマイコンも無数です。

 * Raspberry PI zero 無数
 * Raspberry PI 4 x2
 * Raspberry PI 3 n個
 * Raspberry PI 2 n個
 * Raspberry PI n個
 * 罪マイコン 無数



さて、この本は積み基板というテーマなので、僕が電子工作をやっていた頃を思い出しながら、話を整理してみます。

== モチベーションを整理する


僕はソフトウェアエンジニアで、ソフトウェアはあれこれ触るものの、ソフトウェアだけだと実世界に干渉しづらいという問題があります。二酸化炭素濃度や気温・湿度を取得したいといったものです。


こういう事例では目的がはっきりしているので、あとは、ちょうどいいセンサーがお手頃な価格で買えるか？とか、そのセンサーの精度はどれくらいなのか？とか、センサーを読み取るための方法のような技術的問題だったり、やるための時間・気合いの話になることでしょう。気温や湿度程度なら、そもそも電子工作不要の製品でなんとかなるでしょう、たぶん。


あるいは、最近は自作キーボード界隈が盛り上がっていることもあって、皆様の手元にも組み立てがまだの自作キーボードがあったりするかもしれませんが、早いところ組んでしまいましょう。はんだづけするだけです。簡単ですね！


ブレッドボードや部品がいっぱい積まれてる程度なら、置き場所問題が生じるほど大量に仕入れないかぎりは、そうそう罪の意識を覚える必要もありません。それはもう経費というか、電子工作をやってくうえで必要なものなので、個別に数え上げる必要もないでしょう。


しかし、積み基板のうち「何かに使えると思って買っておいた系」が一番、罪の意識に苛まれやすいと思います。ついつい新しいラズパイが出たから買うみたいなムーブをキメてる人も多いでしょう。もっと安いマイコンであれば、値段ゆえにたぶんそんなに罪の意識は沸かないはずですが、ラズパイあたりは値段がある程度しちゃう上に、マイコンなんてレベルの性能ではなく、もう普通にコンピュータとして使えるレベルなので、より罪の意識を覚えることでしょう。


そこで、手っ取り早く罪を軽減するために、ラズパイを見渡してみましょう。

== ラズパイの罪を軽減する


ラズパイは汎用的に使えすぎてしまうのです。特にRaspberry PI 4なんて高性能すぎるのです。その対極にある Raspberry PI zeroは小さくて、ワンコイン@<fn>{erukiti-onecoin}という、これまた夢が広がるデバイスです。

//footnote[erukiti-onecoin][ほとんど入手できませんでしたし、莫大な送料がかかったりして実質コスパはあまりよくなかったですが]


ラズパイに関しては、色々な人が記事や本を書いているので、ラズパイの使い方はぜひ色々調べてみてほしいところですが、ここではいったんラズパイの罪を軽減する方法に絞って書いてみます。


ラズパイは「なんでも使える」ので、いっそそれを逆手に取って、トラブルシューティングやいざというときの備えのためにセットアップをしておくと、罪の意識を軽減しつつ安心感を得られるのではないでしょうか。

=== ウェブ向け動作検証端末


僕はウェブ開発をしていて、日頃使っているMacはApple Silicon@<fn>{erukiti-mac}というとても高速なチップを使っているせいで、ブラウザの速度に対する感覚がとても鈍るという問題があります。Macに限らずウェブ開発あるあるなんですが、開発者のマシンはスペックが高めなので、一般的なユーザーと性能の乖離が生じる危険性があるのです。Chrome Devtoolsの速度スロットリングなどで、擬似的に重い環境を作る方法もありますが、別マシンを用意してしまうといいでしょう。

//footnote[erukiti-mac][仕事ではApple M1で、プライベートではApple M1 Maxを使っています。]


そうです。我らが愛すべきラズパイです。ラズパイはマイコンと呼ぶには高性能すぎるとはいえど、搭載メモリ量やCPUスピードはさすがに一般的なPCよりは下回ります。そこでラズパイにUbuntuを入れてブラウザが動くようにしておけば、動作検証端末として使えるわけです。

 * HDMIでディスプレイにつながるようにしておく
 * USBのキーボード・マウスを用意しておく（安物でOK）
 * Ubuntuをインストールしてデスクトップとブラウザが問題なく動くように設定しておく



こういった環境がそろっていれば、それなりに便利です。

=== Docker/k8s練習機


いまどきの開発シーンでは、当たり前のようにDocker@<fn>{docker}やk8s@<fn>{k8s}が使われています。これらはインフラエンジニアや、インフラよりの開発者が触るツールです。


Dockerもk8sも仮想マシン上に構築されることも多いですが、ラズパイでDockerやk8s（やk3s）なんかを動かしてみるというのも、面白いテーマでしょう。

//footnote[docker][仮想マシンよりも軽量なコンテナと呼ばれる技術です。コンテナをうまく活用すれば誰でも同じ環境で安定して動かすことができるため、昨今では開発環境では大体Dockerを使い、本番運用もDockerベースになっていることが多くなりました。]

//footnote[k8s][Kubernetesの略称です。@<code>{k}と@<code>{s}の間に8文字入っているからk8sです。元々はGoogleの分散コンピューティング基盤Borgをベースに、OSSとして登場したものです。イケてる会社だと大体採用されてるようなインフラ技術だと思っていただければ大体合っています。]


x86とは違うがゆえの苦労もありますが、最近だとMacがARMになったり、ARMがデータセンターでも少しずつ使われてきて、今後増えるのは間違いないので、手元にM1 MacのようなARMマシンを持ってない人がARMでの環境構築の練習をするのには、うってつけではないでしょうか。

=== ネットワークトラブルシューター


ラズパイにはEthernetとWiFiが載っていて、USBデバイスも繋げられるとなると、ネットワーク機器としても十分活用できるはずです。ラズパイをご家庭用DHCPサーバとかルーターに使われる事例は割と聞きます。


まあ普通は市販のルーターか、レンタルのルーターを使ってインターネットに接続していることでしょう。ただ、ネットワークトラブルというのは想像してないようなタイミングで襲いかかってくるものです。


クレカの更新期限がきて面倒で放置してたら請求書払いになっていて、支払いを忘れてたらネットが止まる経験を皆さんもしていることでしょう。あるいは広域のネットワーク障害が出たりすることもあれば、家族がルーターのコンセントを引っこ抜いてお掃除してることもあるはずです。夏なんかに熱により暴走することもあれば、故障することもまあありえる話です。


いざというときにルーターとして使えるようにしておけば、ルーターが壊れても安心です。

=== NASとして使う


Raspberry PI 4なんかは、Gigabit EthernetやUSB-3が使えるため、NASとして使う話もちらほら聞きました。USB-SSDとモバイルバッテリなんかを使えば、いつでもどこでも使えるNASに早変わりです。

=== ROMライターとして使う


やっと電子工作っぽい用途です。


ROMライタの回路はブレッドボードでも小さくて安い基板でもいいですが用意しておき、テストワイヤーでラズパイをつないで、ラズパイからROM用のデータを流し込むだけです。


Raspberry PIはPCと同じように使えるだけでなくて、GPIOから入出力が可能なので、電子工作のお供としてとても便利なのです。
