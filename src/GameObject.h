#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <cstdint>

// abstract class defining the interface for game objects 
// (player, enemies, walls, scene & goal)
class GameObject {
public:
	GameObject() = default;
	virtual ~GameObject() = default;

	void set_location(int8_t x, int8_t y);
	void set_next_movement(int8_t dx, int8_t dy);

	int8_t 	get_x() 		const;
	int8_t 	get_y() 		const;
	int8_t 	get_next_x()	const;
	int8_t 	get_next_y() 	const;
	bool 	wants_to_move() const;

	// abstract methods defining the interface
	virtual void update() 				= 0;
	virtual void draw() 		const 	= 0;
	virtual bool is_player() 	const 	= 0;
	virtual bool is_mortal() 	const 	= 0;

protected:
	int8_t 	m_x, m_y;			// current location
	int8_t 	m_nx, m_ny; 		// desired movement
	bool 	m_wants_to_move;	// flag to know whether the object wants to move
};

#endif // GAMEOBJECT_H