#ifndef __VeilWorld__
#define __VeilWorld__

#include <ctime>
#include <vector>
#include <uv.h>
#include <Veil/Entity.h>
#include <Veil/Systems/System.h>

// TODO: Make Scene inherit Entity and use draw/update systems
namespace Veil {

  class System;

  class World {
    std::vector<Entity*> entities;
    std::vector<System*> systems;
    bool running;

    public:
      World();
      ~World();

      void update(double dt);
      void render();

      void add(Entity* e);
      void add(System* e);

      std::vector<Entity*> getEntities() const;
      std::vector<System*> getSystems() const;

      void start();
      void stop();
      bool isRunning();
  };

}

#endif /* defined(__VeilWorld__) */
