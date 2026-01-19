#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

/**
 * @brief Base class for all scene graph nodes
 * 
 * SceneNode implements a hierarchical scene graph structure where each node
 * can have children and applies transformations relative to its parent.
 * It handles both transformation propagation and rendering of the scene tree.
 */
class SceneNode : public sf::Transformable, public sf::Drawable {
public:
	using Ptr = std::unique_ptr<SceneNode>; /**< Unique pointer type for scene nodes */

public:
	/**
	 * @brief Construct a new scene node
	 */
	SceneNode();
	
	// disable copying
	SceneNode(const SceneNode&) = delete;
	SceneNode& operator=(const SceneNode&) = delete;

	/**
	 * @brief Attach a child node to this node
	 * 
	 * The child will be owned by this node and inherit its transformations.
	 * 
	 * @param child Unique pointer to the child node to attach
	 */
	void attachChild(Ptr child);
	
	/**
	 * @brief Detach a child node from this node
	 * 
	 * @param node Reference to the child node to detach
	 * @return Unique pointer to the detached child node
	 */
	Ptr detachChild(const SceneNode& node);

private:
	/**
	 * @brief Draw this node and all its children
	 * 
	 * @param target Render target to draw to
	 * @param states Current render states including transformations
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;
	
	/**
	 * @brief Draw only this node (without children)
	 * 
	 * Override this method in derived classes to provide custom rendering.
	 * 
	 * @param target Render target to draw to
	 * @param states Current render states including transformations
	 */
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	
	/**
	 * @brief Draw all children of this node
	 * 
	 * @param target Render target to draw to
	 * @param states Current render states including transformations
	 */
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	/**
	 * @brief Update this node and all its children
	 * 
	 * @param dt Time elapsed since the last update
	 */
	void update(sf::Time dt);

	/**
	 * @brief Get the world transformation of this node
	 * 
	 * Computes the absolute transformation by combining all parent transformations.
	 * 
	 * @return Combined transformation from root to this node
	 */
	sf::Transform getWorldTransform() const;
	
	/**
	 * @brief Get the world position of this node
	 * 
	 * @return Absolute position in world coordinates
	 */
	sf::Vector2f getWorldPosition() const;

private:
	/**
	 * @brief Update only this node (without children)
	 * 
	 * Override this method in derived classes to provide custom update logic.
	 * 
	 * @param dt Time elapsed since the last update
	 */
	virtual void updateCurrent(sf::Time dt);
	
	/**
	 * @brief Update all children of this node
	 * 
	 * @param dt Time elapsed since the last update
	 */
	void updateChildren(sf::Time dt);

private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;
};