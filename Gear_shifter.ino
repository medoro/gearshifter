/*------------------------------------------------------------------------------------------
 Sample code by Matthew Heironimus | https://github.com/MHeironimus/ArduinoJoystickLibrary
 2016-11-24
--------------------------------------------------------------------
  Gear shifter for MAN lever and ETS2/ATS
  mod by Genxha | https://www.twitch.tv/genxha | https://wolfhowls.tumblr.com/

  Wiring:
  Lever wire | Pro Micro Pin
  
  Upper (round) button (Emulated X button)
  Blue       | GND
  Yellow     | 5
  
  Side selector (Emulated B button)
  Violet     | 4
  Green      | GND
  
  Lower selector (Emulated A button - both positions)
  White      | GND
  Red        | 3
  Blue*      | 2  <---- Note: solder a spare wire between center position of lower selector to pin 2

  ---------------------------------------------------------------------------------------------------*/

#include <Joystick.h>
#include <usb_rename.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   4, 0,                  // Button Count, Hat Switch Count
                   false, false, false,   // X and Y, but no Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering

USBRename dummy = USBRename("Gear Shifter", NULL, NULL);

void setup() {  // Initialize Button Pins
  for (int index = 0; index < 4; index++) {
    pinMode(index + 2, INPUT_PULLUP);
  }

  Joystick.begin();  // Initialize Joystick Library

  for (int index = 0; index < 4; index++) {  // Reset Button Pins
    Joystick.setButton(index, !digitalRead(index + 2));
  }
}

int lastButtonState[4] = { 0, 0, 0, 0 };  // Last state of buttons

void loop() {
  for (int index = 0; index < 4; index++) {
    int currentButtonState = !digitalRead(index + 2);  // Read button state (note the ! operator)
    int isChanged = 0;
    if (lastButtonState[index] != currentButtonState) {  // press emulated buttons
      if (index == 2) {                                  // press X button
        if (currentButtonState == 0 && lastButtonState == 1 && isChanged == 1) {
          Joystick.setButton(3, 1);
          lastButtonState[3] = 1;
          isChanged == 1;
        }
        isChanged == 0;
      }
      if (index == 1 && currentButtonState == 1) {  // press A button when selector changes position
        Joystick.setButton(1, 0);
        lastButtonState[1] = 0;
        if (lastButtonState[0] == 0) {
          Joystick.setButton(0, 1);
          lastButtonState[0] = 1;
        }
      } else {  // press B button
        Joystick.setButton(index, currentButtonState);
        lastButtonState[index] = currentButtonState;
      }
      delay(250);                     // keeps button pressed
      if (currentButtonState == 1) {  // buttons release
        Joystick.setButton(index, 0);
        lastButtonState[index] = currentButtonState;
      }
    }
  }
  delay(50);  // slow down loop
}
