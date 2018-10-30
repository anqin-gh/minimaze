#include <GameObject.h>

GameObject::GameObject() { }

void GameObject::set_location(int8_t x, int8_t y) {
	m_x = x;
	m_y = y;
	m_wants_to_move = true;
}

void GameObject::set_next_movement(int8_t dx, int8_t dy) {
	m_nx = m_x + dx;
	m_ny = m_y + dy;	
	m_wants_to_move = false;
}
