// Global variables
unsigned long Tick = 0;


#include "./Config.h"

void setup() {
	Serial.begin(9600);		      // Initialize serial communications with the PC or bluetooth

  SetupInnerCircle();
  SetupOuterCircle();

  delay(500);
  UpInnerCircle();
  UpOuterCircle();
    
}

void loop() {
  Tick++;

  if (Serial.available()) {
    int inByte = Serial.read();
    if (inByte >=49 and inByte <= 52) {
      switch (inByte) {
        case 49:                      //1 -> Outer mode + 1
          ModeChangeOuter(1);
          break;
        case 50:                      //2 -> Outer mode - 1
          ModeChangeOuter(-1);
          break;
        case 51:                      //3 -> Inner mode - 1
          ModeChangeInner(-1);
          break;
        case 52:                      //4 -> Inner mode + 1
          ModeChangeInner(1);
          break;
      }
    }
  }

  LoopInner();
  LoopOuter();

  delay(10);
}

