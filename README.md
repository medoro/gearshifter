This file will emulate joypad buttons using an Arduino pro micro clone for use on **Euro Truck Simulator 2**.
Is mainly based on sample code from this library: https://github.com/MHeironimus/ArduinoJoystickLibrary

My version is made to be used on **6Pin 8 Speed + R Truck Electric Gear Shift Knob 81326200043 for MAN TGA TGX TGS** (you can bought one on ebay).

# Schematic for wiring / pin pairings

## Wiring:
 
| Wire/Knob button | Pro Micro Pin / Function |
|--|--|
| Upper button | Emulated X button|
| Blue       | GND |
| Yellow     | 5 |
| Side selector| Emulated B button| 
| Violet     | 4 |
| Green      | GND |
| Lower selector | (Emulated A button (both positions) |
| White      | GND |
| Red        | 3 |
| Blue      | 2
||*Note: solder a spare wire between center position of lower selector to pin 2* |

# Game configuration
After programming Adruino you have to load game, then go to *Settings / Controls*. 

I use this setup:  **Button 1** (A) as *Selector 1* and **Button 2** (B) as *Selector 2*. Then choose any transmission mode for H shifter. 

Upper button, emulated as X is free, I use it as engine brake control.

*Refer to game settings wizard for furhter instructions*

Made with 🩷 by M
