// Module variables
int OuterMode = 1;              //Start mode: all on

// Mode variables
int OM2_Position = 1;           // Current LED position

int OM3_Position = 1;           // Current LED position
byte OM3_Delay = 15;            // Current speed
byte OM3_SpeedChange = 1;       // Speed up or down

// Setup
void SetupOuterCircle() {
  pinMode(LEDBAR_LATCH_PIN, OUTPUT);
  pinMode(LEDBAR_CLOCK_PIN, OUTPUT);
  pinMode(LEDBAR_DATA_PIN, OUTPUT);

  ResetOuterCircle();
}

void ResetOuterCircle() {
  LEDint(0);
}

void UpOuterCircle() {
  LEDint(10);
}
//-------------------------------------------------------------------------------

void LEDint(int numberToDisplay) {     
  digitalWrite(LEDBAR_LATCH_PIN, LOW);

  shiftOut(LEDBAR_DATA_PIN, LEDBAR_CLOCK_PIN, MSBFIRST, (numberToDisplay >> 8));  
  shiftOut(LEDBAR_DATA_PIN, LEDBAR_CLOCK_PIN, MSBFIRST, numberToDisplay);  

  digitalWrite(LEDBAR_LATCH_PIN, HIGH);  
}

void LEDbar(int bar) {
  int numberToDisplay = 0xFFFF >> (LEDBAR_BARS - bar);
     
  digitalWrite(LEDBAR_LATCH_PIN, LOW);

  shiftOut(LEDBAR_DATA_PIN, LEDBAR_CLOCK_PIN, MSBFIRST, (numberToDisplay >> 8));  
  shiftOut(LEDBAR_DATA_PIN, LEDBAR_CLOCK_PIN, MSBFIRST, numberToDisplay);  

  digitalWrite(LEDBAR_LATCH_PIN, HIGH);  
}

void ModeChangeOuter(int change) {
  if (change == 1) {
    OuterMode = OuterMode + 1;
    if (OuterMode > 3) { OuterMode = 3; }    
  } else {
    OuterMode = OuterMode - 1;
    if (OuterMode < 0) { OuterMode = 0; }    
  }

/*
 * Outer modes:
 *  0: Off
 *  1: On
 *  2: Circular
 *  3: Circular+
 */
  switch (OuterMode) {
    case 0:       
      ResetOuterCircle();
      break;
    case 1:
      UpOuterCircle();
      break;
    case 2:
      OM2_Position = 1;         // Current LED position
      break;
    case 3:
      {
        OM3_Position = 1;       // Current LED position
        OM3_Delay = 15;         // Current speed
        OM3_SpeedChange = 1;    // Speed change direction
      }     
      break;
  } 
}

void LoopOuter() {
  switch (OuterMode) {
    case 2:
      LoopOuterMode2();
      break;
    case 3:
      LoopOuterMode3();
      break;
  }  
}

void LoopOuterMode2() {
  if (Tick % 12 == 0) {
    LEDint(OM2_Position);
    OM2_Position = OM2_Position * 2;
    if (OM2_Position > 512) { OM2_Position = 1;}
  }  
}

void LoopOuterMode3() {
  if (Tick % OM3_Delay == 0) {
    LEDint(OM3_Position);
    OM3_Position = OM3_Position * 2;
    if (OM3_Position > 512) { OM3_Position = 1; }
  }  

  if (Tick % 200 == 0) {
    if (OM3_SpeedChange == 1) {
      OM3_Delay--;
      if (OM3_Delay == 1 ) { OM3_SpeedChange = -1; }
    } else {
      OM3_Delay++;
      if (OM3_Delay == 15 ) { OM3_SpeedChange = 1; }
    }
  }  
}


