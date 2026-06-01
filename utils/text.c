#include "text.h"

// Text Struct Functions
Text MakeText(const char *text, int fontSize, Color color) {
  Text objText;
  strncpy(objText.text, text, 255);
  objText.text[255] = '\0';
  objText.fontSize = fontSize;
  objText.textWidth = MeasureText(text, fontSize);
  objText.textColor = color;
  return objText;
}
