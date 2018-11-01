#include "../../mvc/mvc.h"
#include "../../list/list.h"
#include "tupel.h"
#include "settings.h"

#if !defined(MODEL)
#define MODEL

const Tupel NORTH(0, -1);
const Tupel EAST(1, 0);
const Tupel SOUTH(0, 1);
const Tupel WEST(-1, 0);

struct GameInfo
{
    bool shouldUpdate = true;
    bool gameOver = false;
    GameInfo(){};
};

class Snake : public State
{
  public:
    int width = 20;
    int height = 20;
    int velocity = 1;
    int score = 0;
    Tupel direction = NORTH;
    Tupel fruit;
    List<Tupel> blocks;
    GameInfo info;

    Snake(){};
    Snake(Settings settings)
    {
        velocity = settings.velocity;
        width = settings.viewport.width;
        height = settings.viewport.height;
    };
};

class Model : public AbstractModel<Snake>
{
  public:
    Model(Snake *_state)
    {
        state = _state;
    };
    Model(){};
    ~Model(){};
    void setDirection(Tupel direction);
    bool canMove(Tupel src, Tupel dest);
    void move(float frameTime);
    void spawnFruit();
    void spawn();
};

void Model::setDirection(Tupel direction)
{
    state->direction = direction;
};

void Model::spawn()
{
    int x, y;
    x = round(state->height / 2);
    y = round(state->width / 2);
    state->blocks.append(Tupel(x, y));
};

bool Model::canMove(Tupel src, Tupel dest)
// Nur zu dest bewegen, wenn der Abstand eine volle Laenge betraegt
{
    return (abs(round(dest.x) - round(src.x)) >= 1 ||
            abs(round(dest.y) - round(src.y)) >= 1);
};

void Model::spawnFruit()
// laesst zufaellig auf einem nicht blockierten Feld eine Frucht spawnen
{
    int x, y;
    Tupel fruit;

    x = rand() % state->width;
    y = rand() % state->height;
    fruit = Tupel(x, y);

    if (!state->blocks.includes(fruit))
    {
        state->fruit = fruit;
    }
    else
    {
        spawnFruit();
    }
};

void Model::move(float frameTime)
{
    if (state->blocks.head != NULL)
    {
        Tupel head = state->blocks.head->value;
        Tupel dest = head + state->direction * state->velocity * frameTime;

        // Begrenzung einhalten
        if (dest.y < 0)
        {
            dest.y += state->height;
        }
        if (dest.x < 0)
        {
            dest.x += state->width;
        }
        if (dest.y > state->height)
        {
            dest.y -= state->height;
        }
        if (dest.x > state->width)
        {
            dest.x -= state->width;
        }

        if (canMove(head, dest))
        {
            state->info.shouldUpdate = true;

            if (state->blocks.includes(dest))
            // Endbedingung
            {
                state->info.gameOver = true;
            }

            state->blocks.prepend(dest);

            if (state->fruit == dest)
            // esse Frucht
            {
                state->score += 10;
                spawnFruit();
            }
            else
            {
                state->blocks.pop();
            }
        }
        else
        {
            state->blocks.head->value = dest;
        }
    }
};

#endif // MODEL