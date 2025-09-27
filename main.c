#include <raylib.h>

#include "buttons.h"

Button button1;
TextButton button2;
TextureButton button3;

int main(void) {
  makeButton(&button1, RectangleBounds(400, 300, 60, 100), RED);
  InitWindow(800, 600, "ButtonsRaylib");
  SetTargetFPS(60);
  TextButtonFromButton(&button2, &button1, makeText("NewText", 50, BLUE));
  changeTextButton(&button2, makeText("NewText", 25, GRAY));
  // TextureButtonFromButton(&button3, &button1, "./infopisco.jpeg", WidthHeight(-10, -10));
  MakeTextureButton(&button3, RectangleBounds(400, 300, 400, 600), "./infopisco.jpeg");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    inputTextButton(&button2);
    drawTextButton(&button2);
    DrawTextureButton(&button3);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
