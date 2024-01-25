#pragma once

#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{
public:
    Tile(int column_y_pos);

    void setTexture(sf::Texture& texture);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

private:
    sf::Sprite m_sprite;
};
