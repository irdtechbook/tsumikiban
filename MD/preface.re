= はじめに

== この本の目的

積み基板とは何でしょう？本書では、何かを作ろうと思ったけど挫折した、あるいは何となく/とりあえず買った基板たちを指します。家に1枚や2枚、あるいはもっと、そういった基板が転がってたりしませんか？

世の中には、ArduinoやRaspberryPiをはじめとして、様々な魅力的なボードがあふれています。価格もお手頃で、数百円から数千円程度で様々な機能を持つボードが手に入る世の中になりました。でも、なぜ手元には使われていない「積み基板」が残るのでしょうか？とりあえず買っちゃう？作りたいものがない？それでも買ってしまう？作りたいものがあっても挫折しちゃう？…様々な理由があるでしょう。

本書では、そういった状況を解きほぐし、作りたいものを探す、あるいは挫折しないためのテクニックを解説してみることにしました。

ソフトウェア開発の界隈では広く市民権を得てきたアジャイル開発の方法論を一部取り入れてみる、作りたいものを定義する、知っておくべきことは知っておく、電子工作における基礎知識、作例に触れてみる、様々なノウハウが集まりました。一方で、具体的な環境、特定のボードに関する記述はほとんどありません。回路図やコードに関する記述もほとんどありません。そういった内容は、本書のスコープ外です。他に素晴らしい本がたくさんありますので、そちらを参照ください。

あなたのおうちの積み基板たちに、再度注目してみてください。これをきっかけとして、何か新しいモノづくりを始める方がいれば幸いです。

寄稿いただきました著者の皆様ありがとうございます。おかげで入門書としても素敵な本ができました。積み基板というキーワードに刺さる皆様からの寄稿でした。改めてお礼申し上げます。

表紙は湊川あい@llminatollさんに今回もお願いしました。ちょっと渋い顔をしつつ、積み基板に囲まれたワンストップくんちゃんです。この本が書きあがった暁には、きっと晴れ晴れした顔になることでしょう。

それでは、あなたの電子工作ライフが実り多きものになりますよう。その一助になりましたら幸いです。

//flushright{

2021年12月

編集長　親方＠親方Project　拝

//}


== 免責事項

 * 本書の内容は、情報提供のみを目的としております。著者一同、正確性には留意しておりますが、正確性を保証するものではありません。この本の記載内容に基づく一切の結果について、著者、編集者とも一切の責任を負いません。
 * 個別の事象についてのアドバイス・サポート等はお受けできません。あくまで著者の体験を記述しているものであり、一般に適合しない事例もあります。
 * 会社名、商品名については、一般に各社の登録商標です。TM表記等については記載しておりません。また、特定の会社、製品、案件について、不当に貶める意図はありません。
 * 本書の一部あるいは全部について、無断での複写・複製はお断りします。
