// standard includes
#include <new>

// custom includes
#include <Game.h>
#include <KeyManager.h>
#include <Scene.h>

Game::Game() 
	: m_key_manager{&KeyManager.get_instance()}
	, m_scene{new Scene()}
{

}

Game::~Game() {
	delete m_scene;
}

void Game::update() {

}

void Game::draw() {

}

void Game::time_wait() {
	
}

void Game::run() {
	do {
		udpate();
		draw();
		time_wait();
	} while (m_key_manager->get_next_key() != 'q');
}


	KeyManager* m_key_manager;
	Scene*		m_scene;