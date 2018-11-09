#ifndef WALLNORMAL_H
#define WALLNORMAL_H

#include <Wall.h>

namespace minimaze {

class RendManager;

class WallNormal : public Wall {
public:
	WallNormal();
	~WallNormal() = default;

	// abstract methods defining the interface
	void update() override;
	
	void draw() 	 const override;
	bool is_mortal() const override;
private:
	RendManager* m_rend_manager;
};

} // minimaze

#endif // WALLNORMAL_H
