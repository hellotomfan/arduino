#!/bin/bash
avr-objcopy -O ihex main/main main.hex
avrdude -V -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:main.hex:i
rm main.hex
