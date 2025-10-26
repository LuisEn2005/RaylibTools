#include <raylib.h>
#include <stdio.h>

#include "buttons/button.h"
#include "buttons/textbutton.h"
#include "buttons/texturebutton.h"

Button button1;
TextButton button2;
TextureButton button3;

int main(void) {
  makeButton(&button1, RectangleBounds(400, 300, 60, 100), RED);
  InitWindow(800, 600, "ButtonsRaylib");
  SetTargetFPS(60);
  // TextButtonFromButton(&button2, &button1, makeText("NewText", 50, BLUE));
  MakeTextButton(&button2, RectangleBounds(400, 300, 60, 100), makeText("NewText", 50, BLUE), RED);
  // changeTextButton(&button2, makeText("NewText", 25, GRAY));
  // TextureButtonFromButton(&button3, &button1, "./VictorTurnick.png", WidthHeight(-10, -10));
  MakeTextureButton(&button3, RectangleBounds(200, 300, -200, -300), "./VictorTurnick.png");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (HandleTextureButton(&button3)) printf("Waza\n");
    if (HandleTextButton(&button2)) printf("Waza\n");
    DrawText("texto", 200, 300, 20, YELLOW);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
