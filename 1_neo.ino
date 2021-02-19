#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   10   
#define PIXEL_PIN 5  
#define PIXEL_COUNT 3  

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;
int  touchPin = analogRead(A0);
// variables will change:
//int buttonState = 0;        


void setup() {
 Serial.begin(9600);
  strip.begin();
  strip.show(); 
}

void loop() {

  bool newState = analogRead(A0);
  if (newState == LOW && oldState == HIGH) {
    delay(20);
    newState = analogRead(A0);
    if (newState == LOW) {
      showType++;
      if (showType > 4)
        showType=0;
      startShow(showType);
    }
    Serial.println(A0);
  }

  oldState = newState;
}

void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
            break;
    case 1: colorWipe(strip.Color(0, 255, 0), 50);  // Red
            break;
    case 2: colorWipe(strip.Color(0, 255, 0), 50);  // Green
            break;
    case 3: colorWipe(strip.Color(0, 0, 255), 50);  // Blue
            break;
  }
}
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


 //CODE EXAMPLE FROM https://www.arduino.cc/en/Tutorial/LibraryExamples 
// MODIFIED BY SHERIDAN INSTRUCTOR 
