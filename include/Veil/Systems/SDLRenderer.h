#ifndef __VeilSystemSDLRenderer__
#define __VeilSystemSDLRenderer__

#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <Veil/Systems/System.h>
#include <Veil/Entity.h>
#include <Veil/Components/Component.h>
#include <Veil/Components/Typeface.h>
#include <Veil/Components/Color.h>
#include <Veil/Components/Text.h>
#include <Veil/Components/Texture.h>
#include <Veil/Components/Fullscreen.h>
#include <Veil/Components/WindowTitle.h>
#include <Veil/Components/Rotation.h>
#include <Veil/Components/Position.h>
#include <Veil/Components/Offset.h>
#include <Veil/Components/Size.h>

namespace Veil {

  struct SDLTexture : public Component {
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDLTexture(SDL_Surface*, SDL_Renderer*);
  };

  struct SDLTypeface : public Component {
    TTF_Font* typeface;
    SDLTypeface(TTF_Font* _typeface) : typeface(_typeface) {};
  };

  class SDLRenderer : public System {
    SDL_Renderer* renderer;
    SDL_Window* window;

    static Position* defaultPosition;
    static Rotation* defaultRotation;
    static Offset* defaultOffset;

    void renderTexture(Entity* e);
    void renderText(Entity* e);

    SDL_Texture* getTexture(Entity* e);
    SDL_Texture* getText(Entity* e);

    Position* getPosition(Entity* e);
    Rotation* getRotation(Entity* e);
    Offset* getOffset(Entity* e);
    Size* getSize(Entity* e, SDL_Texture* texture);

    public:
      SDLRenderer(Entity* e);
      ~SDLRenderer();
      void render();
  };

}

#endif /* defined(__VeilSystemSDLRenderer__) */
