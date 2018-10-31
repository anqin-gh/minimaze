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

int8_t GameObject::get_x() const {return m_x;}

int8_t GameObject::get_y() const {return m_y;}

int8_t GameObject::get_next_x() const {return m_nx;}

int8_t GameObject::get_next_y() const {return m_ny;}

bool GameObject::wants_to_move() const {return m_wants_to_move;}
