 #include <Servo.h>
 
 int photodiodeDigital=2;              //digital pin 2 
 int photodiodeAnalog=0;               //analog pin 0  
 int limit=600;                        //Threshold range of an obstacle  

 Servo servoMotor;
 
 void setup()    
 {  
  pinMode(photodiodeDigital,OUTPUT);  
  digitalWrite(photodiodeDigital,HIGH);       //supply 5 volts to photodiode  
  pinMode(LED_BUILTIN, OUTPUT);
  servoMotor.attach(9);
  servoMotor.write(0);
  Serial.begin(9600);          //setting serial monitor at a default baund rate of 9600  
 }  

 
 void loop()  
 {  
  int val=analogRead(photodiodeAnalog);  //variable to store values from the photodiode  
  Serial.println(val);          // prints the values from the sensor in serial monitor  
  if(val <= limit)              //If obstacle is nearer than the Threshold range  
  {  
   digitalWrite(LED_BUILTIN, HIGH);
   servoMotor.write(90);
   delay(500);
  }  
  else if(val > limit)          //If obstacle is not in Threshold range  
  {  
   digitalWrite(LED_BUILTIN, LOW);
    servoMotor.write(0);
   delay(500); 
  }  
 }  
