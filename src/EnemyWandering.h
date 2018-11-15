#ifndef ENEMYWANDERING_H
#define ENEMYWANDERING_H

#include <vector>

#include <Enemy.h>

namespace minimaze {

class RendManager;

class EnemyWandering : public Enemy {
public:
	EnemyWandering();
	~EnemyWandering() override = default;

	// abstract methods defining the interface
	void update() override;	
	void draw() const override;

private:
	struct MoveDir { int8_t dx, dy, steps; };

	std::vector<MoveDir>	m_dirs{4}; 	// vector of directions
	int8_t					m_di{0};	// direction index
	int8_t					m_step{0};	// current step
	RendManager* 			m_rend_manager{nullptr};

	void init();
	int8_t steps_left_in_current_direction() const;
	void move_one_step_in_current_direction();
	void change_direction();
};

} // minimaze

#endif // ENEMYWANDERING_H
