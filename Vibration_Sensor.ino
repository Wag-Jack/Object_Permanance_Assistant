#define VIBRATION_SENSOR 3

void setup() {
  
  Serial.begin(9600);
  
  pinMode(VIBRATION_SENSOR, INPUT);

}

void loop() {
  
  Serial.println(digitalRead(VIBRATION_SENSOR));

  delay(500);

}
