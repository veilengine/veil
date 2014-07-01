#ifndef __VeilComponentOrigin__
#define __VeilComponentOrigin__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Origin : public Component {
    const double xOffset;
    const double yOffset;

    Origin(double _xOrigin, double _yOrigin)
      : xOrigin(_xOrigin), yOrigin(_yOrigin) {};
  };

}

#endif /* defined(__VeilComponentOrigin__) */
