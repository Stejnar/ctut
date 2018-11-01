#include <fstream>
#include <iostream>
#include "view.h"

#if !defined(SETTINGS)
#define SETTINGS

#define VELOCITY 0
#define WIDTH 1
#define HEIGHT 2

struct Settings
{
    Viewport viewport;
    int velocity;
};

using namespace std;

int readValue(string str)
{
    return stoi(str.substr(str.find('=') + 1), nullptr);
}

void readSettings(Settings *settings)
{
    ifstream file("settings.dat");

    Viewport viewport;
    int i = 0;

    for (string line; getline(file, line);)
    {
        int value = readValue(line);
        std::cout << value << std::endl;
        switch (i)
        {
        case VELOCITY:
            settings->velocity = value;
            break;
        case WIDTH:
            viewport.width = value;
            break;
        case HEIGHT:
            viewport.height = value;
            break;
        }
        i++;
    }

    settings->viewport = viewport;

    file.close();
}

#endif // SETTINGS