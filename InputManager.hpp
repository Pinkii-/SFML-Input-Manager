#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

class InputManager {
private:
	static std::map<std::string, sf::Keyboard::Key> keyboardBinds;
public:
	void bind(std::string s, sf::Keyboard::Key);
	bool action(std::string);
};

#endif // INPUTMANAGER_HPP