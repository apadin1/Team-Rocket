// File Name:   car.ino
// Project:     RC Car: Car side
// Author:      Adrian Padin
// Start Date:  19 April 2016

/***** LIBRARIES *****/

/***** DEFINES *****/
#define MAX_PWM 255
#define MOTOR_OUT 5
#define TURN_OUT 6
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define STOP 0x5A

#define CAR_ID 1

/***** GLOBALS *****/
byte rx_buff[4] = {0, 0, 0, 0};
byte num_bytes = 0;


/***** SETUP *****/
void setup() {
  Serial.begin(57600); // For XBee data
  //Serial.begin(9600);
}


/***** LOOP *****/
void loop() {

  // Read data when it is sent
  if (Serial.available() >= 4) {

    // Protocol:
    // Byte 0: CAR ID
    // Byte 1: Forward motion      OR Left Stick
    // Byte 2: Left/right control  OR Right Stick
    // Byte 3: STOP byte

    // Read the incoming bytes:
    rx_buff = {0, 0, 0, 0};
    num_bytes = Serial.readBytesUntil(STOP, rx_buff, 4);
    if (rx_buff[0] == CAR_ID &&
        rx_buff[3] == STOP &&
        num_bytes == 4) {

      /***** SCHEME ONE *****/

      analogWrite(MOTOR_OUT, rx_buff[1]); // Forward data is PWM

      // Interpret left/right control
      byte turn_val = rx_buff[2];
      if (turn_val > 128) {
        analogWrite(TURN_OUT, (turn_val-128)*2); // Turn right
      }
      else if (turn_val < 128) {
        analogWrite(TURN_OUT, (turn_val-128)); // Turn left
      }
      else {
        // do nothing
        analogWrite(TURN_OUT, /*zero?*/)
      }
      
      
    }
  }
}


/***** FUNCTIONS *****/
