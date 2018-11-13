#ifndef WALLMORTAL_H
#define WALLMORTAL_H

#include <Wall.h>

namespace minimaze {

class RendManager;

class WallMortal : public Wall {
public:
	WallMortal();
	~WallMortal() override = default;

	// abstract methods defining the interface
	void update() override;
	
	void draw()			const override;
	bool is_mortal()	const override;
private:
	RendManager* m_rend_manager;
};

} // minimaze

#endif // WALLMORTAL_H
