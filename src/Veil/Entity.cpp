#include <Veil/Entity.h>

namespace Veil {

int Entity::nextId = 0;

Entity::Entity() {
  id = ++nextId;
}

int Entity::getId() {
  return id;
}

}
