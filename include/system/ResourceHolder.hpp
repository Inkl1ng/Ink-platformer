#pragma once

#include "ResourceIDs.hpp"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <string_view>

template <typename Resource, typename Identifier>
class Resource_holder {
public:
                        Resource_holder();

    void                load(Identifier id, const std::string& filename);
    Resource&           get(Identifier id);
    const Resource&     get(Identifier id) const;

private:
    /// Resources are allocated on the heap with unique_ptr's and are associated with a identifier
    std::map<Identifier, std::unique_ptr<Resource>>     resource_map;
};

typedef Resource_holder<sf::Texture, Texture_id>         Texture_holder;
typedef Resource_holder<sf::Font, Font_id>               Font_holder;
typedef Resource_holder<sf::SoundBuffer, Sound_id>       Sound_holder;
typedef Resource_holder<sf::Music, Music_id>             Music_holder;

#include "ResourceHolder.tpp"
