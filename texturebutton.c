#include "texturebutton.h"

void TextureButtonFromButton(TextureButton *tButton, Button *button, const char *fileSource, Vector2 size) {
  tButton->button = *button;
  Image image = LoadImage(fileSource);
  tButton->sprite = LoadTextureFromImage(image);
  UnloadImage(image);
  if (size.x != 0 && size.y != 0) {
    resizeTextureButton(tButton, size);
  } else {
    Rectangle *bounds = &tButton->button.bounds;
    Button *btn = &tButton->button;
    Texture2D *sprite = &tButton->sprite;
    float centerX = bounds->x + bounds->width / 2;
    float centerY = bounds->y + bounds->height / 2;
    setButtonBounds(btn, RectangleBounds(centerX, centerY, sprite->width, sprite->height));
  }
}

void MakeTextureButton(TextureButton *tButton, Rectangle rBounds, const char *fileSource) {
  Button button = setButton(rBounds, BLANK);
  TextureButtonFromButton(tButton, &button, fileSource, (Vector2){button.bounds.width, button.bounds.height});
}

void resizeTextureButton(TextureButton *tButton, Vector2 newSize) {
  Rectangle *bounds = &tButton->button.bounds;
  float centerX = bounds->x + bounds->width / 2;
  float centerY = bounds->y + bounds->height / 2;

  if (tButton->sprite.id != 0) {
    Image image = LoadImageFromTexture(tButton->sprite);
    UnloadTexture(tButton->sprite);
    if (newSize.x < 0 && newSize.y < 0) {
      newSize.x *= -1;
      newSize.y *= -1;
      ImageFlipHorizontal(&image);
      ImageFlipVertical(&image);
    } else if (newSize.x < 0 || newSize.y < 0) {
      newSize.x < 0 ? (newSize.x *= -1) : (newSize.y *= -1);
      newSize.x < 0 ? ImageFlipHorizontal(&image) : ImageFlipVertical(&image);
    }
    setButtonBounds(&tButton->button, RectangleBounds(centerX, centerY, newSize.x, newSize.y));
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
  Texture2D *texture = &(tButton->sprite);
  drawButton(button);
  DrawTexture(*texture, button->bounds.x, button->bounds.y, WHITE);
}

bool inputTextureButton(TextureButton *tButton) {
  return inputButton(&tButton->button);
}

bool HandleTextureButton(TextureButton *tButton) {
  DrawTextureButton(tButton);
  return inputTextureButton(tButton);
}
