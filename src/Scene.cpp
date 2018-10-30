#include <vector>

#include <Scene.h>

Scene::Scene(const MazeFactory& f)
	: m_world_matrix{15, std::vector(std::vector(15, nullptr))}
{
	// TODO: create enemies, walls, player & goal with the input factory
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
