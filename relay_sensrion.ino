#include <Sensirion.h>


/*
sensirion 
önden
1-2
2-5v
3-gnd
4-3
*/
const uint8_t dataPin  =  3;
const uint8_t clockPin =  2;

float temperature;
float humidity;
float dewpoint;
int byteRead;

const int redPin = 10;
const int greenPin = 5;
const int bluePin = 11;

Sensirion tempSensor = Sensirion(dataPin, clockPin);
int led = 13;
#define RELAY1  6                        
#define RELAY2  7                        
#define RELAY3  8                        
#define RELAY4  9


void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
   pinMode(redPin, OUTPUT); 
   pinMode(greenPin, OUTPUT); 
   pinMode(bluePin, OUTPUT);  
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
   switch(GetFromSerial())
  {
  case 'a':
     digitalWrite(RELAY1,LOW); 
    break;
  case 'A':
      digitalWrite(RELAY1,HIGH);          // Turns Relay Off
    break;
  case 'b':
     digitalWrite(RELAY2,LOW); 
    break;
  case 'B':
      digitalWrite(RELAY2,HIGH);          // Turns Relay Off
    break;
  case 'c':
     digitalWrite(RELAY3,LOW); 
    break;
  case 'C':
      digitalWrite(RELAY3,HIGH);          // Turns Relay Off
    break;
  case 'd':
     digitalWrite(RELAY4,LOW); 
    break;
  case 'D':
      digitalWrite(RELAY4,HIGH);          // Turns Relay Off
    break;
   case 'S':
       tempSensor.measure(&temperature, &humidity, &dewpoint);
      
        Serial.print("T(C): ");
        Serial.print(temperature);
        Serial.print("; H(%): ");
        Serial.println(humidity);
    break;
    case 'R':
                     // while (Serial.available() > 0) {
                
                     // look for the next valid integer in the incoming serial stream:
                     int red = Serial.parseInt(); 
                     // do it again:
                     int green = Serial.parseInt(); 
                     // do it again:
                     int blue = Serial.parseInt(); 
                
                     // look for the newline. That's the end of your
                     // sentence:
                     if (Serial.read() == '\n') {
                       // constrain the values to 0 - 255 and invert
                       // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
                
                       // fade the red, green, and blue legs of the LED: 
                       analogWrite(redPin, red);
                       analogWrite(greenPin, green);
                       analogWrite(bluePin, blue);

    break;
                     }
                     
  }
}
int GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}

