#if !defined(CONTROLLER)
#define CONTROLLER

#include <conio.h>

#include "model.h"
#include "view.h"
#include "timer.h"
#include "score.h"

#define TARGET_FPS 75

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Controller : public AbstractController<Model, View>
{
  private:
    Timer timer;
    Settings *settings;

  public:
    Controller(Model *_model, View *_view)
    {
        model = _model;
        view = _view;
    };
    Controller(){};
    ~Controller(){};
    void start();
    void input();
    void update();
    void stop();
};

void Controller::start()
{
    settings = new Settings();
    readSettings(settings);

    model->getState()->width = settings->viewport.width;
    model->getState()->height = settings->viewport.height;
    model->getState()->velocity = settings->velocity;

    view->setViewport(settings->viewport);
    view->initMatrix(settings->viewport);

    model->spawn();
    model->spawnFruit();
};

void Controller::input()
{
    int key = 0;
    if (kbhit())
    // Nur wenn auch eine Taste gedrückt ist
    {
        switch ((key = getch()))
        {
        case KEY_UP:
            model->setDirection(NORTH);
            break;
        case KEY_DOWN:
            model->setDirection(SOUTH);
            break;
        case KEY_LEFT:
            model->setDirection(WEST);
            break;
        case KEY_RIGHT:
            model->setDirection(EAST);
            break;
        }
    }
};

void Controller::update()
{
    timer.update();

    input();

    model->move(timer.getElapsedTime());

    view->render(model->getState());
};

void Controller::stop()
{
    std::string name;

    system("cls");
    std::cout << "Please enter your name:" << endl;

    std::cin >> name;

    writeScore(name, model->getState()->score);
};

#endif // CONTROLLER
