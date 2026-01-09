#define led 2
#define button 4

bool state = false;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP); //button not pressed - HIGH
}
void loop () {
  if(digitalRead(button) == LOW) {
    state = !state; //reverse
    delay(300); //avoid noise
  }
  digitalWrite(led, state? HIGH : LOW); //ternary
}
