#include <raylib.h>

#include "buttons.h"

Button button1;
TextButton button2;
TextureButton button3;

int main(void) {
  makeButton(&button1, RectangleBounds(200, 300, 60, 100), RED);
  InitWindow(800, 600, "ButtonsRaylib");
  SetTargetFPS(60);
  makeTextButton(&button2, &button1, makeText("asfanfijafjafjabifabwo", 50, BLUE));
  changeTextButton(&button2, makeText("NewText", 25, GRAY));
  makeResizedTextureButton(&button3, &button1, LoadImage("./infopisco.jpeg"), WidthHeight(100, 200));
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    inputTextButton(&button2);
    drawTextButton(&button2);
    // DrawTextureButton(&button3);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
