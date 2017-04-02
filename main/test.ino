#include <Arduino.h>
#include <PLDuino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World");
  
  // Set pin modes and initialize stuff
  // NB: This line is necessary in all sketches which use PLDuino library stuff.
  PLDuino::init();
}

void loop() {
    byte inputByte = getInputByte();
    int MatrixLength = 9;
    byte OutMatrix[MatrixLength] = {
      B00000001,
      B00000010,
      B00000011,
      B00000100,
      B00000101,
      B00000110,
      B00000111,
      B00001000
    };
    
    for(int i = 0; i < 8; i++){
        digitalWrite(38+i, bitRead(inputByte, i) == 1? HIGH : LOW);
    }
}

byte getInputByte(){
  byte tempByte = B000000;

  for(int i; i < 8; i++){
    bitWrite(tempByte, i, digitalRead(37-i));
  }

  return tempByte;
}



