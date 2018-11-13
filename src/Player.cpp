#include <KeyManager.h>
#include <Renderer.h>
#include <RendSTDP.h>
#include <RendSTDP2.h>
#include <RendManager.h>
#include <Player.h>

namespace minimaze {

Player::Player() 
	: m_key_manager{&KeyManager::get_instance()} 
	, m_rend_manager{&RendManager::get_instance()}
{

}

void Player::update() {
	switch (m_key_manager->get_last_key()) {
		case 'w' : set_next_movement( 0, -1); break;
		case 's' : set_next_movement( 0,  1); break;
		case 'a' : set_next_movement(-1,  0); break;
		case 'd' : set_next_movement( 1,  0); break;
		default: break;
	}
}

void Player::draw() const {
	m_rend_manager->renderer().draw_player(m_x, m_y);
}

bool Player::is_player() const {return true;}

bool Player::is_mortal() const {return false;}

bool Player::is_goal() const {return false;}

} // minimaze
