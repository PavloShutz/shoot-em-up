#include "TextureHolder.hpp"

void TextureHolder::load(Texture id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
		;
	m_textureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(Texture id)
{
	auto found = m_textureMap.find(id);
	return *found->second;
}

const sf::Texture& TextureHolder::get(Texture id) const
{
	auto found = m_textureMap.find(id);
	return *found->second;
}
