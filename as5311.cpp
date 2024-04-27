// =========================HEADER=============================================================
/*
   Arduino Uno/Nano/328p Hardware Setup
   
            Quadrature inputs from AS5311

            Quad A --------------------  D2
            Quad B --------------------  D3
                    
//============================================================================================
*/
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#include <U8glib.h>

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);

char Reading[9];

Encoder Encoder1(2, 3);

void setup() {
  Serial.begin(9600);
}

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 20); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print(Reading);
}

void loop() {
 
    long position = Encoder1.read();
    float mm = (float)position/512.000; 

    // using the dtostrf function below since this sets the number of decimal places for either metric or imperial readings
    dtostrf(mm,7,3,Reading);


    draw();
   
    Serial.println(mm);
    delay(500);    
}
