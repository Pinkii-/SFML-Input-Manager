#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <map>
#include <SFML/Window.hpp>

class InputManager {
private:
    struct helperK {
        bool b;
        sf::Keyboard::Key k;
        helperK(sf::Keyboard::Key kk,bool bb) {
            b = bb;
            k = kk;
        }
    };
    struct helperM {
        bool b;
        sf::Mouse::Button m;
        helperM(sf::Mouse::Button mm,bool bb) {
            b = bb;
            m = mm;
        }
    };

    static std::map<std::string, helperK> keyboardBinds;
    static std::map<std::string, helperM> mouseBinds;
public:
    static void bind(std::string s, sf::Keyboard::Key k);
    static void bind(std::string s, sf::Mouse::Button m);
    static bool isBinded(std::string s);
    static bool isKeyboardBinded(std::string s);
    static bool isMouseBinded(std::string s);
    static bool action(std::string s);
    static void update();
};

#endif // INPUTMANAGER_HPP
