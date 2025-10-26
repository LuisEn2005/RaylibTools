#include <raylib.h>

#ifndef BUTTON_H
#define BUTTON_H

typedef struct Button {
  Rectangle bounds;
  Color color;
} Button;

void makeButton(Button *, Rectangle, Color);
Button setButton(Rectangle, Color);
void setButtonBounds(Button *, Rectangle);
void setButtonColor(Button *, Color);
void drawButton(Button *);

// Input functions
bool inputButton(Button *);

// Aux functions
Vector2 WidthHeight(int, int);
Rectangle RectangleBounds(int, int, int, int);
bool HandleButton(Button *);

#endif  // BUTTONS_H
