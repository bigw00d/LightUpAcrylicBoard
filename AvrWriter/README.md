Making Avr Writer
====

AVRマイコン(ATTiny13A, ATTiny85など)書き込み装置を作る方法を記載しています。

## Description

ここで作成するAvrWriter（AVRマイコン書き込み装置）は以下のような機能を持っています

- Digisparkと同等の回路を保持
    - USBシリアルなしでATTiny85にプログラミングできます

- 各種電圧を取り扱い可能
    - 各種レギュレータを使えます
    - USB電源をそのまま使うこともできます

- WROOM02との高い親和性
    - WROOM02の[ピッチ変換済みモジュール](https://www.switch-science.com/catalog/2347/)用のピン穴があります
    - [EsprDeveloper](https://www.switch-science.com/catalog/2500/)用のピン穴があります
    - Attiny85をUSBシリアル化できればWROOM02の書き込みもこの基板で可能です

- FRISKケース台の基板サイズ
    - ただし、レギュレータを使用する際ははみ出る気がします

## Requirement

* USBシリアル
* Windows PC
* AvrWriter基板
* 各種電子部品
  * ツェナーダイオード（GDZJ3.6B）x2  
  * 低電圧ショットキーダイオード（SBM1045VSS）x1  
  * 抵抗（1.5kΩ） x1
  * 抵抗（68Ω） x2
  * コンデンサ（4.7uF） x1
  * コンデンサ（0.1uF） x1
  * ジャンパーピン x2
  * 三端子レギュレーター（5V1A NJM7805FA） x1  
  * LED x2　※BETTER  
  * LED用の抵抗（68Ω） x2　※BETTER
  * WROOM02ピッチ変換済みモジュール用のピンソケット（1x8） x2　※BETTER
  * EsprDeveloper用のピンソケット（1x10） x2　※BETTER

## Usage

1. micronucles（ATTiny usb bootloader）をATTiny85に書き込む  
   1-1. ArduinoIDEをインストールする  
   1-2. ArduinoNanoにArduinoISPを書き込む(AruidnoIDEの「ファイル」→「スケッチの例」→「ArduinoISP」)  
   1-3. ArduinoNanoとAttiny85を結線します    
```
                                                ╔═══════════════╗
           ╔═════════════════════════╗          ║               ║
           ║                       SS╬──────────╬1              ║
           ║                      GND╬──────────╬4   Attiny85   ║
           ║          Arduino    MOSI╬──────────╬5              ║
           ║          Nano       MISO╬──────────╬6              ║
           ║                      SCK╬──────────╬7              ║
           ║                       5V╬──────────╬8              ║
           ║                         ║          ║               ║
           ╚═════════════════════════╝          ╚═══════════════╝
```
   1-4. avrdude.exe、avrdude.conf、libusb0.dllをArduinoIDEのファイル群から取ってきます  
   1-5. micronucleusをArduinoIDEのGitHubから取ってきてt85_default.hexを取り出します（ZIP解凍してmicronucleus-master\firmware\releases）  
   1-6. avrdude.exe、avrdude.conf、t85_default.hex、libusb0.dllを1つのフォルダに入れます    
   1-7. 1-6のフォルダにコマンドプロンプトで移動してAttinyと接続します（以下のようにavrdudeコマンドを入力）    
   　　　※COM6は各自のArduinoNanoのCOM番号を指定してください  
```
C:\temp\WriteAttinyBootloader>avrdude -c avrisp -P COM6 -b 19200 -p t85

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.09s

avrdude: Device signature = 0x1e930b (probably t85)

avrdude: safemode: Fuses OK (E:FF, H:DF, L:62)

avrdude done.  Thank you.
```
   1-8. Attinyにブートローダを書き込みます（以下のようにavrdudeコマンドを入力）  
   　　　※ヒューズの書き換え  
   　　　※適当に書き換えることはできません！！！！  
   　　　※最悪の場合、専用の装置が無いと復帰できないレベルの問題が起きます！！！！  
   　　　※自己責任でお願いします。  
```
C:\temp\WriteAttinyBootloader>avrdude -c avrisp -P COM6 -b 19200 -p t85 -U flas
:w:t85_default.hex -U lfuse:w:0xe1:m -U hfuse:w:0x5d:m -U efuse:w:0xfe:m
```

2. Digistump AVR BoardをArduinoIDEのボードマネージャーに読み込ませる  
   2-1. [ファイル]=>環境設定(CTRL+Comma)で、環境設定メニューを開く  
   2-2. Adittional Boards Manager URLs: に http://digistump.com/package_digistump_index.jsonを追加して、[OK]を押す  
   2-3. TypeのドロップダウンメニューからContributedを選択。するのだが、初回時でないので、一回ボードマネージャーのウィンドウを閉じて、もう一回開く  
   2-4. Contributedをえらぶと、Digistump AVR Boards by Digistumpというのがあるのでそこをクリック、[インストール]ボタンが出るので押して、インストールが終わったら[閉じる]。  
   2-5. [ツール]=>マイコンボード:から、Digispark (Default - 16.5mhz) を選択  

3. Windows7用のドライバをインストールする  
   3-1. Digistump AVR Boardsパッケージをインストールすると、 %USERPROFILE%\AppData\Local\Arduino15\packages\digistump\tools\micronucleus\2.0a4 あたりにinfがあるのでそいつを指定して手動でドライバをいれる。  

4. コード作成・書き込み
  
※[参考サイト：ArduinoでHEXファイルを書き込む](http://blog.livedoor.jp/hymne333/archives/4710525.html)
※[参考サイト：FT232RLでAVRライターを自作してATtiny85をDigispark互換にするまで](https://qiita.com/erukiti/items/0a51d959082e242e2e2a)  
※[参考サイト：[メモ] Digispark(ATTiny85) Arduino開発環境で、Lチカ](https://qiita.com/mt08/items/df4ed8c659b205d1fa1e)  
※[参考サイト](https://gist.github.com/Ircama/22707e938e9c8f169d9fe187797a2a2c)   
※ArduinoIDEの代わりに[platformio](http://qiita.com/erukiti/items/74a848489ec102841b66)でもアプリケーションの開発はできると思います  

## Demo

LED(PROG_LED)を点滅させるデモがあります → ATTin85_LED_BLINK（準備中）

## Licence

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

