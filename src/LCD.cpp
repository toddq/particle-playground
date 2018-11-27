#include "LCD.h"


// Constructor
LCD::LCD() {

}

void LCD::moveCursorLine(int line) {
    Serial1.write(254);
    Serial1.write(line == 1 ? 128 : 192);
}

void LCD::clearLine(int line) {
    moveCursorLine(line);
    Serial1.write("                ");
    moveCursorLine(line);
}

void LCD::line1(String text) {
  writeLine(1, text);
}

void LCD::line2(String text) {
  writeLine(2, text);
}

void LCD::writeLine(int line, String text) {
  clearLine(line);
  Serial1.write(text);
}
