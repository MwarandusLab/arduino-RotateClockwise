//28BYJ 5V or 12V stepper Motor Connection
const int STEPPER_PIN_1 = 10;
const int STEPPER_PIN_2 = 11;
const int STEPPER_PIN_3 = 12;
const int STEPPER_PIN_4 = 13;

const int STEPS_PER_REVOLUTION = 2048;
const float DEGREES_PER_STEP = 360.0 / STEPS_PER_REVOLUTION;
const int TARGET_DEGREES = 40;

void setup() {
  // put your setup code here, to run once:
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  // to call the instruct the motor to rotate clockwise once when the program begins then call the function here
  rotateClockwise();
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
//Motor Function To rotate clockwise
void rotateClockwise() {
  int targetSteps = TARGET_DEGREES / DEGREES_PER_STEP;
  const int stepSequence[8][4] = {
    {HIGH, LOW, LOW, LOW},
    {HIGH, HIGH, LOW, LOW},
    {LOW, HIGH, LOW, LOW},
    {LOW, HIGH, HIGH, LOW},
    {LOW, LOW, HIGH, LOW},
    {LOW, LOW, HIGH, HIGH},
    {LOW, LOW, LOW, HIGH},
    {HIGH, LOW, LOW, HIGH}
  };
  for (int i = 0; i < targetSteps; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(STEPPER_PIN_1, stepSequence[j][0]);
      digitalWrite(STEPPER_PIN_2, stepSequence[j][1]);
      digitalWrite(STEPPER_PIN_3, stepSequence[j][2]);
      digitalWrite(STEPPER_PIN_4, stepSequence[j][3]);
      delayMicroseconds(1000);
    }
  }
  delay(500);
  for (int i = 0; i < targetSteps; i++) {
    for (int j = 7; j >= 0; j--) {
      digitalWrite(STEPPER_PIN_1, stepSequence[j][0]);
      digitalWrite(STEPPER_PIN_2, stepSequence[j][1]);
      digitalWrite(STEPPER_PIN_3, stepSequence[j][2]);
      digitalWrite(STEPPER_PIN_4, stepSequence[j][3]);
      delayMicroseconds(1000);
    }
  }
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
}