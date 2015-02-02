#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <map>
#include <SFML/Window.hpp>

class InputManager {
private:
    struct helperK {
        bool b;
        sf::Keyboard::Key k;
        helperK(sf::Keyboard::Key k) {
            this->b = false;
            this->k = k;
        }
    };
    struct helperM {
        bool b;
        sf::Mouse::Button m;
        helperM(sf::Mouse::Button m) {
            this->b = false;
            this->m = m;
        }
    };
    struct helperJA {
        int pos;
        sf::Joystick::Axis j;
        int nPad;
        helperJA(sf::Joystick::Axis j, int nPad) {
            this->pos = 0;
            this->j = j;
            this->nPad = nPad;
        }
    };

    static std::map<std::string, helperK> keyboardBinds;
    static std::map<std::string, helperM> mouseBinds;
    static std::map<std::string, helperJA> joystickAxisBinds;
public:
    static void bind(std::string s, sf::Keyboard::Key k);
    static void bind(std::string s, sf::Mouse::Button m);
    static void bind(std::string s, sf::Joystick::Axis ja, int nPad);
    static bool isBinded(std::string s);
    static bool isKeyboardBinded(std::string s);
    static bool isMouseBinded(std::string s);
    static bool isJoystickBinded(std::string s);
    static int action(std::string s);
    static void update();
};

#endif // INPUTMANAGER_HPP
