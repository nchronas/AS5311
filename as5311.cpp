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

long position = 0;

Encoder Encoder1(2, 3);

void setup() {
   Serial.begin(9600);
}

void loop() {
   
    position = Encoder1.read();
    float mm = (float)position/512.000; 

    Serial.println(mm);
    delay(50);    
}
