#include <time.h>

#include "../../mvc.h"
#include "model.h"
#include "view.h"

#if !defined(CONTROLLER)
#define CONTROLLER

class Controller : public AbstractController<Model, View>
{
  public:
    clock_t last_time = clock();
    clock_t current_time = clock() - TIME_GREEN * CLOCKS_PER_SEC;

    Controller(Model _model, View _view)
    {
        model = _model;
        view = _view;
    };
    void start();
    void stop(){};
    void update(bool *shouldStop);
};

void Controller::start()
{
    model.on();
};

void Controller::update(bool *shouldStop)
{
    // bestimme vergangene Zeit seit letztem Aufruf
    current_time = clock();
    float dt = float(current_time - last_time) / CLOCKS_PER_SEC;

    if (dt >= model.time())
    {
        auto state = model.getState();

        // setze Endbedingung
        if (!state.isOn)
        {
            shouldStop = true;
        }

        // wechsle Farbe
        int color = model.next();
        model.setColor(color);
        view.render(state);

        last_time = current_time;
    }
}

#endif // CONTROLLER