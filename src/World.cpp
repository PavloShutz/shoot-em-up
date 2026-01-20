#include "World.hpp"

World::World(sf::RenderWindow& window)
	: m_window(window)
	, m_worldView(window.getDefaultView())
	, m_textures()
	, m_sceneGraph()
	, m_sceneLayers()
	, m_worldBounds({ 0.f, 0.f	}, { m_worldView.getSize().x, 2000.f })
	, m_spawnPosition({m_worldView.getSize().x / 2.f, m_worldBounds.size.y - m_worldView.getSize().y / 2.f})
	, m_scrollSpeed(-50.f)
	, m_playerAircraft(nullptr)
{
	loadTextures();
	buildScene();

	// Prepare the view
	m_worldView.setCenter(m_spawnPosition);
}

void World::loadTextures() {
	m_textures.load(Textures::Eagle, "../media/textures/eagle.png");
	m_textures.load(Textures::Raptor, "../media/textures/raptor.png");
	m_textures.load(Textures::Desert, "../media/textures/dune_simple.png");
}