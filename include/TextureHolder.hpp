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

private:
	void load(Texture id, const std::string& filename);
};
