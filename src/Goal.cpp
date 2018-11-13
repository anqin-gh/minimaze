#include <Goal.h>
#include <Renderer.h>
#include <RendManager.h>

namespace minimaze {

Goal::Goal() : m_rend_manager{&RendManager::get_instance()} {}

void Goal::update() {}

void Goal::draw() const {m_rend_manager->renderer().draw_goal(m_x, m_y);}

bool Goal::is_player() const {return false;}

bool Goal::is_mortal() const {return false;}

bool Goal::is_goal() const {return true;}

} // minimaze
