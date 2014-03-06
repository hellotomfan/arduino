#include "U8glib.h"
#include "Arduino.h"
#include "anmi.h"

U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, CD = 9, RST = 8

void setup(void) 
{
	u8g.setRot180();// rotate screen, if required
}

void loop(void) 
{
	for (uint8_t x = 0; x < 128; ++x)
	{
		uint8_t y = sin(x/12)*10+1;
		u8g.firstPage(); 
		do {
			u8g.drawBitmapP(x, y, 6, 48, BirdAnmiUp);
		}
		while( u8g.nextPage() );
		delay(200);
	}
	delay(500);
}
