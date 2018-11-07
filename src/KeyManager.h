#ifndef KEYMANAGER_H
#define KEYMANAGER_H

namespace minimaze {

class KeyManager {
public:
	~KeyManager() = default;
	KeyManager(const KeyManager&) = delete;
	KeyManager& operator=(const KeyManager&) = delete;

	static KeyManager& get_instance();

	void update();
	char get_last_key()	const;
	// char wait4key()		const;
	void clear()		const;
private:
	char m_last_key_pressed;

	KeyManager() = default;
};

} // minimaze

#endif // KEYMANAGER_H
