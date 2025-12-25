#include <Arduino.h>

void setup() { //! setup() runs once when esp32 starts
    Serial.begin(115200); //! start serial communication
    pinMode(2, OUTPUT); //! set gpio2 as output

}
void loop() {
    digitalWrite(2, HIGH); //! ON
    delay(50);
    digitalWrite(2, LOW); //! OFF
    delay(50);
}