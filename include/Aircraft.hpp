#pragma once

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

/**
 * @brief Represents an aircraft entity in the game
 * 
 * Aircraft is a specialized entity that displays a sprite based on its type
 * (Eagle or Raptor). It handles loading the appropriate texture and rendering.
 */
class Aircraft : public Entity {
public:
	/**
	 * @brief Enumeration of available aircraft types
	 */
	enum Type {
		Eagle,  /**< Eagle aircraft type */
		Raptor  /**< Raptor aircraft type */
	};

public:
	/**
	 * @brief Construct a new aircraft
	 * 
	 * @param type Type of aircraft (Eagle or Raptor)
	 * @param textures Reference to the texture holder containing aircraft textures
	 */
	explicit Aircraft(Type type, const TextureHolder& textures);
	
	/**
	 * @brief Draw the aircraft sprite
	 * 
	 * @param target Render target to draw to
	 * @param states Current render states including transformations
	 */
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Type m_type;        /**< Type of this aircraft */
	sf::Sprite m_sprite; /**< Sprite used to render the aircraft */
};