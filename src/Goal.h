#ifndef GOAL_H
#define GOAL_H

#include <GameObject.h>

namespace minimaze {

class RendManager;

class Goal : public GameObject {
public:
	Goal();
	~Goal() = default;

	// abstract methods defining the interface
	void update() override;

	void draw() 	 const override;
	bool is_player() const override;
	bool is_mortal() const override;

private:
	RendManager* m_rend_manager;
};

} // minimaze

#endif // GOAL_H
