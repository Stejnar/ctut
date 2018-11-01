#include "model.h"
#include "view.h"
#include "controller.h"

int main()
{
    bool shouldStop = false;

    // instanziere Klassen
    AmpelState state;
    Ampel ampel(state);
    View view;
    AmpelController ctrl(ampel, view);

    ctrl.start();

    while (!shouldStop)
    {
        ctrl.update(&shouldStop);
    }

    return 0;
};