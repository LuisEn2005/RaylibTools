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
TextButton makeTextButton(Button *button, Text text) {
  TextButton tButton;
  tButton.button = *button;
  tButton.textButton = text;
  tButton.textButton.textWidth =
      MeasureText(tButton.textButton.text, tButton.textButton.fontSize);
  return tButton;
}
/*
TextButton changeTextButton(TextButton *button, const char *newText) {
  button->text = newText;
  button->
  return button;
}
*/
void drawTextButton(TextButton *tButton) {
  drawButton(&tButton->button);
  DrawText(tButton->textButton.text, tButton->button.Bounds.x,
           tButton->button.Bounds.y, tButton->textButton.fontSize,
           tButton->textButton.textColor);
}

Text makeText(const char *text, int fontSize, Color color) {
  Text objText;
  objText.text = text;
  objText.fontSize = fontSize;
  objText.textWidth = MeasureText(text, fontSize);
  objText.textColor = color;
  return objText;
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
