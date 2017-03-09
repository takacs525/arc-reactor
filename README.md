# Welcome to Arc reactor sample

This Arduino project contains a sample/demo application to drive LEDs in a 3D printed "custom case".

In motion :-)
-----------------
[![Youtube video](https://img.youtube.com/vi/b2yPtyNsJaY/0.jpg)](http://www.youtube.com/watch?v=b2yPtyNsJaY)

Project pictures
-----------------
![LEDs_on_breadboard](Pictures/web/LEDs_on_breadboard_web.jpg) | ![Inner_LED_setup](Pictures/web/Inner_LED_setup_web.jpg)
------------ | -------------
![Custom_PCB_with_arduino_web](Pictures/web/Custom_PCB_with_arduino_web.jpg) | ![Final](Pictures/web/Final_web.jpg)

File structure
-----------------
Directories:
* Arc_reactor: the Arduino project files
* Pictures
* Schematic: fritzing file folder

Hardware
-----------------
Required components:
* an Arduino Pro Mini 5V
* 2 SN74HC595 shift registers
* LEDs
* Resistors (470 ohm)
* a Bluetooth module (HC-07)

Software
-----------------
To send mode switch commands (key '1' to '4') you can use the serial monitor in the Arduino IDE or any Bluetooth mobile application (like Arduino Bluetooth Control in Google Play Store).

3D model
-----------------
Special thanks to Gyorgy Balassy for his incredible work. :clap:

You can find more informatin on his Thingiverse page: [Tony Stark's Bluetooth Controlled Arc Reactor](http://www.thingiverse.com/thing:2069812)

