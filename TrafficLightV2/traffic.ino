// ===== PIN DEFINITIONS =====
#define RED_LED            2
#define YELLOW_LED         22
#define GREEN_LED          23

#define MANUAL_AUTO_BUTTON 4
#define RED_BUTTON         15
#define YELLOW_BUTTON      5
#define GREEN_BUTTON       21

// ===== TIMING =====
const int redTimeMS    = 5000;
const int yellowTimeMS = 2000;
const int greenTimeMS  = 5000;

// ===== STATE VARIABLES =====
unsigned long previousMillis = 0;
int currentLed = RED_LED;
bool mode = true;   // true = AUTO, false = MANUAL
int secondsLeft = 0;

// ===== SETUP =====
void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(MANUAL_AUTO_BUTTON, INPUT_PULLUP);
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(YELLOW_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

// ===== LOOP =====
void loop() {
  static unsigned long lastSecond = 0;

  // ----- MODE TOGGLE -----
  if (digitalRead(MANUAL_AUTO_BUTTON) == LOW) {
    mode = !mode;

    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    previousMillis = millis();
    lastSecond = millis();
    currentLed = RED_LED;

    delay(300); // debounce
  }

  // ===== AUTO MODE =====
  if (mode) {
    unsigned long currentMillis = millis();

    // Countdown timer
    if (currentMillis - lastSecond >= 1000 && secondsLeft > 0) {
      lastSecond = currentMillis;
      secondsLeft--;
      Serial.println(secondsLeft);
    }

    // Determine interval
    unsigned long interval = 0;
    if (currentLed == RED_LED) interval = redTimeMS;
    else if (currentLed == YELLOW_LED) interval = yellowTimeMS;
    else if (currentLed == GREEN_LED) interval = greenTimeMS;

    // Switch lights
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (currentLed == RED_LED) {
        currentLed = YELLOW_LED;
        secondsLeft = yellowTimeMS / 1000;
        Serial.println("STOP");
      }
      else if (currentLed == YELLOW_LED) {
        currentLed = GREEN_LED;
        secondsLeft = greenTimeMS / 1000;
      }
      else if (currentLed == GREEN_LED) {
        currentLed = RED_LED;
        secondsLeft = redTimeMS / 1000;
      }
    }

    // Update LEDs
    digitalWrite(RED_LED,    currentLed == RED_LED);
    digitalWrite(YELLOW_LED, currentLed == YELLOW_LED);
    digitalWrite(GREEN_LED,  currentLed == GREEN_LED);
  }

  // ===== MANUAL MODE =====
  else {
    digitalWrite(RED_LED,    digitalRead(RED_BUTTON)    == LOW);
    digitalWrite(YELLOW_LED, digitalRead(YELLOW_BUTTON) == LOW);
    digitalWrite(GREEN_LED,  digitalRead(GREEN_BUTTON)  == LOW);
  }
}
