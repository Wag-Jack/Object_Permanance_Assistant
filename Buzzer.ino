#define buzzPin 4

float dist;

void setup() {
  
  Serial.begin(9600);

  pinMode(buzzPin, OUTPUT);
  
}

void loop() {
  
  if (Serial.available() > 0) {
    
    dist = Serial.parseFloat();
    
    if (dist <= 100.0 && dist >= 80.0) {

      noTone(buzzPin);
      tone(buzzPin, 15000);

    } else if (dist >= 60.0) {

      noTone(buzzPin);
      tone(buzzPin, 16000);

    } else if (dist >= 40.0) {

      noTone(buzzPin);
      tone(buzzPin, 17000);

    } else if (dist >= 20.0) {

      noTone(buzzPin);
      tone(buzzPin, 18000);

    } else if (dist >= 0.0) {

      noTone(buzzPin);
      tone(buzzPin, 19000);

    }
    
  }
  
  delay(10);
  
  Serial.print(dist);
  
}