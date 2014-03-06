#!/bin/bash

MODEL=atmega328p
DEVICE=/dev/ttyACM0
RATE=115200

if [[ "$1" != "" ]]; then

	if test -e $1/$1; then
		avr-objcopy -O ihex $1/$1 $1.hex
		avrdude -V -p$MODEL -carduino -P$DEVICE -b$RATE -D -Uflash:w:$1.hex:i
		rm $1.hex
	else
		echo "$1 not found!"
	fi
else
	echo "$0 <upload_file>"
fi
