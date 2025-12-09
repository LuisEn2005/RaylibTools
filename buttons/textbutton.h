#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H
#include <raylib.h>

#include "../utils/text.h"
#include "button.h"

typedef struct TextButton {
  Button button;
  Text textContent;
} TextButton;

void MakeInputText(TextButton *, Rectangle, Text);
void MakeTextButton(TextButton *, Rectangle, Text, Color);
void ChangeTextButton(TextButton *, Text);
void ChangeTextColor(TextButton *, Color);
void DrawTextButton(TextButton *);

bool InputTextButton(TextButton *);

#endif  // TEXTBUTTON_H
