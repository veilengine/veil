#ifndef __VeilComponentOrigin__
#define __VeilComponentOrigin__

#include <Veil/Components/Component.h>

namespace Veil {

  /**
   * The Origin component uses doubles to identify relative offset.
   *
   * (0.0, 0.0) to align to center
   * (-1.0, -1.0) to align to top left
   * (1.0, 1.0) to align to bottom right
   *
   * Values can exceed the bounds of the object for orbit-style pivots.
   */
  struct Origin : public Component {
    const double xOrigin;
    const double yOrigin;

    Origin(double _xOrigin, double _yOrigin)
      : xOrigin(_xOrigin), yOrigin(_yOrigin) {};
  };

}

#endif /* defined(__VeilComponentOrigin__) */
