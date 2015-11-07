# Why
This arduino library 

# Requirements
- Arduino Uno or Yùn (tested only with Yùn)
- x * 7 * NeoPixels led strips (any WS2811/WS2812 5050 RGB LED Addressable strips seems to be ok)

**Multiples of 7 strips are needed because this library displays chars on a 7 rows by 5 columns matrix.**

Example of connection :

|Arduino|Led Strip|
|GND|GND|
|5V|5V if any|
|Pin #6|DATA|

Led strips are all chained like this :

```
        v-- TOP LINE #6
        ^-- LINE #5 --------v
        v-- LINE #4 --------^
        ^-- LINE #3 --------v
        v-- LINE #2 --------^
        ^-- LINE #1 --------v
ARDUINO >>> BOTTOM LINE #0 -^
```

# Installation
1. Install Adafruit Neopixels Library from your Arduino IDE
1. Get zip from this repository and uncompress file in your Arduino/libraries folder

# Usage

## First time

Add Adafruit Neopixels to your Arduino project

In head of your Arduino main code, paste this :

```
#include <LedStripPixelsDisplay.h>
#include <Adafruit_NeoPixel.h>
#define PIN 6 // Connect your RGB LED STRIP on a PWM pin, 6 is ok on Yùn
#define LED_BY_STRIP 60 // Numbers of leds for each horizontal line
#define NUMPIXELS    420 // Total numbers of pixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // Initialize your led strip
LedStripPixelsDisplay display = LedStripPixelsDisplay(&pixels, LED_BY_STRIP); // Initialize display
```

In your setup function, add :

```
pixels.begin();  // Start clock of leds strips
display.clear(); // Clear display
pixels.show();   // Send data to led strips, keep in mind that pixels is a buffer and display fills this buffer, you need to call show to send buffer to led strips
delay(20);       // Wait for 20ms before any other led strip refresh
```

## Set text

Use **display.message("Your text", pixels.Color(32, 0, 0));** to display **Your text** with red

Next you need to show the pixel buffer with **pixels.show()**

## Set a char at any position

Use **display.setChar(16, pixels.Color(0, 32, 0), 'A');** to display the char **A** at 16 pixels from the start

**Warning it's pixel position and not character position. If you want to pass character position, multiply position by 6** 