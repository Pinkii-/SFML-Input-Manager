#include "InputManager.hpp"

std::map<std::string, InputManager::helperK> InputManager::keyboardBinds;
std::map<std::string, InputManager::helperM> InputManager::mouseBinds;

void InputManager::bind(std::string s, sf::Keyboard::Key k) {
    if (keyboardBinds.find(s) == keyboardBinds.end()) keyboardBinds.insert(std::make_pair(s,helperK(k,false)));
    else keyboardBinds.at(s) = helperK(k,false);
}

void InputManager::bind(std::string s, sf::Mouse::Button m) {
    if (mouseBinds.find(s) == mouseBinds.end()) mouseBinds.insert(std::make_pair(s,helperM(m,false)));
    else mouseBinds.at(s) = helperM(m,false);
}

bool InputManager::isBinded(std::string s) {
    return (keyboardBinds.find(s) != keyboardBinds.end()) || (mouseBinds.find(s) != mouseBinds.end());
}

bool InputManager::isKeyboardBinded(std::string s) {
    return (keyboardBinds.find(s) != keyboardBinds.end());
}

bool InputManager::isMouseBinded(std::string s) {
    return (mouseBinds.find(s) != mouseBinds.end());
}

bool InputManager::action(std::string s) {
    auto itK = keyboardBinds.find(s);
    auto itM = mouseBinds.find(s);
    if (itK == keyboardBinds.end() && itM == mouseBinds.end()) return false;
    else return (*itK).second.b || (*itM).second.b;
}

void InputManager::update() {
    for (auto& kb : keyboardBinds) {
        kb.second.b = sf::Keyboard::isKeyPressed(kb.second.k);
    }
    for (auto& ms : mouseBinds) {
        ms.second.b = sf::Mouse::isButtonPressed(ms.second.m);
    }
}
