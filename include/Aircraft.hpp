#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

/**
 * @brief Represents an aircraft entity in the game
 *
 * Aircraft is a specialized entity that displays a sprite based on its type
 * (Eagle or Raptor). It handles loading the appropriate texture and rendering.
 */
class Aircraft : public Entity {
 public:
  enum Type { Eagle, Raptor };

 public:
  /**
   * @brief Construct a new aircraft
   *
   * @param type Type of aircraft
   * @param textures Reference to the texture holder containing aircraft
   * textures
   */
  explicit Aircraft(Type type, const TextureHolder& textures);

  /**
   * @brief Draw the aircraft sprite
   *
   * @param target Render target to draw to
   * @param states Current render states including transformations
   */
  virtual void drawCurrent(sf::RenderTarget& target,
                           sf::RenderStates states) const override;

 private:
  Type m_type;
  sf::Sprite m_sprite;
};