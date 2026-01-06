#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();

	void handlePlayerInput(sf::Keyboard::Scan scan, bool isPressed);

private:
	sf::RenderWindow m_window;
	sf::CircleShape m_player;

	bool m_isMovingUp = false;
	bool m_isMovingDown = false;
	bool m_isMovingRight = false;
	bool m_isMovingLeft = false;
};