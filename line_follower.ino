// Motor pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// IR sensor pins
#define S1 12
#define S2 14
#define S3 27

void setup() {
  Serial.begin(115200);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // IR sensors
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
}

void loop() {
  // Read sensors (0 = black line, 1 = white surface)
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);

  // Debug
  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.println(s3);

  // Line following logic
  if (s2 == 0) {          // Middle sensor on line
    forward();
  } else if (s1 == 0) {   // Left sensor on line
    left();
  } else if (s3 == 0) {   // Right sensor on line
    right();
  } else {                 // No line detected
    stopMotors();
  }
}

// Motor functions
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
