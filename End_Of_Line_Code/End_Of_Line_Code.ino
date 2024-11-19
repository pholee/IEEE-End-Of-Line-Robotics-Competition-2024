//pins
const int rSpeed = 5;
const int lSpeed = 6;
const int rDir = 7;
const int lDir = 8;

const int speedPin = 3;
const int speed = 125;

//macro for reading from sensors
#define L analogRead(A0)
#define M analogRead(A1)
#define R analogRead(A0)

void setup() {
  Serial.begin(9600);
  analogWrite(speedPin, speed);
}

void loop() { //your logic goes here
  analogWrite(rSpeed, 250);
  analogWrite(lSpeed, 250);
  digitalSpeed(rDir, HIGH);
  digitalSpeed(lDir, HIGH);
  delay(10);
}
