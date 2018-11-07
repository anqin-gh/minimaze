#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H

#include <cstdint>

namespace minimaze {

class Player;
class Enemy;
class Wall;
class Goal;

class MazeFactory {
public:
	MazeFactory() = default;
	virtual ~MazeFactory() = default;

	virtual Player*	create_player(int8_t x, int8_t y)	const = 0;
	virtual Enemy*	create_enemy(int8_t x, int8_t y) 	const = 0;
	virtual Wall*	create_wall(int8_t x, int8_t y) 	const = 0;
	virtual Goal*	create_goal(int8_t x, int8_t y) 	const = 0;
};

} // minimaze

#endif // MAZEFACTORY_H
