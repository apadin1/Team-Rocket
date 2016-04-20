// File Name:   controller.ino
// Project:     RC Car: Controller side
// Author:      Adrian Padin
// Start Date:  19 April 2016

/***** LIBRARIES *****/
#include <PS2X_lib.h> 

/***** DEFINES *****/

/***** GLOBALS *****/
PS2X ps2x; // PS2 Controller class
int error = 0;
byte vibrate = 0;
byte rx_buff

byte PWM = 6;

/***** SETUP *****/
void setup() {

  Serial.begin(57600); // For XBee data

  int error = ps2x.config_gamepad(13,11,10,12, true, true);   

}


/***** LOOP *****/

void loop() {

  //if (error != 0) {
  //  return; // Controller not found, reset
  //}

  



  ps2x.read_gamepad(false, vibrate);
  analogWrite(PWM, ps2x.Analog(PSAB_BLUE));
}


/***** FUNCTIONS *****/

