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

// Text Struct Functions
Text makeText(const char *text, int fontSize, Color color) {
  Text objText;
  objText.text = text;
  objText.fontSize = fontSize;
  objText.textWidth = MeasureText(text, fontSize);
  objText.textColor = color;
  return objText;
}

TextureButton *makeResizedTextureButton(TextureButton *tButton, Button *button, Image image, Vector2 size) {
  tButton->button = *button;
  tButton->sprite = LoadTextureFromImage(image);
  if (size.x != 0 && size.y != 0) {
    resizeTextureButton(tButton, size);
  }
  return tButton;
}

void resizeTextureButton(TextureButton *tButton, Vector2 newSize) {
  Button *buttonRef = &tButton->button;
  setButtonBounds(buttonRef,
                  (Vector4){buttonRef->bounds.x, buttonRef->bounds.y, newSize.x, newSize.y});
  if (tButton->sprite.id != 0) {
    Image image = LoadImageFromTexture(tButton->sprite);
    UnloadTexture(tButton->sprite);
    ImageResize(&image, newSize.x, newSize.y);
    tButton->sprite = LoadTextureFromImage(image);
    UnloadImage(image);
  }
}

void UnloadTextureButton(TextureButton *tButton) {
  if (tButton->sprite.id != 0) {
    UnloadTexture(tButton->sprite);
    tButton->sprite.id = 0;
  }
}
void DrawTextureButton(TextureButton *tButton) {
  Button *button = &(tButton->button);
  Rectangle *bounds = &(tButton->button.bounds);
  Texture2D *texture = &(tButton->sprite);
  drawButton(button);
  DrawTexture(*texture, button->bounds.x, button->bounds.y, WHITE);
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

// Aux functions

Vector2 WidthHeight(int width, int height) {
  return (Vector2){width, height};
}

Vector4 RectangleBounds(int x, int y, int width, int height) {
  return (Vector4){x, y, width, height};
}
