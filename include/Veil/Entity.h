#ifndef __VeilEntity__
#define __VeilEntity__

#include <Veil/Components/Component.h>

namespace Veil {

  class Entity : public Component {
    int id;

    protected:
      static int nextId;

    public:
      Entity();
      virtual ~Entity() = default;
      int getId();
  };

}

#endif /* defined(__VeilEntity__) */
