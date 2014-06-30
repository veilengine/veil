#include <Veil/Systems/System.h>

namespace Veil {

System::System() {}
System::~System() {}

void System::setWorld(World* w) {
  world = w;
}

} // namespace Veil
