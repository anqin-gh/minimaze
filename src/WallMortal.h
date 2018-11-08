#ifndef WALLMORTAL_H
#define WALLMORTAL_H

#include <Wall.h>

namespace minimaze {

class WallMortal : public Wall {
public:
	WallMortal() = default;
	~WallMortal() = default;

	// abstract methods defining the interface
	void update() override;
	
	void draw() 		const override;
	bool is_mortal() 	const override;
};

} // minimaze

#endif // WALLMORTAL_H
