#include "SceneNode.hpp"

#include <algorithm>
#include <cassert>

SceneNode::SceneNode() : m_children(), m_parent(nullptr) {}

void SceneNode::attachChild(Ptr child)
{
	child->m_parent = this;
	m_children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(m_children.begin(), m_children.end(),
		[&](Ptr& p) -> bool {return p.get() == &node; });

	assert(found != m_children.end());

	Ptr result = std::move(*found);
	result->m_parent = nullptr;
	m_children.erase(found);
	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();  // place current node in the world
	drawCurrent(target, states);

	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& child : m_children)
		child->draw(target, states);
}
