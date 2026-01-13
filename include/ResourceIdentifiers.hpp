#pragma once

// forward declaration for SFML classes
namespace sf {
	class Texture;
}

namespace Textures {
	enum ID {
		Eagle,
		Raptor
	};
}

// forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;