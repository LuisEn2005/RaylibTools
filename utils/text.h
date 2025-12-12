#ifndef TEXT_H
#define TEXT_H

#include <raylib.h>
#include <string.h>

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
