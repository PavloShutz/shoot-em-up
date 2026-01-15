#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable {
public:
	using Ptr = std::unique_ptr<SceneNode>;

public:
	SceneNode();
	// disable copying
	SceneNode(const SceneNode&) = delete;
	SceneNode& operator=(const SceneNode&) = delete;

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final override;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	void update(sf::Time dt);

private:
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;
};