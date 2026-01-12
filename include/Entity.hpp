#pragma once

#include <SFML/System/Vector2.hpp>

#include "SceneNode.hpp"

class Entity : public SceneNode {
public:
	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity() const;

private:
	sf::Vector2f m_velocity;
};