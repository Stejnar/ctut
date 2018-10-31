#include <time.h>

#include "model.h"
#include "mvc.h"

#if !defined(CONTROLLER)
#define CONTROLLER

class AmpelController : public Controller<Ampel, AmpelView>
{
  public:
    clock_t last_time = clock();
    clock_t current_time = clock() - TIME_GREEN * CLOCKS_PER_SEC;

    AmpelController(Ampel ampel, AmpelView ampelView)
    {
        model = ampel;
        view = ampelView;
    };
    void start();
    void stop(){};
    void update(bool shouldStop);
};

void AmpelController::start()
{
    model.on();
};

void AmpelController::update(bool shouldStop)
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