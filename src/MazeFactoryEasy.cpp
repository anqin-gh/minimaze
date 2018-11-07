#include <MazeFactoryEasy.h>

namespace minimaze {

Player* MazeFactoryEasy::create_player(int8_t x, int8_t y) const {
	Player* p = new Player();
	p->set_location(x, y);
	return p;
}

Enemy* MazeFactoryEasy::create_enemy(int8_t x, int8_t y) const {
	Enemy* e = new Enemy();
	e->set_location(x, y);
	return e;
}

Wall* MazeFactoryEasy::create_wall(int8_t x, int8_t y) const {
	Wall* w = new Wall();
	w->set_location(x, y);
	return w;
}

Goal* MazeFactoryEasy::create_goal(int8_t x, int8_t y) const {
	Goal* g = new Goal();
	g->set_location(x, y);
	return g;
}


} // minimaze
