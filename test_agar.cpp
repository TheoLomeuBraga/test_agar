#include <agar/core.h>
#include <agar/gui.h>

#include <iostream>

AG_Window *win;

uint32_t update_loop(AG_Timer *timer, AG_Event *event)
{
  std::cout << "Hello, world!\n";
  AG_AddTimerAuto(win, 1, update_loop, NULL);
  return 0;
}

int main(int argc, char **argv)
{

  if (AG_InitCore(NULL, 0) == -1 ||
      AG_InitGraphics(0) == -1)
  {
    return (1);
  }

  win = AG_WindowNew(0);
  AG_LabelNew(win, 0, "Hello, world!");
  AG_WindowShow(win);

  AG_AddTimerAuto(win, 1, update_loop, NULL);

  AG_EventLoop();
  return 0;
}
