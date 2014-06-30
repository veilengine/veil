#ifndef __VeilLambda__
#define __VeilLambda__

#include <functional>
#include <Veil/Systems/System.h>
#include <Veil/World.h>

namespace Veil {

  class Lambda : public System {
    const std::function<void (World*, double)> callback;

    public:
      Lambda(std::function<void (World*, double)> _callback)
        : callback(_callback) {};

      void update(double);
  };

}

#endif /* defined(__VeilLambda__) */
