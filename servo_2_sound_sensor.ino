//FIRST TESTING OF SERVO MOTOR WITH SOUND SENSOR CONTROL

#include <Servo.h>
Servo myservo;  
int LED=8;
int soundSensor=2;

void setup() {
  pinMode(soundSensor,INPUT);
  pinMode(LED,OUTPUT);
  myservo.attach(LED,600,4300); 
}

void loop() {
  boolean LEDStatus=false;
 int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){

    if(LEDStatus==false){
        LEDStatus=true;
        
        digitalWrite(LED,HIGH);
        myservo.write(0);  
        delay(1000);
  
        myservo.write(90);              
        delay(500); 
  
        myservo.write(135);              
        delay(500);
 
        myservo.write(360);              
        delay(1500); 
    
    
    }else{
        LEDStatus=false;
        digitalWrite(LED,LOW);           
}
}
}

 //CODE EXAMPLE FROM https://www.arduino.cc/en/Tutorial/LibraryExamples 
