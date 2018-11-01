/*
*   State
*     definiert den internen Zustand des Programms
* 
*   Model
*     kontrolliert den State
*     legt Regeln fuer Veraenderungen des State fest
*
*   by Armin Butkereit
*/

class State
//
{
public:
  State(){};
  ~State(){};
};

template <class State>
class AbstractModel
{
protected:
  State *state;

public:
  void setState(State *_state)
  {
    state = _state;
  };
  State *getState()
  {
    return state;
  };
  AbstractModel(State *_state)
  {
    state = _state;
  };
  AbstractModel(){};
  ~AbstractModel(){};
};