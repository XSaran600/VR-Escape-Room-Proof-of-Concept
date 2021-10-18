#include <SPI.h>
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial bt(0,1);

int lightSensorPin = A0;
int analogValue = 0;

/*
int buttonState = 0;

bool button = false;
*/
void setup() {
  SPI.begin();
  bt.begin(9600);
  //Serial.begin(9600);
  pinMode(2, INPUT);

}

void loop() {

  analogValue = analogRead(lightSensorPin);
  if(analogValue < 50) // If light sensor is covered
  {
    bt.write(2);
    bt.flush();
    delay(20);
  }
  /*
  buttonState = digitalRead(2);

  if(buttonState == 0)
  {
    if (button == true)
    {
      bt.println("not pressed");
      bt.write(1);
      bt.flush();
      delay(20);
      button = false;
    }
  }
  if(buttonState == 1)
  {
    if (button == false)
    {
      bt.println("pressed");
      bt.write(2);
      bt.flush();
      delay(20);
      button = true;
    }
  }
  if(buttonState == 0)
  {
    if (button == true)
    {
      bt.println("not pressed");
      bt.write(3);
      bt.flush();
      delay(20);
      button = false;
    }
  }
  if(buttonState == 1)
  {
    if (button == false)
    {
      bt.println("pressed");
      bt.write(4);
      bt.flush();
      delay(20);
      button = true;
    }
  }
  */
}
