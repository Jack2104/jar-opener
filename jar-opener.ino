int mainMotor; // The motor that rotates the base of the jar
int startButton;
int buttonValue;

int activeLED; // Will light up when the jar opener is on
int runningLED; // Will light up when the jar opener is running

bool motorRunning = false;
unsigned long delayStart;
unsigned long openingDuration;

void setup() {
  // Setting the pin mode to output should make the LEDs brighter
  pinMode(activeLED, OUTPUT);
  pinMode(runningLED, OUTPUT);

  digitalWrite(activeLED, HIGH);

  startTime = millis()
}

void loop() {
  buttonValue = digitalRead(startButton);

  if (buttonValue) {
    motorRunning = !motorRunning;
    startTime = millis()
  }

  if (motorRunning) {
    digitalWrite(mainMotor, HIGH)
    digitalWrite(runningLED, HIGH);
    
  } else if (!motorRunning || millis() - startTime >= openingDuration) {
      digitalWrite(mainMotor, LOW);
      digitalWrite(runningLED, LOW);

      motorRunning = false;
      startTime = 0;
    }
}