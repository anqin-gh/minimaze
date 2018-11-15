// standard includes
#include <new>
#include <thread>
#include <vector>

// custom includes
#include <MazeFactoryEasy.h>
#include <MazeFactoryHard.h>
#include <Game.h>
#include <KeyManager.h>
#include <RendManager.h>
#include <Renderer.h>
#include <Scene.h>

namespace minimaze {

Game::Game() 
	: m_key_manager{&KeyManager::get_instance()}
	, m_rend_manager{&RendManager::get_instance()}
	, m_factories{}
	, m_factory_index{0}
	, m_scene{nullptr}
{
	m_key_manager->clear();

	MazeFactoryEasy* fe = new MazeFactoryEasy();
	m_factories.push_back(fe);
	MazeFactoryHard* fh = new MazeFactoryHard();
	m_factories.push_back(fh);

	m_scene = new Scene(15, m_factories[m_factory_index]);
}

Game::~Game() {
	m_rend_manager->renderer().clear_screen();
	m_rend_manager->renderer().refresh();
	for (MazeFactory* f : m_factories) {
		delete f;
	}
	m_factories.clear();
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
		if (m_scene->reached_goal()) {
			if (m_factory_index < m_factories.size() - 1) {
				delete m_scene;
				m_factory_index++;
				m_scene = new Scene{15, m_factories[m_factory_index]};
			}
			else {
				m_reached_last_goal = true;
			}
		}
	} while (	m_key_manager->get_last_key() != 'q'
			 && m_scene->there_is_player()
			 && !m_reached_last_goal);

	if (m_reached_last_goal) {
		m_rend_manager->renderer().draw_win(2, m_scene->get_size()/2);
		m_rend_manager->renderer().refresh();
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	else {
		m_rend_manager->renderer().draw_game_over(2, m_scene->get_size()/2);
		m_rend_manager->renderer().refresh();
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

} // minimaze
