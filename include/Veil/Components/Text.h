#ifndef __VeilComponentText__
#define __VeilComponentText__

#include <Veil/Components/Component.h>

namespace Veil {

  struct Text : public Component {
    const char* text;

    Text(const char* _text) : text(_text) {};
  };

}

#endif /* defined(__VeilComponentText__) */
