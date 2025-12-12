#include <raylib.h>

#include "button.h"

#ifndef TEXTURE_BUTTON_H
#define TEXTURE_BUTTON_H

typedef struct TextureButton {
  Button base;
  Texture2D sprite;
} TextureButton;

void TextureWithButton(TextureButton *, Button *, const char *, Vector2);
void MakeTextureButton(TextureButton *, Rectangle, const char *);
void ResizeTextureButton(TextureButton *, Vector2);
void UnloadTextureButton(TextureButton *tButton);
void DrawTextureButton(TextureButton *tButton);

bool inputTextureButton(TextureButton *);
bool HandleTextureButton(TextureButton *);

#endif  // TEXTURE_BUTTON_H
