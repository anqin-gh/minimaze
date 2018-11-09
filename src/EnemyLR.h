#ifndef ENEMYLR_H
#define ENEMYLR_H

#include <Enemy.h>

namespace minimaze {

class RendManager;

class EnemyLR : public Enemy {
public:
	EnemyLR();
	~EnemyLR() = default;

	// abstract methods defining the interface
	void update() override;	
	void draw() const override;

private:
	int8_t m_dir;
	RendManager* m_rend_manager;
};

} // minimaze

#endif // ENEMYLR_H
