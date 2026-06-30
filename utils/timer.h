#ifndef TIMER_H
#define TIMER_H

#include <raylib.h>

typedef struct Timer {
  float duration;
  float elapsed;
  bool finished;
} Timer;

void TimerStart(Timer *t, float seconds);
void TimerUpdate(Timer *t);
bool TimerDone(Timer *t);
void TimerReset(Timer *t);

#endif //TIMER_H
