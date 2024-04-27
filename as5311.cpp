// =========================HEADER=============================================================
/*
   Arduino Uno/Nano/328p Hardware Setup
   
            Quadrature inputs from AS5311

            Quad A --------------------  D2
            Quad B --------------------  D3

            2.2" SSD1305 OLED Display on SPI bus
            
            SCK    --------------------  D13
            MOSI   --------------------  D11
            CS     --------------------  D7
            D/C    --------------------  D6
            RST    --------------------  D8
            
            Units Switch --------------  D4
            Zero Switch ---------------  D5           
                    
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

void u8g_prepare(void) 
{
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

void loop() {
 
    long position = Encoder1.read();
    float mm = (float)position/512.000; 

    // using the dtostrf function below since this sets the number of decimal places for either metric or imperial readings
    dtostrf(mm,7,3,Reading);

    // u8g.drawStr(0,28,"Y");
    // u8g.drawStr( 24, 28, Reading);
    // u8g.drawStr( 110, 28, "mm");

    u8g_prepare();

  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(2, 19, "Welcome");
  u8g.drawStr(2, 38, "to");
  u8g.drawStr(2, 57, "Mybotic :)");

    Serial.println(mm);
    delay(50);    
}
