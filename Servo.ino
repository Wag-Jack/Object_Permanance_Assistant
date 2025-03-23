#include <Servo.h>

#define servoPin 5

Servo myServo;

float dist = 200;
int angle = 90;

void setup() {
  
  Serial.begin(9600);

  myServo.attach(servoPin);
  
  myServo.write(0);
  
}

void loop() {
  
  if (Serial.available() > 0) {
    
    dist = Serial.parseFloat();
    
    if (dist <= 50) {
    
      myServo.write(90);
      delay(1000);
    
    } else {
    
      myServo.write(0);
      delay(1000);
    
    }
    
  }
  
  delay(10);
  
  Serial.print(dist);
  
}
