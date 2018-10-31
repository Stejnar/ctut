#include "mvc.h"

#if !defined(MODEL)
#define MODEL

#define GREEN 0
#define YELLOW 1
#define RED 2

// in Sekunden
#define TIME_GREEN 5
#define TIME_YELLOW 3
#define TIME_RED 1

class AmpelState : public State
{
  public:
    int color;
    bool isOn;
};

class Ampel : public Model<AmpelState>
{
  public:
    Ampel(){};
    Ampel(AmpelState ampelState)
    {
        state = ampelState;
    };
    void off();
    void on();
    void setColor(int code);
    int next();
    float time();
};

void Ampel::on()
{
    state.color = RED;
    state.isOn = true;
};

void Ampel::off()
{
    state.color = RED;
    state.isOn = false;
};

void Ampel::setColor(int code)
{
    state.color = code;
};

int Ampel::next()
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

float Ampel::time()
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