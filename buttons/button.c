#include "button.h"

/*
static Color RandomColor(void) {
  return (Color){
      GetRandomValue(0, 255),  // r
      GetRandomValue(0, 255),  // g
      GetRandomValue(0, 255),  // b
      255                      // alpha fijo en 255
  };
}
*/

// Button Struct Functions
void MakeButton(Button *button, Rectangle bounds, Color color) {
  SetButtonBounds(button, bounds);
  SetButtonColor(button, color);
}

Button SetButton(Rectangle bounds, Color color) {
  Button button;
  MakeButton(&button, bounds, color);
  return button;
}

void SetButtonBounds(Button *button, Rectangle vBounds) {
  Rectangle *bounds = &(button->bounds);
  *bounds = (Rectangle){vBounds.x, vBounds.y, vBounds.width, vBounds.height};
  bounds->x -= bounds->width / 2;
  bounds->y -= bounds->height / 2;
}

void SetButtonColor(Button *button, Color _color) {
  button->colorNormal = _color;
}

void DrawButton(Button *b) {
  Color c = b->colorNormal;
  if (CheckCollisionPointRec(GetMousePosition(), b->bounds)) {
    c = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? b->colorPressed : b->colorHover;
  }
  DrawRectangleRec(b->bounds, c);
}

// Input Button Functions
bool InputButton(Button *button) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
      CheckCollisionPointRec(GetMousePosition(), button->bounds)) {
    return true;
  }
  return false;
}

// Aux functions

Vector2 WidthHeight(int width, int height) {
  return (Vector2){width, height};
}

Rectangle RectangleBounds(int x, int y, int width, int height) {
  return (Rectangle){x, y, width, height};
}

bool HandleButton(Button *button) {
  DrawButton(button);
  return InputButton(button);
}

