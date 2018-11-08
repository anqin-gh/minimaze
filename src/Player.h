#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>

namespace minimaze {

class KeyManager;

class Player : public GameObject {
public:
	Player();
	~Player() = default;

	// abstract methods defining the interface
	void update() 		 		override;
	void draw() 		const 	override;
	bool is_player() 	const 	override;
	bool is_mortal() 	const 	override;

private:
	KeyManager* m_key_manager;
	RendererManager* m_rend_manager;
};

} // minimaze

#endif // PLAYER_H
