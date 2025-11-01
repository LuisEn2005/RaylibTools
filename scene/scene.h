#include <raylib.h>
#include <stdlib.h>

#include "../buttons/textbutton.h"
#include "../buttons/texturebutton.h"
#include "../utils/text.h"

#ifndef SCENE_H
#define SCENE_H

typedef struct Scene {
  Texture2D* textures;
  int nTextures;
  Text* texts;
  TextButton* textbuttons;
  int ntbuttons;
  TextureButton* texturebuttons;
  int nttbuttons;
  Texture2D* sprites;
  int nsprites;
} Scene;

void MakeScene(Scene*);
void FreeScene(Scene*);
void DrawScene(Scene*);

#endif  // SCENE_H
