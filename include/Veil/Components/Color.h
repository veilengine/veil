#ifndef __VeilComponentColor__
#define __VeilComponentColor__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Color : public Component {
    const uint8_t red;
    const uint8_t green;
    const uint8_t blue;

    Color(uint8_t _red, uint8_t _green, uint8_t _blue)
      : red(_red), green(_green), blue(_blue) {};
  };

}

#endif /* defined(__VeilComponentColor__) */
