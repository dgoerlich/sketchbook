const int redLedPin = 9;
const int greenLedPin = 10;
const int blueLedPin = 11;

void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  char buffer[3];

  static int red = 0;
  static int green = 0;
  static int blue = 0;

  int redDelta;
  int greenDelta;
  int blueDelta;
  
  float redIncrement;
  float greenIncrement;
  float blueIncrement;
  
  float redPartial;
  float greenPartial;
  float bluePartial;

  // check if data has been sent from the computer:
  if (Serial.available()) {
     Serial.readBytes(buffer, 3);
     
     //Serial.print(red);
     //Serial.print(green);
     //Serial.println(blue);
     
     redDelta = buffer[0] - red;
     greenDelta = buffer[1] - green;
     blueDelta = buffer[2] - blue;
     
     redIncrement = redDelta / 10;
     greenIncrement = greenDelta / 10;
     blueIncrement = blueDelta / 10;
     
     redPartial = red;
     greenPartial = green;
     bluePartial = blue;

     for (int x = 0; x < 10; x++) {
       redPartial += redIncrement;
       greenPartial += greenIncrement;
       bluePartial += blueIncrement;

       analogWrite(redLedPin, rnd(redPartial));
       analogWrite(greenLedPin, rnd(greenPartial));
       analogWrite(blueLedPin, rnd(bluePartial));
      
       delay(100);
     }    
     
     red = buffer[0];
     green = buffer[1];
     blue = buffer[2];

     analogWrite(redLedPin, red);
     analogWrite(greenLedPin, green);
     analogWrite(blueLedPin, blue);
  }  
}

int rnd(float value){
  int returnValue;
  
  if (value > 0.0)
    returnValue = int(floor(value + 0.5));
  else
    returnValue = int(ceil(value - 0.5));
    
  return returnValue;
}

