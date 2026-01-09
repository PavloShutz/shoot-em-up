#include "ResourceHolder.hpp"
template<typename Resource, typename Identifier>
void ResourceHolder::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	insertResource(id, resource);
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder::load(Identifier id,
	const std::string& filename, const Parameter& secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	insertResource(id, resource);
}

template<typename Resource, typename Identifier>
Resource& ResourceHolder::get(Identifier id)
{
	auto found = m_resourceMap.find(id);
	assert(found != m_resourceMap.end());

	// if resouce is found, return pointer to it
	return *found->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder::get(Identifier id) const
{
	auto found = m_resourceMap.find(id);
	assert(found != m_resourceMap.end());

	// if resouce is found, return pointer to it
	return *found->second;
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	auto inserted = m_resourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}
