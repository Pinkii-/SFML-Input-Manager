#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "InputManager.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(10,10),"input manager testing");

	InputManager::bind("walk", sf::Keyboard::W);
	InputManager::bind("attack", sf::Keyboard::A);
    InputManager::bind("walk",sf::Keyboard::S); // Rebinding walk
    InputManager::bind("attack",sf::Mouse::Right);

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
		if (InputManager::action("walk")) std::cout << "walking" << std::endl;
        if (InputManager::action("attack")) std::cout << "attacking" << std::endl;
        std::cout << std::endl;

		window.clear();
		window.display();
	}
}
