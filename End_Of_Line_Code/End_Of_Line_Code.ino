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

  //wheels
  pinMode(rSpeed, OUTPUT);
  pinMode(lSpeed, OUTPUT);
  pinMode(rDir, OUTPUT);
  pinMode(lDir, OUTPUT);

  //sensors recieving
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);

  Serial.begin(9600);
  analogWrite(speedPin, speed);
}

//Core logic
void loop() {

  //Go forward if line under middle sensor
  if (digitalRead(M) == LOW) (
    forward();
  )

  //Go right if line under right sensor
  if (digitalRead(R) == LOW) (
    right();
  )

  //Go left if line under left sensor
  if (digitalRead(L) == LOW) (
    left();
  )

  //Spin if line under all sensors
  if (digitalRead(L) == LOW) && (digitalRead(M) == LOW) && (digitalRead(R) == LOW) (
    spinClockwise();
  )

  //Spin if line undetected
  if (digitalRead(L) == HIGH) && (digitalRead(M) == HIGH) && (digitalRead(R) == HIGH) (
    spinClockwise();
  )

  delay(10);
}

void forward() {
  analogWrite(rSpeed, 250);
  analogWrite(lSpeed, 250);
  digitalSpeed(rDir, HIGH);
  digitalSpeed(lDir, HIGH);
}

void backward() {
  analogWrite(rSpeed, 250);
  analogWrite(lSpeed, 250);
  digitalSpeed(rDir, LOW);
  digitalSpeed(lDir, LOW);
}

void left() {
  analogWrite(rSpeed, 250);
  analogWrite(lSpeed, 0);
  digitalSpeed(rDir, HIGH);
}

void right() {
  analogWrite(rSpeed, 0);
  analogWrite(lSpeed, 250);
  digitalSpeed(lDir, HIGH);
}

void spinClockwise() {
  analogWrite(rSpeed, 250);
  analogWrite(lSpeed, 250);
  digitalSpeed(rDir, LOW);
  digitalSpeed(lDir, HIGH);
}