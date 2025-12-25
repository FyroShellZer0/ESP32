#include <Arduino.h>

void setup(){
    Serial.begin(9600); //! serial communication
}
void loop() {
  Serial.println("Hello World!"); //! new line print
  delay(5000);
}