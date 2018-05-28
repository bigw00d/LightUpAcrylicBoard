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

1. micronucles（ATTiny usb bootloader）をATTiny85に書き込む →[参考サイト](https://gist.github.com/Ircama/22707e938e9c8f169d9fe187797a2a2c)  

2. ArduinoIDEをインストール

3. Digisparkのボードパッケージ（Digistump AVR Board)をインストール

4. Windows7用のドライバをインストール

5. コード作成・書き込み
  

※[参考サイト：FT232RLでAVRライターを自作してATtiny85をDigispark互換にするまで](https://qiita.com/erukiti/items/0a51d959082e242e2e2a)  
※[参考サイト：[メモ] Digispark(ATTiny85) Arduino開発環境で、Lチカ](https://qiita.com/mt08/items/df4ed8c659b205d1fa1e)  
※Arduinoの代わりに[platformio](http://qiita.com/erukiti/items/74a848489ec102841b66)でもアプリケーションの開発はできると思います  

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

