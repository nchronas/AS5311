
// Quadrature inputs from AS5311

// Quad A --------------------  D2
// Quad B --------------------  D3

// Units Switch --------------  D4 

#include <Encoder.h>


// Switch debounce counters
long lastDebounceTime1 = 0;
long oldPosition = -999;
long newPosition = 0;

char Reading2[9];

Encoder Encoder1(2, 3);

void setup() {
  
 pinMode(5,INPUT);    // push button to zero display count  
 
}

void loop() {
 
    // check pin 5                    // Zero display count
    if(digitalRead(5) == LOW){
       if ((millis() - lastDebounceTime1) > 200) {
        lastDebounceTime1 = millis();
        Encoder1.readAndReset();
       }
    }
 
    newPosition = Encoder1.read();
    if (newPosition != oldPosition) {
        oldPosition = newPosition;
    }
    mm = (float)newPosition/512.000; 

    // using the dtostrf function below since this sets the number of decimal places for either metric or imperial readings
    dtostrf(mm,7,3,Reading2);

    serial.println(mm);
    delay(50);    
}
