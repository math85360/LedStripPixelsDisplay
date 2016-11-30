#ifndef LedStripPixelsDisplay_h
#define LedStripPixelsDisplay_h
#include "neopixel/neopixel.h"

class LedStripPixelsDisplay
{
  public:
    LedStripPixelsDisplay(Adafruit_NeoPixel* pixels, int ledByLines);
    void scroll_message(String msg, uint32_t color, int (*f)(int, uint32_t color));
    void tap_message(String msg, uint32_t color, int (*f)(int, uint32_t color));
    void message(String msg, uint32_t color);
	void clear();
	void clear_color(uint32_t color);
	void digits(int pos, uint32_t color, byte l0, byte l1, byte l2, byte l3, byte l4, byte l5, byte l6, int from, int to);
	void line(int pos, uint32_t color, byte line, byte content, int from, int to);
	void onebit(int pos, uint32_t color, byte line, byte content, byte col, int from, int to);
	void onebit(uint32_t color, int col, byte line, bool enabled);
	void setChar(int pos, uint32_t color, char ch);
	void setChar(int pos, uint32_t color, char ch, int from, int to);
	void drawPath(byte p[], uint32_t color);
	void drawPath(byte p[], uint32_t color, int from, int to);
	void drawPath(byte p[], uint32_t color, int from, int to, int w, int offset);
	void drawImage(byte p[]);
  private:
	int _ledByLines;
	int _totalpixels;
    Adafruit_NeoPixel* _pixels;
	uint32_t black;
};
#endif
