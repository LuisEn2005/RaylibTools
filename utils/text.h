#include <raylib.h>

#ifndef UTILS_H
#define UTILS_H

typedef struct Text {
  const char *text;
  int fontSize;
  int textWidth;
  int posX;
  int posY;
  Color textColor;
} Text;

Text makeText(const char *, int, Color);

#endif  // UTILS_H
