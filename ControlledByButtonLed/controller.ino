#define led 2
#define button 4

bool state = false;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}
void loop () {
  if(digitalRead(button) == LOW) {
    state = !state;
    delay(300);
  }
  digitalWrite(led, state? HIGH : LOW);
}
