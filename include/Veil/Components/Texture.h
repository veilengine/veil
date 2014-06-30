#ifndef __VeilComponentTexture__
#define __VeilComponentTexture__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Texture : public Component {
    const char* path;

    Texture(const char* _path) : path(_path) {};
  };

}

#endif /* defined(__VeilComponentTexture__) */
