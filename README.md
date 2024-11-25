# spdif-duplex
Linux driver providing SPDIF duplex CODEC

A device tree overlay to enable 8 channels of audio input and audio output.
A kernel device driver providing duplex SPDIF interface.

This only works on Raspberry Pi 5.

To build:

`make`

To install:

`make install`

Configure /boot/firmware/config.txt:

`dtoverlay=zyndaudio8x`

The soundcard must create bit clock and word clock. Bit clock should be connected to Rasberry Pi pin 12 (GPIO 18). Word clock should be connected to Raspberry Pi pin 35 (GPIO 19).

Connections
|GPIO|Pin|Description|
|-|-|-|
|18|12|Bit Clock|
|19|35|Word Clock|
|20|38|I2S In 1|
|21|40|I2S Out 1|
|22|15|I2S In 2|
|23|16|I2S Out 2|
|24|18|I2S In 3|
|25|22|I2S Out 3|
|26|37|I2S In 4|
|27|13|I2S Out 4|

