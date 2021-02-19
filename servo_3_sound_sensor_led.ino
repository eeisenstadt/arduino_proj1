//FINAL SERVO - SOUND MOTION CONTROL TOY GARAGE SERVO 

#include <Servo.h>
Servo myservo;  
int LED=10;
int soundSensor=2;
void setup() {
  pinMode(soundSensor,INPUT);
  pinMode(LED,OUTPUT);
  myservo.attach(LED,600,2300);  
}

void loop() {
 boolean LEDStatus=false;
 int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){
    if(LEDStatus==false){
      LEDStatus=true;
      digitalWrite(2,HIGH);
      digitalWrite(LED,HIGH);
       
      myservo.write(0);  
      delay(5000);
  
      myservo.write(90);              
      delay(500); 
  
      myservo.write(135);              
      delay(500);
 
      myservo.write(180);              
      delay(1500); 
        }else{
       LEDStatus=false;
       digitalWrite(LED,LOW);           
}
}
}

 //CODE EXAMPLE FROM https://www.arduino.cc/en/Tutorial/LibraryExamples 
