#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void handlePlayerInput(sf::Keyboard::Scan scan, bool isPressed);

private:
	sf::RenderWindow m_window;
	//sf::CircleShape m_player;
	sf::Texture m_texture;
	sf::Sprite m_player;

	bool m_isMovingUp = false;
	bool m_isMovingDown = false;
	bool m_isMovingRight = false;
	bool m_isMovingLeft = false;

	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};