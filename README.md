# LED-Cassette-Tape

<https://www.instructables.com/Light-Up-the-Cassette-Tape-Get-Hyped-in-Rave-Parti/>

## arduino のインストール

<https://www.arduino.cc/en/software>

## 必要なライブラリのインストール

[FastLED](https://github.com/FastLED/FastLED)

## Digisparkのボード設定

<http://digistump.com/wiki/digispark/tutorials/connecting>

## FastLED色指定

<http://fastled.io/docs/3.1/struct_c_r_g_b.html>

## WEBカラーコード

<https://www.colordic.org/>

例：[fuchsia `#ff00ff`](https://www.colordic.org/colorsample/1125)　で光らせたい場合

`#ff00ff` →　`ff` `00` `ff`　二文字ずつに分けてそれぞれ頭に0x（ゼロエックス）をつけてカンマで区切る 

`0xff,0x00,0xff`

## わからないことがあったときの調べ方

* やりたいことを区切って検索する。検索結果がいまいちな時は、単語を翻訳ツールとかで英語に翻訳して検索する。
* 自分の使ってるPCのOSやマイコンボード、部品名、ライブラリ名を検索ワードに追加する
* エラーメッセージをコピペして検索結果がゼロの場合はメッセージの一部分だけ、みたいに検索する部分を変えて検索してみる。

例：

* arduino インストール　やり方 Windows
* arduino ライブラリ インストール
* Fastled サンプルコード
* WS2812　arduino ○○できない

## コード何回見直しても間違えてないっぽいのにエラーが出てコンパイルできない時

全角のスペースがコメントアウト部分以外に入っていたり、プログラムで必要な記号（特に末尾のセミコロン`;`とかコピペで最後の`}`をコピーし忘れてないか
確認する。そういうときはだいたい下のエラーが出るからいったんお茶とか飲んで落ち着いてから探すといいよ。

```plaintext
exit status 1
stray '\343' in program
```

### コンパイルしたときに`#include EEPROM.h`の部分にエラーが出る場合

下記リンクを開いて

<https://github.com/digistump/DigistumpArduino/issues/34>

ページ内のEEPRPM.zipをダウンロードして、ArduinoIDEのスケッチ→ライブラリをインクルード  
→zip形式のライブラリをインストールでEEPRPMをインストールしてからコンパイルする
