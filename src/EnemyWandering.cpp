#include <algorithm>
#include <random>

#include <EnemyWandering.h>
#include <Renderer.h>
#include <RendManager.h>

namespace minimaze {

EnemyWandering::EnemyWandering()
	: m_rend_manager{&RendManager::get_instance()}
{
	init();
}

void EnemyWandering::init() {
	std::default_random_engine generator;
	std::uniform_int_distribution<int8_t> distribution(1, 10);

	m_dirs[0] = { 0,  1, distribution(generator)};
	m_dirs[1] = { 0, -1, distribution(generator)};
	m_dirs[2] = { 1,  0, distribution(generator)};
	m_dirs[3] = {-1,  0, distribution(generator)};

	std::random_shuffle(m_dirs.begin(), m_dirs.end());
	m_di = 0;
	m_step = 0;
}

int8_t EnemyWandering::steps_left_in_current_direction() const {
	return m_dirs[m_di].steps - m_step;
}

void EnemyWandering::move_one_step_in_current_direction() {
	const MoveDir& move = m_dirs[m_di];
	set_next_movement(move.dx, move.dy);
	++m_step;
}

void EnemyWandering::change_direction() {
	++m_di;
	if (m_di < 3) init();
}

void EnemyWandering::update() {
	if (!steps_left_in_current_direction()) {
		change_direction();
	}
	move_one_step_in_current_direction();
}

void EnemyWandering::draw() const {
	m_rend_manager->renderer().draw_enemy_wandering(m_x, m_y);
}

} // minimaze
