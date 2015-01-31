#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <map>
#include <SFML/Window.hpp>

class InputManager {
private:
    struct helper {
        bool b;
        sf::Keyboard::Key k;
        helper(sf::Keyboard::Key kk,bool bb) {
            b = bb;
            k = kk;
        }
    };
    static std::map<std::string, helper> keyboardBinds;
public:
    static void bind(std::string s, sf::Keyboard::Key k);
    static bool isBinded(std::string s);
    static bool action(std::string s);
    static void update();
};

#endif // INPUTMANAGER_HPP
