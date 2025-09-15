#include <raylib.h>

#ifndef BUTTONS_H
#define BUTTONS_H

typedef struct Button {
  Rectangle Bounds;
  Color color;
} Button;

Button makeButton(Button *, Vector4, Color);
void drawButton(Button *);

typedef struct Text {
  const char *text;
  int fontSize;
  int textWidth;
  Color textColor;
} Text;

typedef struct TextButton {
  Button button;
  Text textContent;
} TextButton;

TextButton makeTextButton(Button *, Text);
TextButton changeTextButton(TextButton *, Text);
void drawTextButton(TextButton *);

Text makeText(const char *, int, Color);

// Generic functions
Button setButtonBounds(Button *, Vector4);
Button setButtonColor(Button *, Color);
void inputButton(Button *);

#endif // BUTTONS_H
