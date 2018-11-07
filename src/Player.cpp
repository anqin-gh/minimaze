#ifndef PLAYER_H
#define PLAYER_H

#include <KeyManager.h>
#include <Player.h>

Player() : m_key_manager{&KeyManager.get_instance()} {}

void Player::update() {
	switch (m_key_manager->get_last_key()) {
		case 'w' : set_next_movement( 0, -1): break;
		case 's' : set_next_movement( 0,  1): break;
		case 'a' : set_next_movement(-1,  0): break;
		case 'd' : set_next_movement( 1,  0): break;
		default: break;
	}
}

void Player::draw() const {}

bool Player::is_player() const {return true;}

bool Player::is_mortal() const {return false;}

