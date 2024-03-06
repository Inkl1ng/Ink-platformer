#pragma once

#include "ResourceHolder.hpp"

#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include <string_view>
#include <type_traits>
#include <cassert>

/**
 * Constructor for a Resource_holder
*/
template <typename Resource, typename Identifier>
Resource_holder<Resource, Identifier>::Resource_holder()
    : resource_map {} {
}

/**
 * Loads a specified resource into this instance of a Resource_holder.
 * 
 * @param id The Identifier for the resouce being loaded in.
 * @param filename The path to the file of the resource being loaded in.
 * 
 * @throws std::runtime_error Thrown if the specified resource could not be loaded in.
*/
template <typename Resource, typename Identifier>
void Resource_holder<Resource, Identifier>::load(Identifier id, const std::string& filename) {
    auto resource = std::make_unique<Resource>();

    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("ResourceHolder::load() - Failed to load "
            + filename);
    }

    resource_map.insert(std::make_pair<>(id, std::move(resource)));
}

/**
 * Gets a references to a resource associated with a certain id.
 * 
 * @param id The idnetifier for the resource to be returned.
 * 
 * @returns A reference to the requested resource.
*/
template <typename Resource, typename Identifier>
Resource& Resource_holder<Resource, Identifier>::get(Identifier id) {
    auto found = resource_map.find(id);
    assert(found != resource_map.end());

    return *found->second;
}

/**
 * Gets a references to a resource associated with a certain id
 * 
 * @param id The idnetifier for the resource to be returned
 * 
 * @returns A const reference to the requested resource.
 * 
 * @overload
*/
template <typename Resource, typename Identifier>
const Resource& Resource_holder<Resource, Identifier>::get(Identifier id) const {
    auto found = resource_map.find(id);
    assert(found != resource_map.end());

    return *found->second;
}
