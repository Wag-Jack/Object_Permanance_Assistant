#include <Servo.h>

#define TRIG_PIN_LEFT 9
#define ECHO_PIN_LEFT 10
#define TRIG_PIN_RIGHT 11
#define ECHO_PIN_RIGHT 12
#define BUZZ_PIN_LEFT 4
#define BUZZ_PIN_RIGHT 5
#define VIBRATION_SENSOR 3

Servo myServo;

bool toggle = false;
long duration;
float distance;

void setup() {

  Serial.begin(9600);

  pinMode(TRIG_PIN_LEFT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(BUZZ_PIN_LEFT, OUTPUT);
  pinMode(BUZZ_PIN_RIGHT, OUTPUT);
  pinMode(VIBRATION_SENSOR, INPUT);

}

void loop() {

  if (toggle) {
    // --- LEFT SENSOR ---
    digitalWrite(TRIG_PIN_LEFT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_LEFT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_LEFT, LOW);

    duration = pulseIn(ECHO_PIN_LEFT, HIGH, 30000);
    distance = (duration * 0.0343) / 2;

    if (distance > 0 && distance <= 100.0) {
      if (distance >= 80.0) {
        noTone(BUZZ_PIN_LEFT);
        tone(BUZZ_PIN_LEFT, 1000);
      } else if (distance >= 60.0) {
        noTone(BUZZ_PIN_LEFT);
        tone(BUZZ_PIN_LEFT, 2000);
      } else if (distance >= 40.0) {
        noTone(BUZZ_PIN_LEFT);
        tone(BUZZ_PIN_LEFT, 3000);
      } else if (distance >= 20.0) {
        noTone(BUZZ_PIN_LEFT);
        tone(BUZZ_PIN_LEFT, 4000);
      } else {
        noTone(BUZZ_PIN_LEFT);
        tone(BUZZ_PIN_LEFT, 5000);
      }
    } else {
      noTone(BUZZ_PIN_LEFT);
    }

    Serial.print("LEFT Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

  } else {
    // --- RIGHT SENSOR ---
    digitalWrite(TRIG_PIN_RIGHT, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN_RIGHT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN_RIGHT, LOW);

    duration = pulseIn(ECHO_PIN_RIGHT, HIGH, 30000);
    distance = (duration * 0.0343) / 2;

    if (distance > 0 && distance <= 100.0) {
      if (distance >= 80.0) {
        noTone(BUZZ_PIN_RIGHT);
        tone(BUZZ_PIN_RIGHT, 1000);
      } else if (distance >= 60.0) {
        noTone(BUZZ_PIN_RIGHT);
        tone(BUZZ_PIN_RIGHT, 2000);
      } else if (distance >= 40.0) {
        noTone(BUZZ_PIN_RIGHT);
        tone(BUZZ_PIN_RIGHT, 3000);
      } else if (distance >= 20.0) {
        noTone(BUZZ_PIN_RIGHT);
        tone(BUZZ_PIN_RIGHT, 4000);
      } else {
        noTone(BUZZ_PIN_RIGHT);
        tone(BUZZ_PIN_RIGHT, 5000);
      }
    } else {
      noTone(BUZZ_PIN_RIGHT);
    }

    Serial.print("RIGHT Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  toggle = !toggle; // alternate left-right
  delay(100); // gives plenty of time for echoes to clear

  Serial.print("Vibration: ");
  
  Serial.println(digitalRead(VIBRATION_SENSOR));

  delay(500);

}