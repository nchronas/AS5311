// =========================HEADER=============================================================
/*
   Arduino Uno/Nano/328p Hardware Setup
   
            Quadrature inputs from AS5311

            Quad A --------------------  D2
            Quad B --------------------  D3

            1.3" 128x64 SSD1306 OLED Display on I2C bus         
                    
//============================================================================================
*/
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#include <U8glib.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);

char Reading[9];

Encoder Encoder1(2, 3);

void setup() {
  Serial.begin(9600);
  u8g.begin(); 
  u8g.setFont(u8g_font_p01type);
}

void loop() {
 
    long position = Encoder1.read();
    float mm = (float)position/512.000; 

    // using the dtostrf function below since this sets the number of decimal places for either metric or imperial readings
    dtostrf(mm,7,3,Reading);

    u8g.drawStr(0,28,"Y");
    u8g.drawStr( 24, 28, Reading);
    u8g.drawStr( 110, 28, "mm");

    Serial.println(mm);
    delay(50);    
}
