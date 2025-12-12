#include "texturebutton.h"

void TextureWithButton(TextureButton *tButton, Button *base, const char *fileSource, Vector2 size) {
  tButton->base = *base;
  Image image = LoadImage(fileSource);
  tButton->sprite = LoadTextureFromImage(image);
  UnloadImage(image);
  if (size.x != 0 && size.y != 0) {
    ResizeTextureButton(tButton, size);
  } else {
    Rectangle *bounds = &tButton->base.bounds;
    Button *btn = &tButton->base;
    Texture2D *sprite = &tButton->sprite;
    float centerX = bounds->x + bounds->width / 2;
    float centerY = bounds->y + bounds->height / 2;
    setButtonBounds(btn, RectangleBounds(centerX, centerY, sprite->width, sprite->height));
  }
}

void MakeTextureButton(TextureButton *tButton, Rectangle rBounds, const char *fileSource) {
  Button base = setButton(rBounds, BLANK);
  TextureWithButton(tButton, &base, fileSource, (Vector2){base.bounds.width, base.bounds.height});
}

void ResizeTextureButton(TextureButton *tButton, Vector2 newSize) {
  Rectangle *bounds = &tButton->base.bounds;
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
      newSize.x < 0 ? ImageFlipHorizontal(&image) : ImageFlipVertical(&image);
      newSize.x < 0 ? (newSize.x *= -1) : (newSize.y *= -1);
    }
    setButtonBounds(&tButton->base, RectangleBounds(centerX, centerY, newSize.x, newSize.y));
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
  Button *base = &(tButton->base);
  Texture2D *texture = &(tButton->sprite);
  drawButton(base);
  DrawTexture(*texture, base->bounds.x, base->bounds.y, WHITE);
}

bool inputTextureButton(TextureButton *tButton) {
  return inputButton(&tButton->base);
}

bool HandleTextureButton(TextureButton *tButton) {
  DrawTextureButton(tButton);
  return inputTextureButton(tButton);
}
