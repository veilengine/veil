#ifndef __VeilComponentOffset__
#define __VeilComponentOffset__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Offset : public Component {
    const int x;
    const int y;

    Offset(int _x, int _y) : x(_x), y(_y) {};
  };

}

#endif /* defined(__VeilComponentOffset__) */
