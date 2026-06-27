#ifndef SCREEN_H
#define SCREEN_H

#include <raylib.h>

typedef void (*SceneFn)(void);

typedef struct Scene{
  SceneFn update;
  SceneFn draw;
} Scene;

void RunScene(Scene* scene);
void SwitchScene(Scene* next);

#endif //SCREEN_H
