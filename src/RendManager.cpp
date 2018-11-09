#include <new>

#include <RendManager.h>
#include <RendSTDP.h>
#include <RendSTDP2.h>

namespace minimaze {

RendManager::RendManager() 
	: m_rend{new RendSTDP()} 
	, m_selected{TRenderer::STDP}
{

}

RendManager& RendManager::get_instance() {
	static RendManager instance;
	return instance;
}

Renderer& RendManager::renderer() {
	return *m_rend;
}

void RendManager::switch_renderer() {
	delete m_rend;
	switch (m_selected) {
		case TRenderer::STDP : {
			m_rend = new RendSTDP2();
			m_selected = TRenderer::STDP2;
			break;
		}
		case TRenderer::STDP2 : {
			m_rend = new RendSTDP();
			m_selected = TRenderer::RendSTDP;
			break;
		}
	}
}

} // minimaze
