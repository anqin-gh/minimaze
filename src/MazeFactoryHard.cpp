#include <new>

#include <EnemyChasing.h>
#include <EnemyWandering.h>
#include <Goal.h>
#include <MazeFactoryHard.h>
#include <Player.h>
#include <WallMortal.h>

namespace minimaze {

Player* MazeFactoryHard::create_player(int8_t x, int8_t y) const {
	Player* p = new Player();
	p->set_location(x, y);
	return p;
}

Enemy* MazeFactoryHard::create_enemy(int8_t x, int8_t y) const {
	Enemy* e = new EnemyWandering();
	e->set_location(x, y);
	return e;
}

Wall* MazeFactoryHard::create_wall(int8_t x, int8_t y) const {
	Wall* w = new WallMortal();
	w->set_location(x, y);
	return w;
}

Goal* MazeFactoryHard::create_goal(int8_t x, int8_t y) const {
	Goal* g = new Goal();
	g->set_location(x, y);
	return g;
}

} // minimaze
