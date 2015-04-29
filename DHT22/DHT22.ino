#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 4;

void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
   dht.begin();
}

void loop() {
  char buffer[1];

  // check if data has been sent from the computer:
  if (Serial.available()) {
    Serial.readBytes(buffer, 1);
    
    digitalWrite(ledPin, HIGH);
    
    
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    Serial.println(h);
    Serial.println(t);
    
    digitalWrite(ledPin, LOW);
  }
}
