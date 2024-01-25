#pragma once

#include "ResourceHolder.hpp"

#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include <string_view>
#include <type_traits>

template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::ResourceHolder()
    : m_resource_map {}
    , m_resource_directory {getResourceDirectory()}
{
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    auto resource {std::make_unique<Resource>()};

    if (!resource->loadFromFile(m_resource_directory + filename))
    {
        // TODO: error handling
    }

    m_resource_map.insert(std::make_pair<>(id, std::move(resource)));
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = m_resource_map.find(id);
    // TODO: error handling

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    auto found = m_resource_map.find(id);
    // TODO: error handling

    return *found->second;
}

template <typename Resource, typename Identifier>
const char* ResourceHolder<Resource, Identifier>::getResourceDirectory()
{
    if (std::is_same<Resource, sf::Texture>::value)
    {
        return "media/textures/";
    }
    else if (std::is_same<Resource, sf::Font>::value)
    {
        return "media/fonts/";
    }
    else if (std::is_same<Resource, sf::SoundBuffer>::value)
    {
        return "media/sounds/";
    }
    else if (std::is_same<Resource, sf::Music>::value)
    {
        return "media/music/";
    }
}
