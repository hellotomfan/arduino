#include "U8glib.h"
#include "Arduino.h"
#include "anmi.h"

U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, CD = 9, RST = 8

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

//unsigned char tmp [ 48 * 48 ] PROGMEM = {0x0};

float wrapPi(float theta)
{
	theta -= floor(theta * k1Over2Pi) * k2Pi;
	return theta;
}

void setup(void) 
{
	u8g.setRot180();// rotate screen, if required
}
void loop(void) 
{
	const unsigned char *bitmap = NULL;
	for (int8_t x = -48; x < 128 - 8; x += 8)
	{
		const float a = 5.5f;
		const uint8_t b = 2;
		const uint8_t c = 12;
		uint8_t y = sin(x/a) * b + c;

		float theta = wrapPi(x/a);
		if (theta >= kPiOver2 && theta < 3 * kPiOver2)
			bitmap = BirdDown;
		else
			bitmap = BirdUp;

		u8g.firstPage(); 
		do {
			u8g.drawBitmapP(x, y, 2, 16, bitmap);
		}
		while( u8g.nextPage() );
		delay(500);
	}
}
