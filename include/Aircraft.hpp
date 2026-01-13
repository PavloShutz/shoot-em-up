#pragma once

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Aircraft : public Entity {
public:
	enum Type {
		Eagle,
		Raptor
	};

public:
	explicit Aircraft(Type type, const TextureHolder& textures);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Type m_type;
	sf::Sprite m_sprite;
};