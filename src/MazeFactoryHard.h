#ifndef MAZEFACTORYHARD_H
#define MAZEFACTORYHARD_H

#include <MazeFactory.h>

namespace minimaze {

class Player;
class Enemy;
class Wall;
class Goal;

class MazeFactoryHard : public MazeFactory {
public:
	MazeFactoryHard() = default;
	~MazeFactoryHard() override = default;

	Player*	create_player	(int8_t x, int8_t y) const override;
	Enemy*	create_enemy	(int8_t x, int8_t y) const override;
	Wall*	create_wall		(int8_t x, int8_t y) const override;
	Goal*	create_goal		(int8_t x, int8_t y) const override;
};

} // minimaze

#endif // MAZEFACTORYHARD_H
