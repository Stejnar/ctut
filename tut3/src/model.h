#include "../../mvc.h"

#if !defined(MODEL)
#define MODEL

#define GREEN 0
#define YELLOW 1
#define RED 2

// in Sekunden
#define TIME_GREEN 5
#define TIME_YELLOW 3
#define TIME_RED 1

class Ampel : public State
{
  public:
    int color;
    bool isOn;
};

class Model : public AbstractModel<Ampel>
{
  public:
    Model(){};
    Model(Ampel _state)
    {
        state = _state;
    };
    void off();
    void on();
    void setColor(int code);
    int next();
    float time();
};

void Model::on()
{
    state.color = RED;
    state.isOn = true;
};

void Model::off()
{
    state.color = RED;
    state.isOn = false;
};

void Model::setColor(int code)
{
    state.color = code;
};

int Model::next()
// bestimme naechste Farbe
{
    if (!state.isOn)
        return RED;
    switch (state.color)
    {
    case GREEN:
        return YELLOW;
    case YELLOW:
        return RED;
    case RED:
        return GREEN;
    default:
        return RED;
    }
};

float Model::time()
// bestimme Schaltzeit je nach farbe
{
    switch (state.color)
    {
    case GREEN:
        return TIME_GREEN;
    case YELLOW:
        return TIME_YELLOW;
    case RED:
    default:
        return TIME_RED;
    }
};

#endif // MODEL