#ifndef TEXT_H
#define TEXT_H

#include <raylib.h>
#include <string.h>

typedef struct Text {
  char text[256];
  int fontSize;
  int textWidth;
  int posX;
  int posY;
  Color textColor;
} Text;

Text MakeText(const char *, int, Color);

#endif  // UTILS_H
