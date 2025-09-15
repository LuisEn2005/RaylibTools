#include "buttons.h"
#include <raylib.h>

Button button1;
TextButton button2;

int main(void) {
  makeButton(&button1, (Vector4){200, 300, 60, 100}, RED);
  InitWindow(800, 600, "ButtonsRaylib");
  SetTargetFPS(60);
  button2 =
      makeTextButton(&button1, makeText("asfanfijafjafjabifabwo", 50, BLUE));
  changeTextButton(&button2, makeText("NewText", 25, GRAY));
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    inputButton(&button2.button);
    drawTextButton(&button2);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
