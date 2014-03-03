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

  // check if data has been sent from the computer:
  if (Serial.available()) {
     Serial.readBytes(buffer, 3);

     analogWrite(redLedPin, buffer[0]);
     analogWrite(greenLedPin, buffer[1]);
     analogWrite(blueLedPin, buffer[2]);
  }
}
