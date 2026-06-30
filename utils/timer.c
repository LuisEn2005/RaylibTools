#include "timer.h"

void TimerStart(Timer *t, float seconds){
  t->finished = false;
  t->duration = seconds;
  t->elapsed = 0.0f;
}

void TimerUpdate(Timer *t){
  if(t->finished) return;

  t->elapsed += GetFrameTime();

  if(t->elapsed >= t->duration) {
    t->finished = true;
    t->elapsed = t->duration;
  }
}

bool TimerDone(Timer *t){
  return t->finished;
}

void TimerReset(Timer *t){
  t->elapsed = 0.0f;
  t->finished = false;
}
