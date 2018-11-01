#if !defined(VIEW)
#define VIEW

#include <iostream>

#include "../../mvc/mvc.h"
#include "model.h"

class View : public AbstractView<Snake>, public Observer<Tupel>
{
  private:
    char **matrix2d;
    char **screen;

  public:
    View(Viewport _viewport);
    View(){};
    ~View()
    {
        free(matrix2d);
    };
    void next(Tupel value, int index);
    void render(Snake *state);
    void clearBoard();
    void initMatrix(Viewport viewport);
};

View::View(Viewport _viewport)
{
    viewport = _viewport;
};

void View::initMatrix(Viewport viewport)
{
    matrix2d = new char *[viewport.height];
    for (int i = 0; i < viewport.height; i++)
    {
        matrix2d[i] = new char[viewport.width];
    }

    screen = new char *[viewport.rows];
    for (int i = 0; i < viewport.rows; i++)
    {
        screen[i] = new char[viewport.columns];
    }
};

void View::clearBoard()
{
    for (int i = 0; i < viewport.height; i++)
    {
        for (int j = 0; j < viewport.width; j++)
        {
            matrix2d[i][j] = ' ';
        }
    }
};

void View::next(Tupel value, int index)
{
    int x, y;
    x = (int)round(value.x) % viewport.width;
    y = (int)round(value.y) % viewport.height;
    matrix2d[y][x] = 'O';
};

void View::render(Snake *state)
{
    if (!state->info.shouldUpdate)
    {
        return;
    }

    // clear screen
    system("cls");
    clearBoard();

    // set fruit
    matrix2d[(int)state->fruit.y][(int)state->fruit.x] = 'X';

    // set blocks
    state->blocks.forEach(this);

    // render board
    int diff_w = (int)ceil((float)max(0, viewport.columns - viewport.width) / 2);
    int diff_h = (int)ceil((float)max(0, viewport.rows - viewport.height) / 2);

    for (int i = 0; i < viewport.rows; i++)
    {
        for (int j = 0; j < viewport.columns - 1; j++)
        {
            bool outside_h = i < diff_h - 1 || i > viewport.rows - diff_h + 1,
                 outside_w = j < diff_w - 1 || j > viewport.columns - diff_w + 1,
                 border_h = i == diff_h - 1 || i == viewport.rows - diff_h + 1,
                 border_w = j == diff_w - 1 || j == viewport.columns - diff_w + 1;
            if (
                (outside_h && !outside_w) ||
                (outside_w && !outside_h))
            {
                screen[i][j] = ' ';
            }
            else if (border_h && !outside_w)
            {
                screen[i][j] = '-';
            }
            else if (border_w && !outside_h)
            {
                screen[i][j] = '|';
            }
            else
            {
                int x, y;
                y = max(0, min(viewport.height - 1, i - diff_h));
                x = max(0, min(viewport.width - 1, j - diff_w));
                screen[i][j] = matrix2d[y][x];
            }
        }
        screen[i][viewport.columns - 1] = '\0';
        std::cout << screen[i] << std::endl;
    }

    state->info.shouldUpdate = false;
};

#endif // VIEW
