#ifndef GAME_H
#define GAME_H

#include <vector>

namespace minimaze {

class KeyManager;
class MazeFactory;
class RendManager;
class Scene;

class Game {
public:
	Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	~Game();

	void run();
private:
	KeyManager* 				m_key_manager;
	RendManager* 				m_rend_manager;
	std::vector<MazeFactory*> 	m_factories;
	std::size_t				 	m_factory_index;
	Scene*						m_scene;
	bool						m_reached_last_goal;
	
	void update();
	void draw();
	void time_wait();
};

} // minimaze

#endif // GAME_H
