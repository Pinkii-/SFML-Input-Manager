#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "InputManager.hpp"

int main() {
	sf::RenderWindow window(sf::ViodeMode(10,10),"input manager testing");

	InputManager::bind("walk", sf::Keyboard::W);
	InputManager::bind("attack", sf::Keyboard::A);

	while(window.isOpen()) {

		InputManager::update();

		if (InputManager::action("walk")) std::cout << "walking" << std::endl;
		if (InputManager::action("attack")) std::cout << "attacking" << std::endl;

		window.clear();
		window.display();
	}
}