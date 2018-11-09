#include <EnemyLR.h>
#include <Renderer.h>
#include <RendManager.h>
#include <RendSTDP.h>
#include <RendSTDP2.h>

namespace minimaze {

EnemyLR::EnemyLR() : m_dir{1} {}

void EnemyLR::update() {
	if (m_x != m_nx) m_dir = -m_dir;
	set_next_movement(m_dir, 0);
}

void EnemyLR::draw() const {
	m_rend_manager->renderer().draw_enemy_lr(m_x, m_y);
}

} // minimaze
