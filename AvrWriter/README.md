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
* 各種電子部品（準備中）

## Usage

1. USBシリアルなどのAVRを使ってattiny85に[micronucleus](https://github.com/micronucleus/micronucleus)を焼きます
※MACでやっている。Windowsでも同じようにすればいい？
2. 以下のどちらかの方法でスケッチを焼きます（Digisparkと同じように）<br>
2-1. [platformio](http://qiita.com/erukiti/items/74a848489ec102841b66)でスケッチを焼きます<br>
2-2. Digisparkと同じように[Arduino](https://qiita.com/mt08/items/df4ed8c659b205d1fa1e)でスケッチを焼きます<br>

※[参考サイト](https://qiita.com/erukiti/items/0a51d959082e242e2e2)  
※[参考URL（Digispark&Arduino）](https://qiita.com/mt08/items/df4ed8c659b205d1fa1e)  

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

