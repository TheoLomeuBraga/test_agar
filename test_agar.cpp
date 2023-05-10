#include <agar/core.h>
#include <agar/gui.h>

#include <iostream>

AG_Window *win;

AG_Button *button;

uint32_t update_loop(AG_Timer *timer, AG_Event *event)
{
  std::cout << "Hello, world!\n";
  AG_AddTimerAuto(win, 1, update_loop, NULL);
  return 0;
}

void button_function(AG_Event *evento)
{
    AG_TextMsg(AG_MSG_INFO, "bunnton!");
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

  button = AG_ButtonNewFn(win, 0, "Hello maçãn", button_function, "%s", "world");

  AG_AddTimerAuto(win, 1, update_loop, NULL);

  AG_EventLoop();
  return 0;
}
