#pragma once

#include "ResourceHolder.hpp"

#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include <string_view>
#include <type_traits>
#include <cassert>

template <typename Resource, typename Identifier>
Resource_holder<Resource, Identifier>::Resource_holder()
    : resource_map {} {
}

template <typename Resource, typename Identifier>
void Resource_holder<Resource, Identifier>::load(Identifier id, const std::string& filename) {
    auto resource = std::make_unique<Resource>();

    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("ResourceHolder::load() - Failed to load "
            + filename);
    }

    resource_map.insert(std::make_pair<>(id, std::move(resource)));
}

template <typename Resource, typename Identifier>
Resource& Resource_holder<Resource, Identifier>::get(Identifier id) {
    auto found = resource_map.find(id);
    assert(found != resource_map.end());

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& Resource_holder<Resource, Identifier>::get(Identifier id) const {
    auto found = resource_map.find(id);
    assert(found != resource_map.end());

    return *found->second;
}
