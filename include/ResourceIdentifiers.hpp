#pragma once

// forward declaration for SFML classes
namespace sf {
	class Texture;
}

/**
 * @brief Namespace containing texture identifiers for the game
 */
namespace Textures {
	enum ID {
		Eagle,
		Raptor,
		Desert
	};
}

// forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

/**
 * @brief Type alias for a texture resource holder
 */
using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;