#include <raylib.h>

#include "button.h"

#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

typedef struct Text {
  const char *text;
  int fontSize;
  int textWidth;
  int posX;
  int posY;
  Color textColor;
} Text;

Text makeText(const char *, int, Color);

typedef struct TextButton {
  Button button;
  Text textContent;
} TextButton;

void TextButtonFromButton(TextButton *, Button *, Text);
void MakeTextButton(TextButton *, Rectangle, Text, Color);
void changeTextButton(TextButton *, Text);
void changeTextColor(TextButton *, Color);
void drawTextButton(TextButton *);

bool inputTextButton(TextButton *);
bool HandleTextButton(TextButton *);

#endif  // TEXTBUTTON_H
