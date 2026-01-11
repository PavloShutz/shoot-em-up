#pragma once

#include <memory>
#include <vector>

class SceneNode {
public:
	using	Ptr = std::unique_ptr<SceneNode>;

public:
	SceneNode();

private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;
};