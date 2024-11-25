# spdif-duplex
Linux driver providing SPDIF duplex CODEC

A device tree overlay to enable 8 channels of audio input and audio output.
A kernel device driver providing duplex SPDIF interface.

This only works on Raspberry Pi 5.

To build:

`make`

To install:

`make install`

The soundcard must create bit clock and word clock. Bit clock should be connected to Rasberry Pi pin 12 (GPIO 18). Word clock should be connected to Raspberry Pi pin 35 (GPIO 19).