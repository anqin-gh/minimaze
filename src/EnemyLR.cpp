#include <EnemyLR.h>
#include <RendManager.h>

namespace minimaze {

EnemyLR::EnemyLR() : m_dir{1} {}

void EnemyLR::update() {
	if (m_x != m_nx) m_dir = -m_dir;
	set_next_movement(m_dir, 0);
}

void EnemyLR::draw() const {

}

} // minimaze
