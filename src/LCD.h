#ifndef LCD_h
#define LCD_h

#include "Serial_LCD_SparkFun.h"

class LCD : public Serial_LCD_SparkFun {
public:
  LCD();

  void writeLine(int line, String text);
  void line1(String text);
  void line2(String text);
  void moveCursorLine(int line);
  void clearLine(int line);
};

#endif
