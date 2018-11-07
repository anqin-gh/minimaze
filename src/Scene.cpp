#include <algorithm>
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
	std::size_t size = m_obj_vector.size();
	for (std::size_t i = 0; i < size; ++i) {
		GameObject* o = m_obj_vector[i];
		o->update();
		move_object(o);
		if (m_obj_vector.size() != size) {
			size = m_obj_vector.size();
			--i
		}
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
	if (o->wants_to_move()) {
		int8_t x  = o->get_x();
		int8_t y  = o->get_y();
		int8_t nx = o->get_next_x();
		int8_t ny = o->get_next_y();

		GameObject* o_dest = m_obj_vector[nx][ny];
		if (o_dest == nullptr) {
			m_obj_vector[nx][ny] = o;
			m_obj_vector[x][y] = nullptr;
		} else if (o_dest->is_mortal && o->is_player){
			remove_object(o)
		} else if (o_dest->is_player && o->is_mortal){
			remove_object(o_dest)
		} else {
			nx = x;
			ny = y;
		}
		o->set_location(nx, ny);
	}
}

void Scene::remove_object(GameObject* o) {
	auto it = std::find(m_obj_vector.begin(), m_obj_vector.end(), o);
	if (it == m_obj_vector.end()) {
		throw std::logic_error("Not found while removing object")
	}
	m_obj_vector.erase(it);

	int8_t x = o->get_x();
	int8_t y = o->get_y();
	if (m_world_matrix[x][y] != o) {
		throw std::logic_error("Not found in wold matrix")
	}
	m_world_matrix[x][y] = nullptr;
	if (o->is_player) {
		m_is_there_player = false;
	}
	delete o;
}

} // minimaze
