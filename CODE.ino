        
        //definition of the integers 
        
int in1 = 2;       //PIN for activation of the realy and then the motor

int moistureSensor = A0;    //definition of the moisture Sensor
int MOISTUREVAL;
int sensorValue;


void setup() {
    Serial.begin(9600);
  // put your setup code here, to run once:

  pinMode(in1, OUTPUT);
}

void loop() {


MOISTUREVAL=analogRead(moistureSensor); // read the values from moisture sensor and name it MOISTUREVAL+
sensorValue=analogRead(moistureSensor);
  // Serial Begin so we can see the data from the mosture sensor in our serial input window. 
///*
Serial.print("Humidity of the moisture: ");
Serial.println(MOISTUREVAL);
Serial.print("2Humidity of the moisture: ");
Serial.println(sensorValue);
//*/

delay(1000);


 //start of the range of values for the sensor

 if (sensorValue >= 820 && sensorValue <= 1024)   // this is the effect if the moisture is completely wet
 {
 digitalWrite(in1, LOW);  //Writes PWM to the motor   
 delay(3000); //Making this too small can damage the motor 
    
}
else if (sensorValue >= 615  && sensorValue < 820)    // this is the light effect if the moisture is almost completely wet
 {
 digitalWrite(in1, HIGH);  // analogWrite(motor, intensity);  //Writes PWM to the motor   
 delay(5000); //Making this too small can damage the motor 
 digitalWrite(in1,LOW);
}  
else if (sensorValue >= 410 && sensorValue < 615)    // this is the light effect if the moisture is a little wet
 {
 digitalWrite(in1, HIGH);  // analogWrite(motor, intensity);  //Writes PWM to the motor   
 delay(9000); //Making this too small can damage the motor 
digitalWrite(in1,LOW);
}    
else if (sensorValue >= 250 && sensorValue < 410)    // this is the light effect if the moisture is almost dry
 {
 digitalWrite(in1, HIGH);  // analogWrite(motor, intensity);  //Writes PWM to the motor   
 delay(14000); //Making this too small can damage the motor 
digitalWrite(in1,LOW);
}
else if (sensorValue >= 0 && sensorValue < 250)     // this is the light effect if the moisture is completely dry
 {
 digitalWrite(in1, HIGH);  // analogWrite(motor, intensity);  //Writes PWM to the motor   
 delay(19000); //Making this too small can damage the motor 
digitalWrite(in1,LOW);
}
  delay(1000);        // delay 1 second between reads


}
