#pragma once

#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

/**
 * @brief Template class for managing game resources
 *
 * This class provides centralized loading and access to game resources like
 * textures, fonts, and sounds. Resources are identified by a unique identifier
 * and loaded from files.
 *
 * @tparam Resource The type of resource to manage (e.g., sf::Texture, sf::Font)
 * @tparam Identifier The type used to identify resources (typically an enum)
 */
template <typename Resource, typename Identifier>
class ResourceHolder {
 public:
  /**
   * @brief Load a resource from a file
   *
   * @param id Unique identifier for the resource
   * @param filename Path to the resource file
   * @throws std::runtime_error if the resource cannot be loaded
   */
  void load(Identifier id, const std::string& filename);

  /**
   * @brief Load a resource from a file with an additional parameter
   *
   * @tparam Parameter Type of the additional parameter
   * @param id Unique identifier for the resource
   * @param filename Path to the resource file
   * @param secondParam Additional parameter for loading (e.g., shader type)
   * @throws std::runtime_error if the resource cannot be loaded
   */
  template <typename Parameter>
  void load(Identifier id, const std::string& filename,
            const Parameter& secondParam);

  /**
   * @brief Get a non-const reference to a loaded resource
   *
   * @param id Identifier of the resource to retrieve
   * @return Reference to the requested resource
   */
  Resource& get(Identifier id);

  /**
   * @brief Get a const reference to a loaded resource
   *
   * @param id Identifier of the resource to retrieve
   * @return Const reference to the requested resource
   */
  const Resource& get(Identifier id) const;

 private:
  /**
   * @brief Insert a resource into the resource map
   *
   * @param id Unique identifier for the resource
   * @param resource Unique pointer to the resource
   */
  void insertResource(Identifier id, std::unique_ptr<Resource> resource);

 private:
  std::map<Identifier, std::unique_ptr<Resource>>
      m_resourceMap; /**< Map storing all loaded resources */
};

#include "ResourceHolder.inl"