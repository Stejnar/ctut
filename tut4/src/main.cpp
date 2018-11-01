#include "controller.h"

using namespace std;

#define MENU 0
#define GAME 1
#define SCORES 2
#define EXIT 3

#define ENTER 13
#define S 115
#define E 101

void menu(int *p)
{
    system("cls");

    cout << "Main menu" << endl
         << endl
         << "[Enter] to start game" << endl
         << "[S] to view scores" << endl
         << "[E] to exit" << endl;

    switch (getch())
    {
    case ENTER:
        *p = GAME;
        break;
    case S:
        *p = SCORES;
        break;
    case E:
        *p = EXIT;
        break;
    }
}

void scores()
{
    ifstream file("scores.dat");

    system("cls");

    cout << "Press any key to go back to main menu" << endl
         << endl;

    for (string line; getline(file, line);)
    {
        cout << line << endl;
    }

    getch();
}

void game()
{
    Snake state;
    Model model(&state);
    View view;
    Controller ctrl(&model, &view);

    ctrl.start();

    while (!model.getState()->info.gameOver)
    {
        ctrl.update();
    }

    ctrl.stop();
}

int main()
{
    int p = MENU;

    while (p != EXIT)
    {
        switch (p)
        {
        case MENU:
            menu(&p);
            break;
        case GAME:
            game();
            p = MENU;
            break;
        case SCORES:
            scores();
            p = MENU;
            break;
        }
    }

    return 0;
}