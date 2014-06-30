#ifndef __VeilSystemSDLInput__
#define __VeilSystemSDLInput__

#include <SDL2/SDL.h>
#include <Veil/Systems/System.h>
#include <Veil/Entity.h>

namespace Veil {

  class SDLInput : public System {
    SDL_Event event;

    public:
      void update(double dt);
  };

}

#endif /* defined(__VeilSystemSDLInput__) */
