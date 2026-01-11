#include "SceneNode.hpp"

#include <algorithm>
#include <cassert>

SceneNode::SceneNode() : m_parent(nullptr) {}

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
