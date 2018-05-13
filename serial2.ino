// Arduino Serial Tester
// rld, cycling'74, 3.2008
#include "matrix.h"

long randomvalue = 0; // random value
long countervalue = 0; // counter value
int serialvalue; // value for serial input
int started = 0; // flag for whether we've received serial yet

void setup()
{
  Serial.begin(9600); // open the arduino serial port

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(20);
  matrix.setTextColor( matrix.Color(255,255,255));
}

void loop()
{
  if(Serial.available()) // check to see if there's serial data in the buffer
  {
    serialvalue = Serial.read(); // read a byte of serial data
    started = 1; // set the started flag to on
  }

  /* this part turns on one light on the matrix */

    matrix.drawPixel(0,0, matrix.Color(serialvalue,0,0));
    matrix.show();  
  
}
