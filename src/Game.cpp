// standard includes
#include <new>

// custom includes
#include <MazeFactoryEasy.h>
#include <Game.h>
#include <KeyManager.h>
#include <RendManager.h>
#include <Scene.h>

namespace minimaze {

Game::Game() 
	: m_key_manager{&KeyManager::get_instance()}
	, m_rend_manager{&RendManager::get_instance()}
	, m_scene{nullptr}
{
	m_key_manager->clear();

	MazeFactoryEasy f;
	m_scene = new Scene(15, f);
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
		update();
		draw();
		time_wait();
		if (m_key_manager->get_last_key() == 'r') {
			m_rend_manager->switch_renderer();
		}
	} while (	m_key_manager->get_last_key() != 'q'
			 && m_scene->there_is_player());
}

} // minimaze
