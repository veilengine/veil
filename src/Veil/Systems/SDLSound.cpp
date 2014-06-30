#include <Veil/Systems/SDLSound.h>

namespace Veil {

SDLSound::SDLSound() {
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) > 0) {
    std::cout << Mix_GetError() << std::endl;
    return;
  }

  channels = 0;
  Mix_AllocateChannels(0);
  Mix_ChannelFinished([](int channel) {
    Veil::SDLSound::instance()->removeChannel();
  });
}

SDLSound::~SDLSound() {
  for (auto a : music) {
    Mix_FreeMusic(a.second);
  }
  for (auto b : sounds) {
    Mix_FreeChunk(b.second);
  }
  Mix_CloseAudio();
  Mix_Quit();
}

void SDLSound::onChannelEnd(int channel) {
  removeChannel();
}

void SDLSound::removeChannel() {
  channels--;
  Mix_AllocateChannels(channels);
}

void SDLSound::addChannel() {
  channels++;
  Mix_AllocateChannels(channels);
}

Mix_Music* SDLSound::getMusic(const char* path) {
  if (music[path] == NULL) {
    music[path] = Mix_LoadMUS(path);
  }
  return music[path];
}

void SDLSound::playMusic(const char* path) {
  Mix_PlayMusic(getMusic(path), -1 );
}

Mix_Chunk* SDLSound::getSound(const char* path) {
  if (sounds[path] == NULL) {
    sounds[path] = Mix_LoadWAV(path);
  }
  return sounds[path];
}

void SDLSound::playSound(const char* path) {
  addChannel();
  Mix_PlayChannel(-1, getSound(path), 0);
}

} // namespace Veil
