#include "InputManager.hpp"

std::map<std::string, InputManager::helperK> InputManager::keyboardBinds;
std::map<std::string, InputManager::helperM> InputManager::mouseBinds;
std::map<std::string, InputManager::helperJA> InputManager::joystickAxisBinds;

void InputManager::bind(std::string s, sf::Keyboard::Key k) {
    if (keyboardBinds.find(s) == keyboardBinds.end()) keyboardBinds.insert(std::make_pair(s,helperK(k)));
    else keyboardBinds.at(s) = helperK(k);
}

void InputManager::bind(std::string s, sf::Mouse::Button m) {
    if (mouseBinds.find(s) == mouseBinds.end()) mouseBinds.insert(std::make_pair(s,helperM(m)));
    else mouseBinds.at(s) = helperM(m);
}

void InputManager::bind(std::string s, sf::Joystick::Axis ja, int nPad) {
    if (joystickAxisBinds.find(s) == joystickAxisBinds.end()) joystickAxisBinds.insert(std::make_pair(s,helperJA(ja,nPad)));
    else joystickAxisBinds.at(s) = helperJA(ja, nPad);
}

bool InputManager::isBinded(std::string s) {
    return (keyboardBinds.find(s) != keyboardBinds.end()) || (mouseBinds.find(s) != mouseBinds.end() || joystickAxisBinds.find(s) != joystickAxisBinds.end());
}

bool InputManager::isKeyboardBinded(std::string s) {
    return (keyboardBinds.find(s) != keyboardBinds.end());
}

bool InputManager::isMouseBinded(std::string s) {
    return (mouseBinds.find(s) != mouseBinds.end());
}

bool InputManager::isJoystickBinded(std::string s) {
    return (joystickAxisBinds.find(s) != joystickAxisBinds.end());
}

int InputManager::action(std::string s) {
    auto itK = keyboardBinds.find(s);
    auto itM = mouseBinds.find(s);
    auto itJA = joystickAxisBinds.find(s);
    if (itK == keyboardBinds.end() && itM == mouseBinds.end() && itJA == joystickAxisBinds.end()) return 0;
    else {
        int aux[] = {(*itK).second.b, (*itM).second.b, (*itJA).second.pos};
        return *std::max_element(aux,aux+3);
    }
}

void InputManager::update() {
    for (auto& kb : keyboardBinds) {
        kb.second.b = sf::Keyboard::isKeyPressed(kb.second.k);
    }
    for (auto& ms : mouseBinds) {
        ms.second.b = sf::Mouse::isButtonPressed(ms.second.m);
    }
    for (auto& jas : joystickAxisBinds) {
        jas.second.pos = sf::Joystick::getAxisPosition(jas.second.nPad,jas.second.j);
    }
}
