#include <EnemyWandering.h>
#include <Renderer.h>
#include <RendManager.h>

namespace minimaze {

EnemyWandering::EnemyWandering()
	: m_dir{1}
	, m_rend_manager{&RendManager::get_instance()}
{

}

void EnemyWandering::update() {
	if (m_x != m_nx) m_dir = -m_dir;
	set_next_movement(m_dir, 0);
}

void EnemyWandering::draw() const {
	m_rend_manager->renderer().draw_enemy_wandering(m_x, m_y);
}

} // minimaze
