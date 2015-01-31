#include "InputManager.hpp"

std::map<std::string, InputManager::helper> InputManager::keyboardBinds;

void InputManager::bind(std::string s, sf::Keyboard::Key k) {
    keyboardBinds.insert(std::make_pair(s,helper(k,false)));
}

bool InputManager::isBinded(std::string s) {
    return (keyboardBinds.find(s) != keyboardBinds.end());
}

bool InputManager::action(std::string s) {
    auto it = keyboardBinds.find(s);
    if (it == keyboardBinds.end()) return false;
    else return (*it).second.b;
}

void InputManager::update() {

}
