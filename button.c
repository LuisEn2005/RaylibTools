#include "button.h"

Color RandomColor(void) {
  return (Color){
      GetRandomValue(0, 255),  // r
      GetRandomValue(0, 255),  // g
      GetRandomValue(0, 255),  // b
      255                      // alpha fijo en 255
  };
}

// Button Struct Functions
void makeButton(Button *button, Rectangle bounds, Color color) {
  setButtonBounds(button, bounds);
  setButtonColor(button, color);
}

Button setButton(Rectangle bounds, Color color) {
  Button button;
  makeButton(&button, bounds, color);
  return button;
}

void setButtonBounds(Button *button, Rectangle vBounds) {
  Rectangle *bounds = &(button->bounds);
  *bounds = (Rectangle){vBounds.x, vBounds.y, vBounds.width, vBounds.height};
  bounds->x -= bounds->width / 2;
  bounds->y -= bounds->height / 2;
}

void setButtonColor(Button *button, Color _color) {
  button->color = _color;
}

void drawButton(Button *button) {
  DrawRectangleRec(button->bounds, button->color);
}

// Input Button Functions
bool inputButton(Button *button) {
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
  drawButton(button);
  return inputButton(button);
}
