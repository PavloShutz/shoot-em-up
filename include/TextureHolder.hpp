#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

enum class Texture {
	Landscape, Airplane, Missile
};

class TextureHolder {
private:
	std::map <Texture, std::unique_ptr<sf::Texture>> m_textureMap;

public:
	void load(Texture id, const std::string& filename);
	sf::Texture& get(Texture id);
	const sf::Texture& get(Texture id) const;
};
