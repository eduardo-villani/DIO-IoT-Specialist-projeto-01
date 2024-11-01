// C++ code
//
#define sensorTempPin A0

const int MOTOR = 6;
const int ALARM = 7;


void setup()
{
  pinMode(MOTOR, OUTPUT);
  pinMode(ALARM, OUTPUT);
  digitalWrite(MOTOR, LOW);  // making sure motor is off
  digitalWrite(ALARM, LOW);  // making sure Alarm if off
  Serial.begin(9600);
}

void loop()
{
  int sensorReading = analogRead(sensorTempPin);
  float voltage = sensorReading * (5000 / 1024.0);
  float temperature = (voltage - 500) / 10;
  delay(10); // Delay a little bit to improve simulation performance
  
  // Serial.println(voltage); //used to confirm readings of TMP36
  // Serial.println(temperature); //used to confirm readings of TMP36
  
  if (temperature >= 30){
    digitalWrite(MOTOR, HIGH); // temperatura above 30ºC turn on motor
    delay(10);
  }
  
  if (temperature <= 29.99) {
      digitalWrite(MOTOR, LOW); // temperatura below 30ºC turn off motor
      delay(10);
  }
   
  if (temperature >= 50){
    digitalWrite(ALARM, HIGH); // temperatura above 50ºC turn on Alarm and Light
    delay(10);
  
  }
  
  if (temperature <= 49.99){
    digitalWrite(ALARM, LOW); // temperatura below 50ºC turn off Alarm and light
    delay(10);
  
  }
  
   
}

// credits Eduardo Villani