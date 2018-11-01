/*
*   View
*     stellt den State dar
*   
*   by Armin Butkereit
*/

#include <windows.h>

class Viewport
{
public:
  int width, height, columns, rows;
  Viewport()
  {
    readTerminalSize();
  };
  Viewport(int w, int h)
  {
    width = w;
    height = h;
    readTerminalSize();
  };

  void readTerminalSize()
  {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  };
};

template <class State>
class AbstractView
{
protected:
  Viewport viewport;

public:
  AbstractView(Viewport vp)
  {
    viewport = vp;
  };
  AbstractView(){};
  void setViewport(Viewport vp)
  {
    viewport = vp;
  };
  virtual void render(State *state) = 0;
};