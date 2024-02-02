#pragma once

#include <SFML/Graphics.hpp>

#include "system/ResourceHolder.hpp"

class Entity : public sf::Drawable, public sf::Transformable {
public:
                    Entity();
    virtual         ~Entity();
    void            set_texture(sf::Texture& texture);
    virtual void    update(sf::Time dt);

protected:
    sf::Vector2f        velocity;
    sf::VertexArray     verticies;
    sf::Texture*        texture;

private:
    virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
};