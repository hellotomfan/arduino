#include "Arduino.h"
#include "U8glib.h"

U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, CD = 9, RST = 8

int get_key(unsigned int input)
{   
    if (input < 100) return 0;
    else  if (input < 300) return 1;
    else  if (input < 500) return 2;
    else  if (input < 700) return 3;
    else  if (input < 900) return 4;    
    else  return -1;
}

const char *get_key_name(int x)
{
    if (x == 0) return "left";
    else  if (x == 1) return "select";
    else  if (x == 2) return "down";
    else  if (x == 3) return "right";
    else  if (x == 4) return "up";    
    else  return "null";
}


void setup()
{
	u8g.setRot180();// rotate screen, if required
	pinMode(7, OUTPUT);
}
void loop()
{
	int val = get_key(analogRead(0));
	if (val == -1)
		digitalWrite(7, LOW);
	else
		digitalWrite(7, HIGH);
	const char *str = get_key_name(val);
	u8g.firstPage();
	do  {
		u8g.setFont(u8g_font_unifont);
		u8g.drawStr(45, 35, str);
	} while( u8g.nextPage() );
}
