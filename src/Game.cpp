// standard includes
#include <new>
#include <thread>

// custom includes
#include <MazeFactoryEasy.h>
#include <Game.h>
#include <KeyManager.h>
#include <RendManager.h>
#include <Renderer.h>
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
	m_rend_manager->renderer().clear_screen();
	m_scene->draw();
	m_rend_manager->renderer().refresh();
}

void Game::time_wait() {
	using clock = std::chrono::system_clock;
	using namespace std::chrono_literals;

	constexpr auto fps = 20.0f;
	constexpr auto spf = 1.0s / fps;
	auto t = clock::now();

	auto passed = clock::now() - t;
	if (passed < spf)
		std::this_thread::sleep_for(spf - passed);
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
