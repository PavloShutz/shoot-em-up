#include "World.hpp"
#include "SpriteNode.hpp"

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

void World::buildScene() {
	for (std::size_t i = 0; i < LayerCount; ++i) {
		SceneNode::Ptr layer(new SceneNode());
		m_sceneLayers[i] = layer.get();

		m_sceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& texture = m_textures.get(Textures::Desert);
	sf::IntRect textureRect(m_worldBounds);
	texture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(m_worldBounds.position);
	m_sceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Aircraft> leader(
		new Aircraft(Aircraft::Eagle, m_textures));
	m_playerAircraft = leader.get();
	m_playerAircraft->setPosition(m_spawnPosition);
	m_playerAircraft->setVelocity({ 40.f, m_scrollSpeed });
	m_sceneLayers[Air]->attachChild(std::move(leader));

	std::unique_ptr<Aircraft> leftEscort(
		new Aircraft(Aircraft::Raptor, m_textures));
	leftEscort->setPosition({ -80.f, 50.f });
	m_playerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort(
		new Aircraft(Aircraft::Raptor, m_textures));
	rightEscort->setPosition({ 80.f, 50.f });
	m_playerAircraft->attachChild(std::move(rightEscort));
}
