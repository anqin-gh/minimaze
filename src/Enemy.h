#ifndef ENEMY_H
#define ENEMY_H

#include <GameObject.h>

namespace minimaze {

class Enemy : public GameObject {
public:
	Enemy() = default;
	virtual ~Enemy() override = default;

	// abstract methods defining the interface
	virtual void update() override = 0;
	
	virtual void draw() const override = 0;

	virtual bool is_player() const override {return false;}
	virtual bool is_mortal() const override {return true;}
	virtual bool is_goal() 	 const override {return false;}
};

} // minimaze

#endif // ENEMY_H
