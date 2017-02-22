// Module variables
int InnerPins[] = {ILED0_PIN, ILED1_PIN, ILED2_PIN, ILED3_PIN, ILED4_PIN};
int InnerMode = 1;              //Start mode: all on

// Mode variables
int IM2_Brightness = 0;         // how bright the LED is
int IM2_FadeAmount = 5;         // how many points to fade the LED by

int IM3_Position = 1;           // Current LED position

// Setup
void SetupInnerCircle() {
  for (int i = 0; i < 5; i++) {
    pinMode(InnerPins[i], OUTPUT);
  }

  ResetInnerCircle();
}

void ResetInnerCircle() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(InnerPins[i], LOW);
  }
}

void UpInnerCircle() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(InnerPins[i], HIGH);
  }
}
//-------------------------------------------------------------------------------

void ModeChangeInner(int change) {
  if (change == 1) {
    InnerMode = InnerMode + 1;
    if (InnerMode > 3) { InnerMode = 3; }
  } else {
    InnerMode = InnerMode - 1;
    if (InnerMode < 0) { InnerMode = 0; }
  }

/*
 * Outer modes:
 *  0: Off
 *  1: On
 *  2: Fade
 *  3: Circular
 */
  switch (InnerMode) {
    case 0:
      ResetInnerCircle();
      break;
    case 1:
      UpInnerCircle();
      break;
    case 2:
      {
        IM2_Brightness = 0;    // how bright the LED is
        IM2_FadeAmount = 5;    // how many points to fade the LED by
      }
      break;
    case 3:
      {
        ResetInnerCircle();
        digitalWrite(ILED0_PIN, HIGH);
        digitalWrite(ILED1_PIN, HIGH);
        IM3_Position = 1;      // Current LED position
      }
      break;
  }
}

void LoopInner() {
  switch (InnerMode) {
    case 2:
      LoopInnerMode2();
      break;
    case 3:
      LoopInnerMode3();
      break;
  }
}

void LoopInnerMode2() {
  if (Tick % 3 == 0) {
    for (int i = 0; i < 5; i++) {
      analogWrite(InnerPins[i], IM2_Brightness);
    }
    
    IM2_Brightness = IM2_Brightness + IM2_FadeAmount;
    if (IM2_Brightness <= 0 || IM2_Brightness >= 255) {
      IM2_FadeAmount = -IM2_FadeAmount;
    }
  }  
}

void LoopInnerMode3() {
  if (Tick % 20 == 0) {
    digitalWrite(InnerPins[IM3_Position], LOW);
    
    IM3_Position++;
    if (IM3_Position > 4) { IM3_Position = 1; }

    digitalWrite(InnerPins[IM3_Position], HIGH);
  }  
}

