#include "buttons.h"

Color RandomColor(void) {
  return (Color){
      GetRandomValue(0, 255),  // r
      GetRandomValue(0, 255),  // g
      GetRandomValue(0, 255),  // b
      255                      // alpha fijo en 255
  };
}

// Button Struct Functions
Button *makeButton(Button *button, Vector4 bounds, Color _color) {
  setButtonBounds(button, bounds);
  setButtonColor(button, _color);
  return button;
}

void setButtonBounds(Button *button, Vector4 vBounds) {
  Rectangle *bounds = &(button->bounds);
  *bounds = (Rectangle){vBounds.x, vBounds.y, vBounds.z, vBounds.w};
  bounds->x -= bounds->width / 2;
  bounds->y -= bounds->height / 2;
}

void setButtonColor(Button *button, Color _color) {
  button->color = _color;
}

void drawButton(Button *button) {
  DrawRectangleRec(button->bounds, button->color);
}

// aux functions for makeTextButton
int setPadding(TextButton *tButton, Text *txt) {
  int padding = txt->fontSize / 2;
  txt->textWidth = MeasureText(txt->text, txt->fontSize);
  return padding;
}

void fitButtonToText(TextButton *tButton, int padding, Text *txt, Rectangle *bounds) {
  bounds->width = txt->textWidth + padding;
  bounds->height = txt->fontSize;  // fontSize ≈ height
}

void centerTextInButton(TextButton *tButton, Text *txt, Rectangle *bounds) {
  txt->posX = bounds->x + (bounds->width - txt->textWidth) / 2;
  txt->posY = bounds->y + (bounds->height - txt->fontSize) / 2;
}

// TextButton Struct Functions
TextButton *makeTextButton(TextButton *tButton, Button *button, Text text) {
  Text *txt = &tButton->textContent;
  Rectangle *bounds = &tButton->button.bounds;

  tButton->button = *button;
  *txt = text;

  int padding = setPadding(tButton, txt);
  fitButtonToText(tButton, padding, txt, bounds);
  centerTextInButton(tButton, txt, bounds);

  return tButton;
}

TextButton *changeTextButton(TextButton *tButton, Text newText) {
  Button *button = &(tButton->button);
  makeTextButton(tButton, button, newText);
  return tButton;
}

void drawTextButton(TextButton *tButton) {
  Button *button = &(tButton->button);
  Text *text = &(tButton->textContent);
  drawButton(button);
  DrawText(text->text, text->posX, text->posY,
           text->fontSize, text->textColor);
}

Text makeText(const char *text, int fontSize, Color color) {
  Text objText;
  objText.text = text;
  objText.fontSize = fontSize;
  objText.textWidth = MeasureText(text, fontSize);
  objText.textColor = color;
  return objText;
}

// Input Button Functions
bool inputButton(Button *button) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
      CheckCollisionPointRec(GetMousePosition(), button->bounds)) {
    return true;
  }
  return false;
}

bool inputTextButton(TextButton *tButton) {
  return inputButton(&tButton->button);
}
