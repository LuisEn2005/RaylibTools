#include <raylib.h>

#ifndef BUTTONS_H
#define BUTTONS_H

typedef struct Button {
  // float posX, posY, width, height;
  Rectangle Bounds;
  Color color;
} Button;

Button makeButton(Button *, Vector4, Color);
void drawButton(Button *);

typedef struct TextButton {
  Button button;
  const char *text;
} TextButton;

TextButton makeTextButton(Button *, const char *);
TextButton changeTextButton(Button *, const char *);
void drawTextButton(TextButton *);

// Generic functions
Button setButtonBounds(Button *, Vector4);
Button setButtonColor(Button *, Color);
void inputButton(Button *);

#endif // BUTTONS_H
