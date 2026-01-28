#pragma once

#include <SFML/System.hpp>
#include <cassert>
#include <functional>

class SceneNode;

struct Command {
  Command();
  std::function<void(SceneNode &, sf::Time)> action;
  unsigned int                               category;
};