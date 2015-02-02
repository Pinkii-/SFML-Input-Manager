#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "InputManager.hpp"

namespace InputAction {
  enum action {
      walk, attack, broken
  };
}

int main() {
    sf::RenderWindow window(sf::VideoMode(10,10),"input manager testing");

    InputManager::bind(InputAction::walk, sf::Keyboard::W);
    InputManager::bind(InputAction::attack, sf::Keyboard::A);
    InputManager::bind(InputAction::walk ,sf::Keyboard::S); // Rebinding walk
    InputManager::bind(InputAction::attack, sf::Mouse::Right);
    InputManager::bind(InputAction::broken, sf::Mouse::Left);

	while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        InputManager::update();
        if (InputManager::action(InputAction::walk)) std::cout << "walking" << std::endl;
        if (InputManager::action(InputAction::attack)) std::cout << "attacking" << std::endl;
        if (InputManager::action(InputAction::broken)) std::cout << "brokeen" << std::endl;
        std::cout << std::endl;

		window.clear();
		window.display();
	}
}
