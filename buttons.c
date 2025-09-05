#include "buttons.h"

Color RandomColor(void) {
  return (Color){
      GetRandomValue(0, 255), // r
      GetRandomValue(0, 255), // g
      GetRandomValue(0, 255), // b
      255                     // alpha fijo en 255
  };
}

// Button Struct Functions
Button makeButton(Button *button, Vector4 bounds, Color _color) {
  setButtonBounds(button, bounds);
  setButtonColor(button, _color);
  return *button;
}

void drawButton(Button *button) {
  DrawRectangleRec(button->Bounds, button->color);
}

// TextButton Struct Functions
TextButton makeTextButton(Button *button, const char *text) {
  TextButton tButton;
  tButton.button = *button;
  tButton.text = text;
  return tButton;
}

void drawTextButton(TextButton *tButton) {
  int textSize = MeasureText(tButton->text, 10);

  drawButton(&tButton->button);
  DrawText(tButton->text, tButton->button.Bounds.x, tButton->button.Bounds.y,
           10, WHITE);
}

// General Button Functions
Button setButtonBounds(Button *button, Vector4 bounds) {
  button->Bounds = (Rectangle){bounds.x, bounds.y, bounds.z, bounds.w};
  button->Bounds.x -= button->Bounds.width / 2;
  button->Bounds.y -= button->Bounds.height / 2;
  return *button;
}

Button setButtonColor(Button *button, Color _color) {
  button->color = _color;
  return *button;
}

void inputButton(Button *button) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
      CheckCollisionPointRec(GetMousePosition(), button->Bounds)) {
    setButtonColor(button, RandomColor());
  }
}
