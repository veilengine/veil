#include <Veil/Veil.h>
#include <Veil/Systems/Lambda.h>
#include <Veil/Systems/SDLRenderer.h>
#include <Veil/Systems/SDLInput.h>

using namespace Veil;

int main (int argc, char* argv[]) {
	// Create world and add player to it
	World* world = new World();

	// A window description is just an entity.
	Entity* window = new Entity();
	window->add(new WindowTitle("Test"));
	window->add(new Fullscreen(false));
	window->add(new Position(100, 100));
	window->add(new Size(640, 480));

	// Add systems to the world
	// TODO: Figure out a good way to abstract SDL_Init/SDL_Quit
	// so multiple systems can depend on it, but only call it once
	world->add(new SDLRenderer(window));
	world->add(new SDLInput());
	// world->add(new SDLSound());

	// Create person entity
	Position* pos = new Position(100, 200);
	Entity* player = new Entity();
	player->add(new Texture("assets/sprite.png"));
	player->add(new Rotation(0.5));
	player->add(pos);
	player->add(new Size(105, 153));
	world->add(player);

	// Add some text
	Entity* title = new Entity();
	title->add(new Typeface("assets/Amble-Bold.ttf", 60));
	title->add(new Text("hello, world!"));
	title->add(new Position(100, 100));
	world->add(title);

	// Lambda updater
	double accumulated = 0;
	world->add(new Lambda([&](World* world, double dt) {
		accumulated += dt;

		// Reset every second
		if (accumulated > 1) {
			accumulated -= 1;
		}

		// Update position
		Position* p1 = player->as<Position>();
		player->remove<Position>();
		int x = p1->x + int(accumulated * 40) % 2;
		if (x > 500) {
			x = 0;
		}
		Position* p2 = new Position(x, p1->y);
		player->add(p2);

		// Update offset
		int offset = int(accumulated * 4) % 4;
		if (player->has<Offset>()) {
			player->remove<Offset>();
		}
		Offset* o2 = new Offset(offset * 105, 0);
		player->add(o2);
	}));

	world->start();

	return 0;
}
