#pragma once

#include <cassert>
#include <functional>

#include <SFML/System.hpp>

class SceneNode;

struct Command {
	std::function<void(SceneNode&, sf::Time)> action;
};