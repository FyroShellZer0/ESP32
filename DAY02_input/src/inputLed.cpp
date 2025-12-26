#include <Arduino.h>
#include <stdbool.h>
bool On = false;
void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  Serial.println("Esp32 ready!, type something...");

}
void loop() {
  
  if(Serial.available()){ 
    Serial.print("Enter: ");
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if(input.length() > 0){ //string check
     Serial.print("you typed: ");
     Serial.println(input);
     if(input == "1"){
       On = true;
     }
     else{
       On = false;
     }
    
    }
  }
   
    if (On == true){
      Serial.println("Turning on...");
      delay(1000);
      digitalWrite(2, HIGH);
    }
    if (On == false){
      Serial.println("Turning off");
      delay(1000);
      digitalWrite(2, LOW);
    } 
}