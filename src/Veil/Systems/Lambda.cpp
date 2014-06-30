#include <Veil/Systems/Lambda.h>

namespace Veil {

void Lambda::update(double dt) {
  callback(world, dt);
}

} // namespace Veil
