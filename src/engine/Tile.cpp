#include "engine/Tile.hpp"

#include "Constants.hpp"

Tile::Tile(int column_y_pos)
    : m_sprite {}
{
    // move the sprite down to the appropriate y-position
    m_sprite.move({0, column_y_pos * Constants::tile_size});
}

void Tile::setTexture(sf::Texture& texture)
{
    m_sprite.setTexture(texture);
    m_sprite.scale(2.f, 2.f);
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}
