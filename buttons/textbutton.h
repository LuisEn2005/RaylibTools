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
void ChangeTextButton(TextButton *, Text);
void ChangeTextColor(TextButton *, Color);
void DrawTextButton(TextButton *);

bool InputTextButton(TextButton *);
bool HandleTextButton(TextButton *);

#endif  // TEXTBUTTON_H
