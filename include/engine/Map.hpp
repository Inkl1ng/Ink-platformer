#pragma once

#include "Tile.hpp"

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

// Each column is 15 tiles tall
typedef std::array<Tile, 15> TileColumn;

class Map : public sf::Drawable
{
public:
    Map();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:

private:
    std::vector<TileColumn> m_map;
};
