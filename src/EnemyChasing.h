#ifndef ENEMYCHASING_H
#define ENEMYCHASING_H

#include <Enemy.h>

namespace minimaze {

class RendManager;

class EnemyChasing : public Enemy {
public:
	EnemyChasing();
	~EnemyChasing() override = default;

	// abstract methods defining the interface
	void update() override;	
	void draw() const override;

private:
	int8_t m_dir;
	RendManager* m_rend_manager;
};

} // minimaze

#endif // ENEMYCHASING_H
