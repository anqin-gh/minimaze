#ifndef GAME_H
#define GAME_H

class KeyManager;
class Scene;

class Game {
public:
	Game();
	~Game();

	void update();
	void draw();
	void run();
	void time_Wait();
private:
	KeyManager* m_key_manager;
	Scene*		m_scene;
};

#endif // GAME_H