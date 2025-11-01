#include "textbutton.h"

// aux functions for makeTextButton
int setPadding(TextButton *tButton, Text *txt) {
  int padding = txt->fontSize / 2;
  txt->textWidth = MeasureText(txt->text, txt->fontSize);
  return padding;
}

void fitButtonToText(TextButton *tButton, int padding, Text *txt, Rectangle *bounds) {
  float width = txt->textWidth + padding;
  float height = txt->fontSize;  // fontSize ≈ height
  float centerX = bounds->x + bounds->width / 2;
  float centerY = bounds->y + bounds->height / 2;
  setButtonBounds(&tButton->button, RectangleBounds(centerX, centerY, width, height));
}

void centerTextInButton(TextButton *tButton, Text *txt, Rectangle *bounds) {
  txt->posX = bounds->x + (bounds->width - txt->textWidth) / 2;
  txt->posY = bounds->y + (bounds->height - txt->fontSize) / 2;
}

// TextButton Struct Functions
void TextButtonFromButton(TextButton *tButton, Button *button, Text text) {
  Text *txt = &tButton->textContent;
  Rectangle *bounds = &tButton->button.bounds;

  tButton->button = *button;
  *txt = text;

  int padding = setPadding(tButton, txt);
  fitButtonToText(tButton, padding, txt, bounds);
  centerTextInButton(tButton, txt, bounds);
}

void MakeTextButton(TextButton *tButton, Rectangle rBounds, Text text, Color bgColor) {
  Button button = setButton(rBounds, bgColor);
  TextButtonFromButton(tButton, &button, text);
}

void ChangeTextButton(TextButton *tButton, Text newText) {
  Button *button = &(tButton->button);
  TextButtonFromButton(tButton, button, newText);
}

void ChangeTextColor(TextButton *tButton, Color color) {
  tButton->textContent.textColor = color;
}

void DrawTextButton(TextButton *tButton) {
  Button *button = &(tButton->button);
  Text *text = &(tButton->textContent);
  drawButton(button);
  DrawText(text->text, text->posX, text->posY, text->fontSize, text->textColor);
}

bool InputTextButton(TextButton *tButton) {
  return inputButton(&tButton->button);
}

bool HandleTextButton(TextButton *tButton) {
  DrawTextButton(tButton);
  return InputTextButton(tButton);
}
