#include "buttons.h"
#include <raylib.h>

Button button1;
TextButton button2;

int main(void) {
  makeButton(&button1, (Vector4){400, 300, 60, 100}, RED);
  InitWindow(800, 600, "ButtonsRaylib");
  SetTargetFPS(60);
  button2 = makeTextButton(&button1, "Wazaaa");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawTextButton(&button2);
    inputButton(&button1);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
