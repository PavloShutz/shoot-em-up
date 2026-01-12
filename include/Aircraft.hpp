#pragma once

#include "Entity.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <optional>

class Aircraft : public Entity {
public:
	enum Type {
		Eagle,
		Raptor
	};

public:
	explicit Aircraft(Type type);
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Type m_type;
	std::optional<sf::Sprite> m_sprite;
};