#include <raylib.h>

#ifndef BUTTONS_H
#define BUTTONS_H

typedef struct Button {
  Rectangle bounds;
  Color color;
} Button;

Button *makeButton(Button *, Vector4, Color);
void setButtonBounds(Button *, Vector4);
void setButtonColor(Button *, Color);
void drawButton(Button *);

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

TextButton *makeTextButton(TextButton *, Button *, Text);
TextButton *changeTextButton(TextButton *, Text);
void changeTextColor(TextButton *, Color);
void drawTextButton(TextButton *);

typedef struct textureButton {
  Button button;
  Texture2D sprite;
} textureButton;

// Input functions
bool inputButton(Button *);
bool inputTextButton(TextButton *);

#endif  // BUTTONS_H
