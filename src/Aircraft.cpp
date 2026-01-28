#include "Aircraft.hpp"

#include "ResourceHolder.hpp"

/**
 * @brief Convert aircraft type to texture identifier
 *
 * @param type Aircraft type to convert
 * @return Corresponding texture identifier
 */
Textures::ID toTextureID(Aircraft::Type type) {
  switch (type) {
    case Aircraft::Eagle : return Textures::Eagle;
    case Aircraft::Raptor: return Textures::Raptor;
  }
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
    : m_type(type), m_sprite(textures.get(toTextureID(type))) {
  sf::FloatRect bounds = m_sprite.getLocalBounds();
  m_sprite.setOrigin(bounds.size / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target,
                           sf::RenderStates  states) const {
  target.draw(m_sprite, states);
}

unsigned int Aircraft::getCategory() const {
  switch (m_type) {
    case Eagle: return static_cast<unsigned int>(Category::PlayerAircraft);
    default   : return static_cast<unsigned int>(Category::EnemyAircraft);
  }
}
