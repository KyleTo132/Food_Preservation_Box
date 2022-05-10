const int buttonPin=3;
int buttonInput= 0;
int buttonState=0;
const int RELAY_PIN=5;

void setup() {
pinMode(RELAY_PIN, OUTPUT);
pinMode(buttonPin,OUTPUT);
}

void loop() {
  
buttonInput = digitalRead(buttonPin);
if (buttonInput == 0) {
if (buttonState == 0) {
buttonState = 1;
} else {
buttonState = 0;
}
delay(500);
}
if (buttonState == 1) {
digitalWrite(RELAY_PIN, HIGH);
} else {
digitalWrite(RELAY_PIN, LOW);
}
delay(500);
}
