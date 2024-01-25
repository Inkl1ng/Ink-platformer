#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player : public sf::Drawable
{
public:
    Player();

    void setTexture(sf::Texture& texture);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void processInput(sf::Time delta_time);
    void update(sf::RenderWindow& window);

private:

private:
    sf::Sprite   m_sprite;
    sf::Vector2f m_velocity;
    bool         m_is_accelerating;
};
