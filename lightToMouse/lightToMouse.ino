// This code lets you use the MEG-compatible touchpad.
//
// Takes input from light sensor, deals with the Microsoft protocol
// that it uses, writes the result in human-readable form to the Serial output
// and emulates a mouse.
//
// For the Microsoft mouse protcol, see
// http://paulbourke.net/dataformats/serialmouse/
//
// This code is quite old and might require some changes to run with newer
// Arduino IDEs.
//
// Authors:
// Jürgen Dax, juergen.dax@med.uni-tuebingen.de
// Jens Klinzing, jens.klinzing@uni-tuebingen.de
// Version: 11.02.2015

boolean debuggingMode = true;  // set true for output to Serial Monitor
boolean activateMouse = true;  // set t to deactivate the mouse function

int  Rx, dx, dy;
byte buttons;

void setup() { 
  // Open the serial port between Arduino and computer (Serial) with 
  // a baud rate of 9600
  Serial.begin(9600);

  // Open serial port between light sensor and Arduino
  // Microsoft Protocol has 7 bits, No parity, and 1 start bit (7N1)
  Serial1.begin(1200, SERIAL_7N1);  

  // Start mouse interface
  Mouse.begin();

  // Wait for the serial port to become initialized
  // while (!Serial);
 
  // Make sure the mouse is released
  Mouse.release(MOUSE_LEFT);
  Mouse.release(MOUSE_RIGHT);
}

void loop() {
  /*
  delay(2);  // to keep the computers buffer from overloading

  // Read in 1st byte coming from the serial port; parse input only 
  // starting from 64, which is the start bit
  Rx = Serial1.read();

  if (Rx >= 64) {

    dx = (Rx & 0x03) << 6;        // AND  3 and shift 6 bits to the left
    dy = (Rx & 0x0C) << 4;        // AND 12 and shift 4 bits to the left
    buttons = (Rx & 0x30) >> 4;   // AND 48 and shift 4 bits to the right

    // Try to read 2nd byte
    do {
      Rx = Serial1.read(); 
      //Serial.println("Code reached: Read second bit."); delay(10);
    } while (Rx < 0);             // while the Serial port sends -1 do nothing
    dx=dx+Rx; 
    if (dx>=128) dx=dx-256;       // convert unsigned number to signed number

    // Try to read 3rd byte
    do {
      Rx = Serial1.read(); 
    } while (Rx<0);               
    dy=dy+Rx; 
    if (dy>=128) dy=dy-256;

    // Use the result for mouse movements and clicks
    if (debuggingMode) {
      Serial.print("Buttons:");
      Serial.print(buttons);
      Serial.print("\tdx:");
      Serial.print(dx);
      Serial.print("\tdy:");
      Serial.println(dy);
    } 

    // mouse output
    if (activateMouse) {
      Mouse.move(dx*3,dy*3,0);
      if (buttons & 1) {
        if (!Mouse.isPressed(MOUSE_RIGHT)) Mouse.press  (MOUSE_RIGHT);
      } else {
        if ( Mouse.isPressed(MOUSE_RIGHT)) Mouse.release(MOUSE_RIGHT);
      }
      if (buttons & 2) {
        if (!Mouse.isPressed(MOUSE_LEFT))  Mouse.press  (MOUSE_LEFT);
      } else {
        if ( Mouse.isPressed(MOUSE_LEFT))  Mouse.release(MOUSE_LEFT);
      }
    }
  }
  */
}
