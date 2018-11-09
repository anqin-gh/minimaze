#include <Renderer.h>
#include <RendManager.h>
#include <RendSTDP.h>
#include <RendSTDP2.h>
#include <WallNormal.h>

namespace minimaze {

WallNormal::WallNormal() {}

void WallNormal::update() {}

void WallNormal::draw() const {m_rend_manager->renderer().draw_wall_normal(m_x, m_y);}

bool WallNormal::is_mortal() const {return false;}

} // minimaze
