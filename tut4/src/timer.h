#include <time.h>

#if !defined(TIMER)
#define TIMER

class Timer
{

  private:
    clock_t last_time;
    float delta;

  public:
    Timer()
    {
        last_time = clock();
    };

    clock_t getLastTime()
    {
        return last_time;
    };

    void update()
    {
        clock_t now = clock();
        delta = (float)(now - last_time) / CLOCKS_PER_SEC;
        last_time = now;
    };

    float getElapsedTime()
    {
        return delta;
    };
};

#endif // TIMER