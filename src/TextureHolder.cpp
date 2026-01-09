#include <cassert>
#include <stdexcept>

#include "TextureHolder.hpp"

void TextureHolder::load(Texture id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
		throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
	
	auto inserted = m_textureMap.insert(std::make_pair(id, std::move(texture)));
	assert(inserted.second);
}

sf::Texture& TextureHolder::get(Texture id)
{
	auto found = m_textureMap.find(id);
	assert(found != m_textureMap.end());

	return *found->second;
}

const sf::Texture& TextureHolder::get(Texture id) const
{
	auto found = m_textureMap.find(id);
	assert(found != m_textureMap.end());
	
	return *found->second;
}
