#ifndef WALL_H
#define WALL_H

#include <GameObject.h>

namespace minimaze {

class Wall : public GameObject {
public:
	Wall() = default;
	virtual ~Wall() override  = default;

	// abstract methods defining the interface
	virtual void update() override = 0;
	
	virtual void draw() 		const override = 0;
	virtual bool is_mortal() 	const override = 0;

	bool is_player() const override {return false;}
};

} // minimaze

#endif // WALL_H
