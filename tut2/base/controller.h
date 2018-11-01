/*
*   Controller
*     koordiniert Programmablauf
*     greift auf Model zurueck um den State zu verwalten
*     laesst View den veraenderten State rendern
*
*   by Armin Butkereit
*/

#include "view.h"
#include "model.h"

template <class AbstractModel, class AbstractView>
class AbstractController
{
protected:
  AbstractModel *model;
  AbstractView *view;

public:
  AbstractController(AbstractModel *m, AbstractView *v)
  {
    model = m;
    view = v;
  };
  AbstractController(){};
  ~AbstractController(){};
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void update() = 0;
};