#include "Game.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: m_window(sf::VideoMode({ 640, 480 }), "SFML Application")
	, m_world(m_window)
{
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window.isOpen()) { // main (game) loop
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
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

void Game::update(sf::Time deltaTime) {
	m_world.update(deltaTime);
}

void Game::render() {
	m_window.clear();
	m_world.draw();

	m_window.setView(m_window.getDefaultView());
	m_window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Scan scan, bool isPressed)
{
}
