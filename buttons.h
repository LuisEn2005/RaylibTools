#include <raylib.h>

#ifndef BUTTONS_H
#define BUTTONS_H

typedef struct Button {
  Rectangle bounds;
  Color color;
} Button;

Button *makeButton(Button *, Vector4, Color);
void setButtonBounds(Button *, Vector4);
void setButtonColor(Button *, Color);
void drawButton(Button *);

typedef struct Text {
  const char *text;
  int fontSize;
  int textWidth;
  int posX;
  int posY;
  Color textColor;
} Text;

Text makeText(const char *, int, Color);

typedef struct TextButton {
  Button button;
  Text textContent;
} TextButton;

TextButton *makeTextButton(TextButton *, Button *, Text);
TextButton *changeTextButton(TextButton *, Text);
void changeTextColor(TextButton *, Color);
void drawTextButton(TextButton *);

typedef struct TextureButton {
  Button button;
  Texture2D sprite;
} TextureButton;

TextureButton *makeResizedTextureButton(TextureButton *, Button *, Image, Vector2);
void resizeTextureButton(TextureButton *, Vector2);
void UnloadTextureButton(TextureButton *tButton);
void DrawTextureButton(TextureButton *tButton);

// Input functions
bool inputButton(Button *);
bool inputTextButton(TextButton *);

// Aux functions
Vector2 WidthHeight(int, int);
Vector4 RectangleBounds(int, int, int, int);

#endif  // BUTTONS_H
