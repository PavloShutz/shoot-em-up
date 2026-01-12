#include "Aircraft.hpp"

// TODO: Initialize sprite object
Aircraft::Aircraft(Type type) : m_type(type) {

}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_sprite.has_value()) {
		target.draw(m_sprite.value(), states);
	}
}
