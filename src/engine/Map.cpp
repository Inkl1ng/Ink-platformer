#include "engine/Map.hpp"

#include "engine/Tile.hpp"

Map::Map()
    : m_map {}
{
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const TileColumn& column : m_map)
    {
        for (const Tile& tile : column)
        {
        }
    }
}
