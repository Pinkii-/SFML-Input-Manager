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
    struct helperJB {
        bool b;
        int nPad;
        int nButton;
        helperJB(int nPad, int nButton) {
            this->b = false;
            this->nPad = nPad;
            this->nButton = nButton;
        }
    };

    static std::map<int, helperK> keyboardBinds;
    static std::map<int, helperM> mouseBinds;
    static std::map<int, helperJA> joystickAxisBinds;
    static std::map<int, helperJB> joystickButtonBinds;
public:
    static void bind(int s, sf::Keyboard::Key k);
    static void bind(int s, sf::Mouse::Button m);
    static void bind(int s, int nPad, sf::Joystick::Axis ja);
    static void bind(int s, int nPad, int nButton);
    static bool isBinded(int s);
    static bool isKeyboardBinded(int s);
    static bool isMouseBinded(int s);
    static bool isJoystickBinded(int s);
    static int action(int s);
    static void update();
};

#endif // INPUTMANAGER_HPP
