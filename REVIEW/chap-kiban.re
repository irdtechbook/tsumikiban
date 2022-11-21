= 基板を起こしてみる


少し何かを作ってみたら、基板を起こしてみましょう。昨今、「基板を作る」こと自体のハードルはかなり下がりました。費用も安いですし、使いやすい基板CADもあります。

== 「基板を起こす」とは？


プリント基板自体を作ることを、基板を起こす、という表現を使います。自分で設計したオリジナルのプリント基板を作ってもらうことをさします。趣味の電子工作においては、費用や制作日数、費用や費用、そして費用の関係で、99％は中国の会社に発注することになります。


基板を起こすこと自体、ハードルが高いように思われるかもしれませんが、今や数センチ角の基板10枚で送料込み1000円程度から作ることができ、その出来栄えも趣味レベルなら十二分です。製造自体も数日、輸送も入れて10日や2週間程度で十分に届きます。


1000円で作れるとしたら…ブレッドボードより安いくらいです。ブレッドボード自体はとても便利ですが、ずっと使うには向きません。あくまでプロトタイプ、試行錯誤用だと考えた方がよいでしょう。

=== 基板を起こすメリット


基板を起こすメリットはいくつもあります。

 * 信頼性が向上する



プリント基板は、はんだ付けまたはコネクタで接続しますので、接触不良が起こりづらくなります。もちろんはんだ不良はあるのですが、ブレッドボードよりもよほど安心して使えるでしょう。結果、変な不具合や動作不良などが生じづらくなります。接触不良および接触不良による通信不良は、わかりづらいうえに原因の究明がきわめて困難な場合が少なくありません。プリント基板であっても、芋はんだをはじめとしたはんだ不良やはんだ付けの失敗や加熱しすぎによる部品の故障などが起こらないわけではないですが、それでもブレッドボードよりよほど信頼性が高いです。


また、ある程度以上の規模になってくると、配線がぐちゃぐちゃとしてきて、ミスが増えやすくなります。配線ミス、間違えて抜いてしまった、ショートした、ピンが折れた、などなど。


最初の試行錯誤には必要な場面もありますが、ハードウェアの実装が終わってしまえば、結線をやり直す必要はありません。そんなとき、基板に作りこんでしまうことで、その後のソフト部分の開発に専念することができます。


また、そのときにミスが見つかったとしても、パターンをカットしたり、改造する部分だけをブレッドボードに取り出したりといった対応をとって、ハイブリッドで開発を進めることもできます。

 * 回路への理解が深まる



自分で基板を起こすことで、おまじないのように入れていた電流制限抵抗やパスコンについて思いを馳せることができるかもしれません。おまじないは相変わらずおまじないかもしれませんが。それでも、設計として現物を入れる、あるいは入れ忘れて動作が不安定になるといったところを確認しながら進めることができます。


また、自分で作った回路ですから、信号の流れや処理の流れが明確にわかります。ブレッドボードでもわかるでしょうが、見た目が大幅に整理されます。

 * コンパクトになる
プリント基板では、配線は基板内に作りこまれます。ですから（ミスによるパッチを除き）配線を自分でする必要がなくなります。ブレッドボードでは、5列が同一の電極につながっていますが、そのため、比較的小規模な回路でも、全体は案外大きくなってしまいます。接点の信頼性も含め、基板化することのメリットは大きいでしょう。
 * はんだ付けが簡単
リード線同士のはんだ付けは案外大変です。クリップ等での接続も信頼性の問題がありますが、リード線同士、あるいはリード線と部品の足のはんだ付けは、空中でやるにせよ、なんらか固定してやるにせよ、コツと経験が必要です。



プリント基板であれば、表面実装はともかく、DIPタイプのICや、リード部品などは、指定の穴にさしてはんだ付けをすることができ、非常に簡単です。はんだ付けが終わったら不要な足は切っておきましょうね。


表面実装のICのはんだ付けは別のノウハウが必要ですが、スルーホールに取り付けるタイプのICや抵抗などであれば比較的簡単にはんだ付けができます。

 * 基板を起こすというノウハウが手に入る
基板を起こすということそのものにいろいろノウハウがあります。基板CADの使い方、プリント基板会社の選定、デザインルールなどなど、様々な経験を得られます。いまなら1種類数百円から作ることもできます。数百円といえば、ブレッドボードやユニバーサル基板を買うのと同じくらいの気軽さで作れます。



部品の配置の制約の自動チェックや、自動配線、また部品ライブラリの充実など、非常に使いやすくなっています。

=== 基板を起こすデメリット


デメリットがないわけではありませんが、比較的小さいですね。

 * 基板制作のリードタイム



中国メーカーに発注して、届くまでには1週間～2週間くらいはかかります。即日発送みたいな会社もあるにはありますが、輸送でやっぱり1週間以上はかかります。


その間進められないのは、ちょっと痛いですね。


また、明日までに！プリント基板が！1枚！欲しいんだ！といった状況には太刀打ちできません。そのときはおとなしくユニバーサル基板かブレッドボードでやりましょう。そんなシチュエーションはあまりありませんが（あるいは、計画性という別の問題が生じますね）。

 * ミスの切り分けがしにくい



うまく動かなかったとき、原因が作ったプリント基板にあるのか、そのほか（デバイス、素子、ソフト）にあるのかの判定が付きづらくなります。もっとも、接触点の数が圧倒的に減るため、トータルとしては、基板を起こしてしまった方がいい場合も多いと考えます。


また、プリント基板はプロービング(テスタやオシロのプローブを当てること)が大幅に楽になるというメリットもあります。プリント基板にミスがある可能性もありますが、その切り分けをすることも楽しいことです。

 * ミスの修正/回路の変更がしづらい
作ってしまった基板を修正することは容易ではありません。もちろんできないことはないのですが、パターンカットやジャンパー線を使って回路の修正が必要です。いっそ作り直してしまった方が楽かもしれません。たいていのミスは、できあがってから見つかるもの。そんなときは、あきらめてもう一度作りましょう。積み基板がまた増えますね！
 * 5枚10枚の積み基板ができる
プリント基板は、1枚作るのも10枚作るのもほとんどコストは変わりません。本来は量産用です。また、メーカーも10枚の発注に対し1枚2枚の「予備」をつけてくれることもあります。でも、個人で10枚全部使うことは稀ですよね。結果として、また積み基板が増えることになります。やったね！


== どうやって基板を起こす？


基板を起こすには、ということで、解説をしてもよいのですが、それを書き記すには余白が狭すぎます。


とりあえず、トランジスタ技術（トラ技）を読んでみてください。年に1回程度、基板の作り方特集の回があります。あるいは、トラ技スペシャルという特別号で基板製作の一通りの解説をしていることもあります。たとえば、「KiCad×LTspiceで始める本格プリント基板設計［DVD付き］(TRSP No.142)」など、ぜひ探してみてください。


あとは、実際に回路を作って、中国メーカーに発注するだけです。なお、まずは一回小さい基板で何かを作ってみることを強く強くお勧めします。なんらかの失敗があっても、規模が小さければリカバリーも容易です。お財布への影響も小さくて済みます。それでいて、基板CADの操作の練習やライブラリの使い方、部品登録の仕方などを練習することができます。
