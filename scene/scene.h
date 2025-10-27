#include <raylib.h>

#include "../buttons/textbutton.h"
#include "../buttons/texturebutton.h"

#ifndef SCENE_H
#define SCENE_H

typedef struct Scene {
  Texture2D* textures;
  // Text* texts;
  TextButton* textbuttons;
  TextureButton* texturebuttons;
  Texture2D* sprites;
} Scene;

void MakeScene(Scene*);

#endif  // SCENE_H
