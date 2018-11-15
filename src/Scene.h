#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <GameObject.h>

namespace minimaze {

class MazeFactory;

class Scene : public GameObject {
public:
	Scene(int8_t size, const MazeFactory* f);
	~Scene() override;

	void update() 			override;	
	void draw()		 const 	override;
	bool is_player() const 	override;
	bool is_mortal() const 	override;
	bool is_goal() 	 const 	override;

	bool there_is_player() 	const;
	bool reached_goal() 	const;

	void add_game_object(GameObject* o);
	void move_object	(GameObject* o);
	void remove_object	(GameObject* o);

	int8_t get_size() const;

private:
	int8_t								m_size;
	std::vector<std::vector<GameObject*>>   m_world_matrix; 	// matrix representing the world, used for collisions
	std::vector<GameObject*>  				m_obj_vector; 		// vector with all the game object in the scene
	bool 					  				m_is_there_player;
	bool 					  				m_reached_goal{false};
};

} // minimaze

#endif // SCENE_H
