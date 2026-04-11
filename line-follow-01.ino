// apologize in advance for not following a naming
// convention - also I have no clue why 5,6,7 could
// not define (arduino ide gave some error and I don't
// care enough to address it) :P

// pins for the sensors
int LEFT_PIN = 8;
int MIDDLE_PIN = 7;
int RIGHT_PIN = 11;

// pins for the motors and speeds
#define DPIN_L_MOTOR 4
#define APIN_L_SPEED 5
#define DPIN_R_MOTOR 2
#define APIN_R_SPEED 6

#define APIN_LED 9

int left_value, middle_value, right_value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_PIN, INPUT);
  pinMode(MIDDLE_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);

  forwardChange();  // init to forward
}

void forwardChange() {
  digitalWrite(DPIN_L_MOTOR, HIGH); digitalWrite(DPIN_R_MOTOR, HIGH);
}
void backwardChange() {
  digitalWrite(DPIN_L_MOTOR, LOW); digitalWrite(DPIN_R_MOTOR, LOW);
}
void leftChange() {
  digitalWrite(DPIN_L_MOTOR, LOW); digitalWrite(DPIN_R_MOTOR, HIGH);
}
void rightChange() {
  digitalWrite(DPIN_L_MOTOR, HIGH); digitalWrite(DPIN_R_MOTOR, LOW);
}
void startMotors() {
  analogWrite(APIN_L_SPEED, 100); analogWrite(APIN_R_SPEED, 100);
}
void stopMotors() {
  analogWrite(APIN_L_SPEED, 0); analogWrite(APIN_R_SPEED, 0);
}

void loop() {
  left_value = digitalRead(LEFT_PIN);
  middle_value = digitalRead(MIDDLE_PIN);
  right_value = digitalRead(RIGHT_PIN);

  Serial.print("left: "); Serial.print(left_value);
  Serial.print("  middle: "); Serial.print(middle_value);
  Serial.print("  right: "); Serial.print(right_value);
  Serial.print("\n");

  if (middle_value || left_value || right_value) {
    startMotors();
    if (middle_value) {
      forwardChange();
    } else if (left_value) {
      rightChange();
    } else if (right_value) {
      leftChange();
    }
  } else {
    stopMotors();
  }

  delay(500);
}
