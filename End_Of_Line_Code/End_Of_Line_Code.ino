// Motor Pins
int rSpeed = 5;  // Right motor speed control
int lSpeed = 6;  // Left motor speed control
int rDir = 7;    // Right motor direction
int lDir = 8;    // Left motor direction

// Sensor Pins
int L = A2;  // Left IR sensor
int M = A1;  // Middle IR sensor
int R = A3;  // Right IR sensor

void setup() {
  // Initialize motor pins
  pinMode(rSpeed, OUTPUT);
  pinMode(lSpeed, OUTPUT);
  pinMode(rDir, OUTPUT);
  pinMode(lDir, OUTPUT);

  // Initialize sensor pins
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);
}

// Core Logic
void loop() {
  // Read sensor values
  int leftVal = analogRead(L);
  int midVal = analogRead(M);
  int rightVal = analogRead(R);

  // Threshold for detecting the line
  int threshold = 500;

  //Go forward if line under middle sensor
  if (midVal < threshold) {
    forward();
  }

  //Go right if line under right sensor
  if (rightVal < threshold) {
    right();
  }

  //Go left if line under left sensor
  if (leftVal < threshold) {
    left();
  }

  //Spin if line under all sensors
  if (leftVal < threshold && midVal < threshold && rightVal < threshold) {
    spinClockwise();
  }

  //Spin if line undetected
  if (leftVal > threshold && midVal > threshold && rightVal > threshold) {
    spinClockwise();
  }
}

// Motor Control Functions
void forward() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 150); 
  analogWrite(lSpeed, 150);
}

void backward() {
  digitalWrite(rDir, LOW);
  digitalWrite(lDir, LOW);
  analogWrite(rSpeed, 150);
  analogWrite(lSpeed, 150);
}

void left() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 150);
  analogWrite(lSpeed, 50);
}

void right() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 50);
  analogWrite(lSpeed, 150);
}

void spinClockwise() {
  analogWrite(rSpeed, 250);
  analogWrite(lSpeed, 250);
  digitalWrite(rDir, LOW);
  digitalWrite(lDir, HIGH);
}