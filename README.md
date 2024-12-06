# zynaudio8x
Provides requirements to enable zynthian 8 channel I2S soundcard.

A device tree overlay to enable 8 channels of audio input and audio output.
A kernel device driver providing duplex SPDIF interface.

This only works on Raspberry Pi 5.

## Dependencies:

```
apt-get install build-essential linux-headers-$(uname -r)
```

## Build:

`make`

or optionally pass a kernel name to build against a specific kernel:

`make kernel=6.6.62+rpt-rpi-2712`

## Install:

`make install`

Configure /boot/firmware/config.txt:

`dtoverlay=zynaudio8x,inputs=4,outputs=2`

`inputs` and `outputs` are optional parameters that limit the quantity of input (capture) and output (playback) ports. Range 0..8 and must be even. Invalid values will default to 8.

The soundcard must create bit clock and word clock. Bit clock should be connected to Rasberry Pi pin 12 (GPIO 18). Word clock should be connected to Raspberry Pi pin 35 (GPIO 19).

## Connections
|GPIO|Pin|Description|
|-|-|-|
|18|12|Bit Clock|
|19|35|Word Clock|
|20|38|I2S 1 In|
|21|40|I2S 1 Out|
|22|15|I2S 2 In|
|23|16|I2S 2 Out|
|24|18|I2S 3 In|
|25|22|I2S 3 Out|
|26|37|I2S 4 In|
|27|13|I2S 4 Out|

