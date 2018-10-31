/*
*   MVC Pattern
*   Das Model-View-Controller Muster unterteilt das Programm in 3 flexible, wiederverwendbare Komponenten.
*   by Armin Butkereit
*/

#if !defined(MVC)
#define MVC

class State
// definiert den internen Zustand des Programms;
{
public:
  State(){};
  ~State(){};
};

template <class State>
class Model
// kontrolliert den State;
// legt Regeln fuer Veraenderungen des State fest;
{
protected:
  State state;
  void setState(State newState)
  // nur dem Model erlauben den State zu veraendern
  {
    state = newState;
  };

public:
  State getState()
  {
    return state;
  };
  Model(State newState)
  {
    state = newState;
  };
  Model(){};
  ~Model(){};
};

template <class State>
class View
// stellt den State dar
{
public:
  virtual void render(State state) = 0;
};

template <class Model, class View>
class Controller
// steuert das Programm;
// greift auf Model zurueck um den State zu kontrollieren;
// laesst View den veraenderten State rendern;
// kuemmert sich um Nebeneffekte (Zeit, Benutzerinteraktionen, Dateien etc)
{
protected:
  Model model;
  View view;

public:
  Controller(Model m, View v)
  {
    model = m;
    view = v;
  };
  Controller(){};
  ~Controller(){};
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void update(bool shouldStop) = 0;
};

#endif // MVC