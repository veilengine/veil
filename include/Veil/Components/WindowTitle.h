#ifndef __VeilComponentWindowTitle__
#define __VeilComponentWindowTitle__

#include <Veil/Components/Component.h>

namespace Veil {

  struct WindowTitle : public Component {
    const char* title;

    WindowTitle(const char* _title) : title(_title) {};
  };

}

#endif /* defined(__VeilComponentWindowTitle__) */
