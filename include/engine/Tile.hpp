#pragma once

#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable {
public:
            Tile(sf::Vector2f cell_pos);
    virtual ~Tile();
    void    set_texture(sf::Texture& texture);

private:
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::VertexArray     verticies;
    sf::Texture*        texture;
};