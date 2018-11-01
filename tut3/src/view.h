#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>

#include "../../mvc.h"
#include "model.h"

using namespace std;

#if !defined(VIEW)
#define VIEW

#define ROWS 7
#define COLS 5

class View : public AbstractView<Ampel>
{
  private:
    char *matrix2d[ROWS];

  public:
    View();
    void render(Ampel state);
};

View::View()
{
    ifstream file("..\\ampel.dat");

    int i = 0;
    for (std::string line; getline(file, line);)
    {
        if (i < ROWS)
        {
            matrix2d[i] = new char[COLS];
            strncpy(matrix2d[i], line.c_str(), sizeof(matrix2d[i]));
            i++;
        }
    }

    file.close();
};

void View::render(Ampel state)
{
    if (!state.isOn)
    {
        cout << "Ampel ist AUS." << endl;
        return;
    }

    system("cls");

    int posY;
    switch (state.color)
    {
    case GREEN:
        posY = ROWS - 2;
        break;
    case YELLOW:
        posY = ROWS - 4;
        break;
    case RED:
    default:
        posY = 1;
    }

    for (int i = 0; i < ROWS; i++)
    {
        char *line = matrix2d[i];
        int posX = round(COLS / 2);

        if (posY == i)
        {
            line[posX] = 'X';
        }
        else if (i % 2 == 0)
        {
            line[posX] = '=';
        }
        else
        {
            line[posX] = ' ';
        }

        cout << line << endl;
    }
};

#endif // VIEW