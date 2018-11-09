#ifndef GAME_H
#define GAME_H

namespace minimaze {

class KeyManager;
class RendManager;
class Scene;

class Game {
public:
	Game();
	~Game();

	void update();
	void draw();
	void run();
	void time_wait();
private:
	KeyManager* m_key_manager;
	RendManager* m_rend_manager;
	Scene*		m_scene;
};

} // minimaze

#endif // GAME_H
