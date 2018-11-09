#ifndef RENDMANAGER_H
#define RENDMANAGER_H

namespace minimaze {

enum class TRenderer {STDP, STDP2};
class Renderer;

class RendManager {
public:
	~RendManager() = default;
	RendManager(const RendManager&) = delete;
	RendManager& operator=(const RendManager&) = delete;

	static RendManager& get_instance();
	Renderer& renderer();

	void switch_renderer();
private:
	Renderer* m_rend;
	TRenderer m_selected;
	
	RendManager();
};

} // minimaze

#endif // RENDMANAGER_H
