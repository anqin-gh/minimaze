#ifndef MAZEFACTORYEASY_H
#define MAZEFACTORYEASY_H

#include <MazeFactory.h>

namespace minimaze {

class MazeFactoryEasy : public MazeFactory {
public:
	MazeFactoryEasy() = default;
	virtual ~MazeFactoryEasy() = default;

	Player*	create_player(int8_t x, int8_t y)	const override;
	Enemy*	create_enemy(int8_t x, int8_t y)	const override;
	Wall*	create_wall(int8_t x, int8_t y)		const override;
	Goal*	create_goal(int8_t x, int8_t y)		const override;
};

} // minimaze

#endif // MAZEFACTORYEASY_H
