#ifndef __VeilComponentFullscreen__
#define __VeilComponentFullscreen__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Fullscreen : public Component {
    const bool fullscreen;

    Fullscreen(bool fs) : fullscreen(fs) {};
  };

}

#endif /* defined(__VeilComponentFullscreen__) */
