#ifndef __VeilComponentColor__
#define __VeilComponentColor__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Color : public Component {
    const Uint8 red;
    const Uint8 green;
    const Uint8 blue;

    Color(Uint8 _red, Uint8 _green, Uint8 _blue)
      : red(_red), green(_green), blue(_blue) {};
  };

}

#endif /* defined(__VeilComponentColor__) */
