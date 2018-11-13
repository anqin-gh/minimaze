#include <EnemyChasing.h>
#include <Renderer.h>
#include <RendManager.h>

namespace minimaze {

EnemyChasing::EnemyChasing()
	: m_dir{1}
	, m_rend_manager{&RendManager::get_instance()}
{

}

void EnemyChasing::update() {
	if (m_x != m_nx) m_dir = -m_dir;
	set_next_movement(m_dir, 0);
}

void EnemyChasing::draw() const {
	m_rend_manager->renderer().draw_enemy_chasing(m_x, m_y);
}

} // minimaze
