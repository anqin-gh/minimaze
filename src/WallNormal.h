#ifndef WALLNORMAL_H
#define WALLNORMAL_H

#include <Wall.h>

namespace minimaze {

class WallNormal : public Wall {
public:
	WallNormal() = default;
	~WallNormal() = default;

	// abstract methods defining the interface
	void update() override;
	
	void draw() 	 const override;
	bool is_mortal() const override;
};

} // minimaze

#endif // WALLNORMAL_H
