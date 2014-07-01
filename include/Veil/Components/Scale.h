#ifndef __VeilComponentScale__
#define __VeilComponentScale__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Scale : public Component {
    const double scale;

    Scale(double _scale) : scale(_scale) {};
  };

}

#endif /* defined(__VeilComponentScale__) */
