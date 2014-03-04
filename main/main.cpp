#include "U8glib.h"
#include "Arduino.h"

U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, CD = 9, RST = 8
 
void draw(void) {
  static uint8_t i = 0;
  // graphic commands to redraw the complete screen should be placed here 
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 20, 35, "hello world");
}
 
void setup(void) {
  u8g.setRot180();// rotate screen, if required
}
 
void loop(void) {
  // picture loop
  u8g.firstPage(); 
  do {
    draw();
  }
  while( u8g.nextPage() );
 
  // rebuild the picture after some delay
  delay(500);
}
