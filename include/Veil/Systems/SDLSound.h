#ifndef __VeilSystemSDLSound__
#define __VeilSystemSDLSound__

#include <functional>
#include <SDL2/SDL_mixer.h>
#include <Veil/Systems/System.h>

namespace Veil {

  class SDLSound : public System {
    std::unordered_map<const char*, Mix_Music*> music;
    std::unordered_map<const char*, Mix_Chunk*> sounds;
    int channels;

    SDLSound();
    ~SDLSound();

    void onChannelEnd(int channel);

    Mix_Music* getMusic(const char*);
    Mix_Chunk* getSound(const char*);

    void init();
    void quit();

    public:
      static SDLSound* instance() {
        static SDLSound* singleton;
        if ( ! singleton) {
          singleton = new SDLSound;
        }
        return singleton;
      }

      void playMusic(const char* path);
      void playSound(const char* path);

      void removeChannel();
      void addChannel();
  };

}

#endif /* defined(__VeilSystemSDLSound__) */
