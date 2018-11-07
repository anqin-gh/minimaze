#include <KeyManager.h>
#include <StdPijo.h>

namespace minimaze {

KeyManager& KeyManager::get_instance() {
	static KeyManager instance;
	return instance;
}

void update() {
	m_last_key_pressed = STDP::ObtenTecla();
}

char get_last_key() const{
	return m_last_key_pressed;
}

// void wait4key() const{
// 	clear();
// 	do {
// 		update();
// 	} while (m_last_key_pressed == -1);
// }

void clear() const{
	while(STDP::ObtenTecla() > -1);
}

} // minimaze
