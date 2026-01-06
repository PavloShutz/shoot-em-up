#include "Game.hpp"

Game::Game()
	: m_window(sf::VideoMode({ 640, 480 }), "SFML Application")
	, m_player()
{
	m_player.setRadius(40.f);
	m_player.setPosition({ 100.f, 100.f });
	m_player.setFillColor(sf::Color::Cyan);
}

void Game::run() {
	while (m_window.isOpen()) { // main (game) loop
		processEvents();
		update();
		render();
	}
}

void Game::processEvents() {
	while (const std::optional event = m_window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			m_window.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
			handlePlayerInput(keyPressed->scancode, true);
		}
		else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
			handlePlayerInput(keyReleased->scancode, false);
		}
	}
}

void Game::update() {
	sf::Vector2f movement({ 0.f, 0.f });
	
	if (m_isMovingUp)
		movement.y -= 1.f;
	if (m_isMovingDown)
		movement.y += 1.f;
	if (m_isMovingLeft)
		movement.x -= 1.f;
	if (m_isMovingRight)
		movement.x += 1.f;

	m_player.move(movement);
}

void Game::render() {
	m_window.clear();
	m_window.draw(m_player);
	m_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Scan scan, bool isPressed)
{
	if (scan == sf::Keyboard::Scancode::W)
		m_isMovingUp = isPressed;
	else if (scan == sf::Keyboard::Scancode::S)
		m_isMovingDown = isPressed;
	else if (scan == sf::Keyboard::Scancode::D)
		m_isMovingRight = isPressed;
	else if (scan == sf::Keyboard::Scancode::A)
		m_isMovingLeft = isPressed;
}
