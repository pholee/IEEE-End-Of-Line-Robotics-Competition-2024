// Speed pin setup
#define MOD 3

// Motor pins setup
#define rSpeed 5 // Right motor speed control (0-256)
#define lSpeed 6 // Left motor speed control (0-256)
#define rDir 7 // Right motor direction (HIGH/LOW)
#define lDir 8 // Left motor direction (HIGH/LOW)

// Sensor pins setup
#define R A0 // Right IR sensor
#define M A1 // Middle IR sensor
#define L A2 // Left IR sensor

int rightVal, midVal, leftVal; // To store the values of sensors (0-1000)

void setup() {
  Serial.begin(9600);

  // Initialise speed pin mode
  pinMode(MOD, OUTPUT);
  digitalWrite(MOD, HIGH);

  //Initialise motor pins mode
  pinMode(rSpeed, OUTPUT);
  pinMode(lSpeed, OUTPUT);
  pinMode(rDir, OUTPUT);
  pinMode(lDir, OUTPUT);

  // Initialise sensor pins mode
  pinMode(R, INPUT);
  pinMode(M, INPUT);
  pinMode(L, INPUT);
}

// Motor Control Functions
void forward() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 180); 
  analogWrite(lSpeed, 180);
}

void backward() {
  digitalWrite(rDir, LOW);
  digitalWrite(lDir, LOW);
  analogWrite(rSpeed, 180);
  analogWrite(lSpeed, 180);
}

void softLeft() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 120);
  analogWrite(lSpeed, 180);
}

void softRight() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 180);
  analogWrite(lSpeed, 120);
}

void sharpRight() {
  digitalWrite(rDir, HIGH);
  digitalWrite(lDir, LOW);
  analogWrite(rSpeed, 150);
  analogWrite(lSpeed, 100);
}

void sharpLeft() {
  digitalWrite(rDir, LOW);
  digitalWrite(lDir, HIGH);
  analogWrite(rSpeed, 100);
  analogWrite(lSpeed, 150);
}

// Core logic
void loop() {
  // Read sensor values
  rightVal = analogRead(R);
  midVal = analogRead(M);
  leftVal = analogRead(L);

  // Movement
  if (rightVal < 250 && midVal >= 400 && leftVal < 250) {  // Go forward if line under middle sensor
    forward();
  } else if (rightVal < 250 && midVal >= 400 && leftVal >= 400) {  // 45 right if only the right sensor is off the line (highermidVal)
    softRight();
  } else if (rightVal < 250 && midVal < 250 && leftVal >= 400) {  // 90 right if only the right sensor is off the line (lower midVal)
    sharpRight();
  } else if (rightVal >= 400 && midVal >= 400 && leftVal < 250) {  // 45 left if only the left sensor is off the line (higher midVal)
    softLeft();
  } else if (rightVal >= 400 && midVal < 250 && leftVal < 250) {  // 90 left only the left sensor is off the line (lower midVal)
    sharpLeft();
  } else if (rightVal < 250 && midVal < 250 && leftVal < 250) {  // Go backwards if no line detected
    backward();
  }
}