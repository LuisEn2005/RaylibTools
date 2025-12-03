#include <raylib.h>

#include "../utils/text.h"
#include "button.h"

#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

typedef struct TextButton {
  Button button;
  Text textContent;
} TextButton;

void MakeTextButton(TextButton *, Rectangle, Text, Color);
void ChangeTextButton(TextButton *, Text);
void ChangeTextColor(TextButton *, Color);
void DrawTextButton(TextButton *);

bool InputTextButton(TextButton *);
bool HandleTextButton(TextButton *);

#endif  // TEXTBUTTON_H
