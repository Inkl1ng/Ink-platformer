#pragma once

#include "ResourceIDs.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string_view>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    ResourceHolder();

    void            load(Identifier id, const std::string& filename);
    Resource&       get(Identifier id);
    const Resource& get(Identifier id) const;

private:
    const char* getResourceDirectory();

private:
    std::map<Identifier, std::unique_ptr<Resource>> m_resource_map;
    const char*                                     m_resource_directory;
};

// typedefs for the 4 different resources
typedef ResourceHolder<sf::Texture, TextureID>   TextureHolder;
typedef ResourceHolder<sf::Font, FontID>         FontHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundID> SoundHolder;
typedef ResourceHolder<sf::Music, MusicID>       MusicHolder;

#include "ResourceHolder.tpp"
