#pragma once

#include <SFML/System/Vector2.hpp>

#include "SceneNode.hpp"

/**
 * @brief Base class for all movable game entities
 * 
 * Entity represents any game object that can move, such as aircraft,
 * projectiles, or other dynamic objects. It extends SceneNode with
 * velocity-based movement.
 */
class Entity : public SceneNode {
public:
	/**
	 * @brief Set the entity's velocity
	 * 
	 * @param velocity New velocity vector in pixels per second
	 */
	void setVelocity(sf::Vector2f velocity);
	
	/**
	 * @brief Get the entity's current velocity
	 * 
	 * @return Current velocity vector in pixels per second
	 */
	sf::Vector2f getVelocity() const;

private:
	/**
	 * @brief Update the entity's position based on its velocity
	 * 
	 * @param dt Time elapsed since the last update
	 */
	virtual void updateCurrent(sf::Time dt) override;

private:
	sf::Vector2f m_velocity;
};