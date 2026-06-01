#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>

typedef struct Button {
  Rectangle bounds;
  Color colorNormal;
  Color colorHover;
  Color colorPressed;
} Button;

void MakeButton(Button *, Rectangle, Color);
Button SetButton(Rectangle, Color);
void SetButtonBounds(Button *, Rectangle);
void SetButtonColor(Button *, Color);
void DrawButton(Button *);

// Input functions
bool InputButton(Button *);

// Aux functions
Vector2 WidthHeight(int, int);
Rectangle RectangleBounds(int, int, int, int);
bool HandleButton(Button *);

#endif  // BUTTONS_H
