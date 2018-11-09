#include <Renderer.h>
#include <RendManager.h>
#include <RendSTDP.h>
#include <RendSTDP2.h>
#include <WallMortal.h>

namespace minimaze {

void WallMortal::update() {}

void WallMortal::draw() const {m_rend_manager->renderer().draw_wall_mortal(m_x, m_y);}

bool WallMortal::is_mortal() const {return true;}

} // minimaze
