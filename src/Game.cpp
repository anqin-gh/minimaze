// standard includes
#include <new>

// custom includes
#include <Game.h>
#include <KeyManager.h>
#include <Scene.h>

namespace minimaze {

Game::Game() 
	: m_key_manager{&KeyManager.get_instance()}
	, m_scene{new Scene()}
{

}

Game::~Game() {
	delete m_scene;
}

void Game::update() {
	m_key_manager->update();
	m_scene->update();
}

void Game::draw() {
	m_scene->draw();
}

void Game::time_wait() {
	
}

void Game::run() {
	do {
		udpate();
		draw();
		time_wait();
	} while (	m_key_manager->get_next_key() != 'q'
			 && m_scene->there_is_player());
}

} // minimaze
