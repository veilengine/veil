#include <Veil/World.h>

namespace Veil {

World::World() {}
World::~World() {}

void World::update(double dt) {
  for (System* s : systems) {
    s->update(dt);
  }
}

void World::render() {
  for (System* s : systems) {
    s->render();
  }
}

void World::add(Entity* e) {
  // e->setWorld(this);
  entities.push_back(e);
}

void World::add(System* s) {
  s->setWorld(this);
  systems.push_back(s);
}

std::vector<Entity*> World::getEntities() const {
  return entities;
}

std::vector<System*> World::getSystems() const {
  return systems;
}

// TODO: Threading?
void World::start() {
  running = true;

  // Keep track of the time delta
  uint64_t last = uv_hrtime();
  double delta;

  while (running) {
    render();

    uint64_t now = uv_hrtime();
    delta = (double) ((now - last) / 1000000000.0);
    last = now;
    update(delta);
  }
}

void World::stop() {
  running = false;
}

bool World::isRunning() {
  return running;
}

} // namespace Veil
