int pd=2;                      //Photodiode to digital pin 2
float sinVal;  
int toneVal;
 int buzz=12;                   //piezo buzzer to digital pin 13  
 int senRead=0;                 //Readings from sensor to analog pin 0  
 int limit=700;                 //Threshold range of an obstacle  
 void setup()    
 {  
  pinMode(pd,OUTPUT);  
  pinMode(buzz,OUTPUT);  
  digitalWrite(pd,HIGH);       //supply 5 volts to photodiode  
  digitalWrite(buzz,LOW);      //set the buzzer in off mode (initial condition)  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);          //setting serial monitor at a default baund rate of 9600  
 }  
 void loop()  
 {  
  int val=analogRead(senRead);  //variable to store values from the photodiode  
  Serial.println(val);          // prints the values from the sensor in serial monitor  
  if(val <= limit)              //If obstacle is nearer than the Threshold range  
  {  
   for(int x=0; x<180; x++){
            sinVal = (sin(x*(3.1412/180)));
            toneVal = 2000+(int(sinVal*1000));
            tone(buzz, toneVal);
            delay(2); 
          } 
   digitalWrite(LED_BUILTIN, HIGH);
   delay(1000);
  }  
  else if(val > limit)          //If obstacle is not in Threshold range  
  {  
   noTone(buzz);
   digitalWrite(LED_BUILTIN, LOW);
   delay(1000); 
  }  
 }  
