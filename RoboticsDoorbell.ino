
#include <Servo.h>

Servo myServo;

int posMin = 119;
int posMax = 180;

void setup() {

   pinMode(8, OUTPUT); //led pin
   pinMode(7, OUTPUT); //relay pin
   digitalWrite(7, LOW); //write the relay low to turn on the doorbell
   myServo.attach(9); //servo pin
   myServo.write(posMin); //start the servo at posMin
}

void loop() {
  
  int sensorValue = analogRead(A1); //read the raw voltage

  float voltage = sensorValue * (5.0 / 1023.0); //calculate the actual voltage from the input pin A1
  
  if (voltage <= 2.00)//threshhold of the doorbell
  {
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    myServo.write(posMax);

    delay(400); //small delay so the servo has time to pop out before the reset
    
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    myServo.write(posMin); 
  }
  
}
