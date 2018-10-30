#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <GameObject.h>

namespace minimaze {

class MazeFactory;

class Scene : public GameObject {
public:
	Scene(const MazeFactory& f);
	~Scene();

	void initialize();
	void update() 			override;	
	void draw()		 const 	override;
	bool is_player() const 	override;
	bool is_mortal() const 	override;

	bool there_is_player() const;

private:
	bool 					  				m_is_there_player;
	std::vector<GameObject*>  				m_obj_vector; 		// vector with all the game object in the scene
	std::vector<std::vector<GameObject*>>   m_world_matrix; 	// matrix representing the world, used for collisions
};

} // minimaze

#endif // SCENE_H