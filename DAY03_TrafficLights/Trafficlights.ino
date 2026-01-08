#define RED 23
#define YELLOW 22
#define GREEN 2
void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}
void timer(void) {
  for(int i = 30; i > 0; i--){
    Serial.print("Stop: ");
    Serial.println(i);
    delay(1000);
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  }
  for(int i = 3; i > 0; i--){
    Serial.print("Wait: ");
    Serial.println(i);
    delay(1000);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
  }
  for(int i = 30; i > 0; i--) {
    Serial.print("Go: ");
    Serial.println(i);
    delay(1000);
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
  }
}
void loop() {
   timer();

}
