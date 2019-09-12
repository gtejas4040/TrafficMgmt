/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int dec = 4;
int counter = 0;
boolean prevState = false;
boolean curState = false;
boolean prevState1 = false;
boolean curState1 = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(dec, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  

  // read the input pin:
  prevState = curState;
  curState = digitalRead(pushButton);
  prevState1 = curState1;
  curState1 = digitalRead(dec);
  // print out the state of the button:

  if (!curState && prevState) {
    counter++;
    Serial.println("COUNTER:");
    Serial.println(counter);
  }
  if (!curState1 && prevState1) {
    counter--;
    counter = constrain(counter, 0, 1000);
    Serial.println("COUNTER:");
    Serial.println(counter);
  }
  delay(100);        // delay in between reads for stability
}
