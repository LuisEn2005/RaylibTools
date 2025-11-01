#include "scene.h"

void MakeScene(Scene* newScene) {
  newScene->textures = 0;
  newScene->nTextures = 0;
  newScene->texts = 0;
  newScene->textbuttons = 0;
  newScene->ntbuttons = 0;
  newScene->texturebuttons = 0;
  newScene->nttbuttons = 0;
  newScene->sprites = 0;
}

void FreeScene(Scene* scene) {
  free(scene->textures);
  free(scene->textbuttons);
  free(scene->texturebuttons);
  free(scene->sprites);
}

void DrawScene(Scene* scene) {
  for (int i = 0; i != 0; i++) {
    HandleTextButton(&scene->textbuttons[i]);
  }
  for (int i = 0; i != 0; i++) {
    HandleTextureButton(&scene->texturebuttons[i]);
  }
}
