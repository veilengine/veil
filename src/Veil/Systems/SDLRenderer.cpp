#include <Veil/Systems/SDLRenderer.h>

namespace Veil {

// SDLTexture component
SDLTexture::SDLTexture(SDL_Surface* surface, SDL_Renderer* _renderer) {
  renderer = _renderer;
  texture = SDL_CreateTextureFromSurface(renderer, surface);
}

SDLRenderer::SDLRenderer(Entity* e) {
  // Initialize SDL systems
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    std::cout << "Failed to initialize sdl" << std::endl;
    exit(1);
    return;
  }

  // Initialize TTF systems
  if (TTF_Init() < 0) {
    std::cout << TTF_GetError() << std::endl;
    return;
  }

  // Extract data from the entity
  Fullscreen* fullscreen = e->as<Fullscreen>();
  WindowTitle* title = e->as<WindowTitle>();
  Position* position = e->as<Position>();
  Size* size = e->as<Size>();

  // Create a window
  window = SDL_CreateWindow(
    title->title,
    position->x,
    position->y,
    size->width,
    size->height,
    fullscreen->fullscreen ? SDL_WINDOW_FULLSCREEN : 0
  );
  if (window == 0) {
    std::cout << "Failed to create window" << std::endl;
    exit(1);
    return;
  }

  std::cout << "Created " << size->width << " x " << size->height << " window at " << position->x << " x " << position->y << std::endl;

  // Create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == 0) {
    std::cout << "Failed to create renderer" << std::endl;
    exit(1);
    return;
  }

  // Draw blank background
  SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
}

SDLRenderer::~SDLRenderer() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SDLRenderer::update(double dt) {
  // std::cout << "SDLRenderer::update() not yet implemented" << std::endl;
  // std::cout << "But it has been " << dt << " seconds since the last tick" << std::endl;
}

void SDLRenderer::render() {
  SDL_RenderClear(renderer);

  for (Entity* e : world->getEntities()) {
    if (e->has<Texture>()) {
      renderTexture(e);
    } else if (e->has<Typeface>() && e->has<Text>()) {
      renderText(e);
    }
  }

  SDL_RenderPresent(renderer);
}

void SDLRenderer::renderText(Entity* e) {
  SDL_Texture* texture = getText(e);

  if (texture != NULL) {
    Position* position = getPosition(e);
    Rotation* rotation = getRotation(e);
    Size* size = getSize(e, texture);

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = size->width;
    srcRect.h = destRect.h = size->height;
    destRect.x = position->x;
    destRect.y = position->y;

    SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, rotation->angle, 0, flip);
  }
}

void SDLRenderer::renderTexture(Entity* e) {
  SDL_Texture* texture = getTexture(e);

  if (texture != NULL) {
    Position* position = getPosition(e);
    Rotation* rotation = getRotation(e);
    Offset* offset = getOffset(e);
    Size* size = getSize(e, texture);

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = offset->x;
    srcRect.y = offset->y;
    srcRect.w = destRect.w = size->width;
    srcRect.h = destRect.h = size->height;
    destRect.x = position->x;
    destRect.y = position->y;

    SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, int(rotation->angle * 360), 0, flip);
  }
}

SDL_Texture* SDLRenderer::getTexture(Entity* e) {
  if ( ! e->has<SDLTexture>()) {
    Texture* texture = e->as<Texture>();
    if (texture == NULL) {
      return 0;
    }

    SDL_Surface* surface = IMG_Load(texture->path);
    e->add(new SDLTexture(surface, renderer));
    SDL_FreeSurface(surface);
  }

  return e->as<SDLTexture>()->texture;
}

SDL_Texture* SDLRenderer::getText(Entity* e) {
  Typeface* typeface = e->as<Typeface>();
  Text* text = e->as<Text>();
  if (typeface == NULL || text == NULL) {
    return 0;
  }

  if ( ! e->has<SDLTexture>()) {
    char* sdl_path = SDL_GetBasePath();
    std::string path(sdl_path);
    path += typeface->path;

    TTF_Font* font = TTF_OpenFont(path.c_str(), typeface->size);
    if (font == NULL) {
      return 0;
    }

    Color* c = typeface->getColor();
    SDL_Color color = { c->red, c->green, c->blue };
    SDL_Surface* surface = TTF_RenderText_Blended(font, text->text, color);

    e->add(new SDLTexture(surface, renderer));

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
  }

  return e->as<SDLTexture>()->texture;
}

// Default enforcers
Position* SDLRenderer::getPosition(Entity* e) {
  Position* p = e->as<Position>();
  if (p == NULL) {
    p = new Position(0, 0);
  }
  return p;
}

Offset* SDLRenderer::getOffset(Entity* e) {
  Offset* o = e->as<Offset>();
  if (o == NULL) {
    o = new Offset(0, 0);
  }
  return o;
}

Size* SDLRenderer::getSize(Entity* e, SDL_Texture* texture) {
  Size* s = e->as<Size>();
  if (s == NULL) {
    int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    s = new Size(width, height);
  }
  return s;
}

Rotation* SDLRenderer::getRotation(Entity* e) {
  Rotation* r = e->as<Rotation>();
  if (r == NULL) {
    r = new Rotation(0.0);
  }
  return r;
}

}
