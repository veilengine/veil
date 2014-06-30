#ifndef __VeilComponentPosition__
#define __VeilComponentPosition__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Position : public Component {
    const int x;
    const int y;

    Position(int _x, int _y) : x(_x), y(_y) {};
  };

}

#endif /* defined(__VeilComponentPosition__) */
