#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "Aircraft.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"

class World {
 public:
  explicit World(sf::RenderWindow& window);

  // disable copying
  World(const World&)            = delete;
  World& operator=(const World&) = delete;

  void update(sf::Time dt);
  void draw();

 private:
  void loadTextures();
  void buildScene();

 private:
  enum Layer { Background, Air, LayerCount };

 private:
  sf::RenderWindow&                  m_window;
  sf::View                           m_worldView;
  TextureHolder                      m_textures;
  SceneNode                          m_sceneGraph;
  std::array<SceneNode*, LayerCount> m_sceneLayers;

  sf::FloatRect m_worldBounds;
  sf::Vector2f  m_spawnPosition;
  float         m_scrollSpeed;
  Aircraft*     m_playerAircraft;
};