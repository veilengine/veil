#ifndef __VeilComponentRotation__
#define __VeilComponentRotation__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Rotation : public Component {
    const double angle;

    Rotation(double _angle) : angle(_angle) {};
  };

}

#endif /* defined(__VeilComponentRotation__) */
