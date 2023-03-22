#include <FastLED.h>
// #define FASTLED_ALL_PINS_HARDWARE_SPI

#define NUM_LEDS 4

#define NUM_STRIPS 10 // number if separate strips, one per column.
#define LED_BRIGHTNESS 32

// #define LED_PWR D7
#define LED_DAT 26
// #define CLOCK_PIN 27
#define LED_CLK1 27
// #define LED_CLK2 C2
// #define LED_CLK3 C3
// #define LED_CLK4 C4
// #define LED_CLK5 C5
// #define LED_CLK6 D0
// #define LED_CLK7 D1
// #define LED_CLK8 D2
// #define LED_CLK9 D3
// #define LED_CLK10 D4

// Define the array of leds
CRGB leds[NUM_LEDS];

uint8_t mode = 02;
bool ledPower = false;
byte hue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_DAT, OUTPUT);
  pinMode(LED_CLK1, OUTPUT);
  FastLED.addLeds<APA102, LED_DAT, LED_CLK1, BGR>(leds, NUM_LEDS);
  delay(100);
}

// Simply animate the current mode.
void loop()
{
  // Now turn the LED off, then pause
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(hue++, 255, 255);
  }
  FastLED.show();
  delay(100);
}
