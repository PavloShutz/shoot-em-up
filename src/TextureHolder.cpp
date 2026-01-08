#include "TextureHolder.hpp"

void TextureHolder::load(Texture id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
		;
	m_textureMap.insert(std::make_pair(id, std::move(texture)));
}