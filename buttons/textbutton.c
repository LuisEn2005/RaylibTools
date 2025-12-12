#include "textbutton.h"

// aux functions for makeTextButton
int setPadding(Text *txt) {
  int padding = txt->fontSize / 2;
  txt->textWidth = MeasureText(txt->text, txt->fontSize);
  return padding;
}

void fitButtonToText(TextButton *tButton, int padding, Text *txt, Rectangle *bounds) {
  float width = txt->textWidth + padding;
  float height = txt->fontSize;  // fontSize ≈ height
  float centerX = bounds->x + bounds->width / 2;
  float centerY = bounds->y + bounds->height / 2;
  setButtonBounds(&tButton->base, RectangleBounds(centerX, centerY, width, height));
}

void centerTextInButton(Text *txt, Rectangle *bounds) {
  txt->posX = bounds->x + (bounds->width - txt->textWidth) / 2;
  txt->posY = bounds->y + (bounds->height - txt->fontSize) / 2;
}

// TextButton Struct Functions
void TextButtonFromButton(TextButton *tButton, Button *base, Text text) {
  Text *txt = &tButton->textContent;
  Rectangle *bounds = &tButton->base.bounds;

  tButton->base = *base;
  *txt = text;

  int padding = setPadding(txt);
  fitButtonToText(tButton, padding, txt, bounds);
  centerTextInButton(txt, bounds);
}

void MakeInputText(TextButton *ITButton, Rectangle rBounds, Text text) {
  Button base = setButton(rBounds, (Color){100, 100, 100, 125});
  TextButtonFromButton(ITButton, &base, text);
}

void MakeTextButton(TextButton *tButton, Rectangle rBounds, Text text, Color bgColor) {
  Button base = setButton(rBounds, bgColor);
  TextButtonFromButton(tButton, &base, text);
}

void ChangeTextButton(TextButton *tButton, Text newText) {
  Button *base = &(tButton->base);
  TextButtonFromButton(tButton, base, newText);
}

void ChangeTextColor(TextButton *tButton, Color color) {
  tButton->textContent.textColor = color;
}

void DrawTextButton(TextButton *tButton) {
  Button *base = &(tButton->base);
  Text *text = &(tButton->textContent);
  drawButton(base);
  DrawText(text->text, text->posX, text->posY, text->fontSize, text->textColor);
}

bool InputTextButton(TextButton *tButton) {
  return inputButton(&tButton->base);
}
