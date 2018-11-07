#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>

class Player : public GameObject {
public:
	Player();
	virtual ~Player() = default;

	// abstract methods defining the interface
	virtual void update() 		 		override;
	virtual void draw() 		const 	override;
	virtual bool is_player() 	const 	override;
	virtual bool is_mortal() 	const 	override;

private:
	KeyManager* m_key_manager;
	// RendererManager* m_rend_manager;
};

#endif // PLAYER_H