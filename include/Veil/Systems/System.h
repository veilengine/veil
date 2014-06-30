#ifndef __VeilSystem__
#define __VeilSystem__

#include <Veil/World.h>

namespace Veil {

  class World;

  class System {
    protected:
      World* world;

    public:
      System();
      ~System();
      virtual void update(double dt) {};
      virtual void render() {};
      void setWorld(World*);
  };

}

#endif /* defined(__VeilSystem__) */
