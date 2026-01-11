#pragma once

#include <memory>
#include <vector>

class SceneNode {
public:
	using	Ptr = std::unique_ptr<SceneNode>;

public:
	SceneNode();

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;
};