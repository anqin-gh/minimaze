#include <stdexcept>
#include <string>
#include <vector>

#include <Enemy.h>
#include <MazeFactory.h>
#include <Scene.h>
#include <Player.h>
#include <Wall.h>

namespace minimaze {

Scene::Scene(int8_t size, const MazeFactory& f)
	: m_size{size}
	, m_world_matrix{m_size, std::vector(std::vector(m_size, nullptr))}
{
	// TODO: create enemies, walls, player & goal with the input factory
	// Enemy* e1 = f.create_enemy(2, 4);
	// add_object(e1);
}

Scene::~Scene() {
	for (GameObject* o : m_obj_vector) {
		//delete o;
	}
}

void Scene::update() {
	for (GameObject* o : m_obj_vector) {
		o->update();
	}
}

void Scene::draw() const {
	for (GameObject* o : m_obj_vector) {
		o->draw();
	}
}

bool Scene::is_player() const { return false; }

bool Scene::is_mortal() const { return false; }

bool Scene::there_is_player() const { return m_is_there_player; }

void Scene::add_object(GameObject* o) {
	// check for nullptr
	if (!o) {
		throw std::invalid_argument("Invalid Object");
	}
	// check boundaries
	int8_t x = o->get_x();
	int8_t y = o->get_y();
	if (x > m_size - 1 || y > m_size - 1) {
		throw std::out_of_range("Out of world matrix ("
			+ std::to_string(x) + x + ", "
			+ std::to_string(y) + y + ")");
	}
	// check whether position is available in world matrix
	if (m_world_matrix[x][y]) {
		throw std::logic_error("Existing object at position ("
			+ std::to_string(x) + x + ", "
			+ std::to_string(y) + y + ") of world matrix");
	}

	m_world_matrix[x][y] = o;
	m_obj_vector.push_back(o);
}

void Scene::move_object(GameObject* o) {

}

void Scene::remove_object(GameObject* o) {

}

} // minimaze
