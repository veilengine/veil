#ifndef __VeilComponentSize__
#define __VeilComponentSize__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Size : public Component {
    const int width;
    const int height;

    Size(int _width, int _height) : width(_width), height(_height) {};
  };

}

#endif /* defined(__VeilComponentSize__) */
