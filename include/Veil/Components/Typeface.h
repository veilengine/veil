#ifndef __VeilComponentTypeface__
#define __VeilComponentTypeface__

#include <Veil/Components/Component.h>
#include <Veil/Components/Color.h>

namespace Veil {

  struct Typeface : public Component {
    const char* path;
    const int size;

    Typeface(const char* _path, int _size)
      : path(_path), size(_size) {};

    Color* getColor() {
      if ( ! has<Color>()) {
        return new Color(0, 0, 0);
      }

      return as<Color>();
    };
  };

}

#endif /* defined(__VeilComponentTypeface__) */
