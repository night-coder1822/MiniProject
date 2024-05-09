 // IR Sensor with Arduino
//put this code in the ide of arduino from this line ( FOR digital output)  
 //Digital code  
 // Techatronic.com  
 int val = 0 ;  
 void setup() {  
    Serial.begin(9600); // sensor buart rate  
    pinMode(2,INPUT);  // IR sensor output pin connected  
    pinMode(6,OUTPUT);  // LED  
    pinMode(7,OUTPUT);  // BUZZER  
 }  

 void loop()  
 {  
    val = digitalRead(2);  //  IR sensor output pin connected  
    Serial.println(val);  // see the value in serial monitor in Arduino IDE  
    delay(500);  
    if(val == 1 ) {  
        digitalWrite(6,HIGH);  // LED ON  
        digitalWrite(7,HIGH);  // BUZZER ON  
    }  
    else {  
        digitalWrite(6,LOW);  // LED OFF  
        digitalWrite(7,LOW);  // BUZZER OFF  
    }  
}