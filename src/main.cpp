#include <SFML/System.hpp>

#include "main.h"
#include "Game.h"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode({ WindowWidth, WindowHeight }), "Survidle");
	window.setVerticalSyncEnabled(true);

	Game game(window);

	sf::Clock clock;

	// Start the game loop
	while (window.isOpen())
	{
		sf::Time delta = clock.restart();

		// Process events
		while (const std::optional event = window.pollEvent())
		{
			// Close window: exit
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		game.update(delta.asSeconds());

		window.clear(sf::Color::Black);
		game.render();
		window.display();
	}
}
