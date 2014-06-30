#include <Veil/Systems/SDLInput.h>

namespace Veil {

void SDLInput::update (double dt) {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        world->stop();
        break;
    }
  }
}

} // namespace Veil
