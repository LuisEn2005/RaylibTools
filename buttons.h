#include <raylib.h>

#ifndef BUTTONS_H
#define BUTTONS_H

typedef struct Button {
  Rectangle bounds;
  Color color;
} Button;

void makeButton(Button *, Rectangle, Color);
Button setButton(Rectangle, Color);
void setButtonBounds(Button *, Rectangle);
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

void TextButtonFromButton(TextButton *, Button *, Text);
void MakeTextButton(TextButton *, Rectangle, Text, Color);
void changeTextButton(TextButton *, Text);
void changeTextColor(TextButton *, Color);
void drawTextButton(TextButton *);

typedef struct TextureButton {
  Button button;
  Texture2D sprite;
} TextureButton;

void TextureButtonFromButton(TextureButton *, Button *, const char *, Vector2);
void MakeTextureButton(TextureButton *, Rectangle, const char *);
void resizeTextureButton(TextureButton *, Vector2);
void UnloadTextureButton(TextureButton *tButton);
void DrawTextureButton(TextureButton *tButton);

// Input functions
bool inputButton(Button *);
bool inputTextButton(TextButton *);
bool inputTextureButton(TextureButton *);

// Aux functions
Vector2 WidthHeight(int, int);
Rectangle RectangleBounds(int, int, int, int);
bool HandleButton(Button *);
bool HandleTextButton(TextButton *);
bool HandleTextureButton(TextureButton *);

#endif  // BUTTONS_H
