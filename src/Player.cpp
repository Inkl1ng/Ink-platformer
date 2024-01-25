#include "Player.hpp"

#include "Constants.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

Player::Player()
    : m_sprite {}
    , m_velocity {}
{
}

void Player::setTexture(sf::Texture& texture)
{
    m_sprite.setTexture(texture);
    // doing this becuase the art work is going to be 32x32 but if I set the game resolution at
    // 640x480 the screen is really small so I set it at double that but I want the sprites to scale
    // up as well
    m_sprite.scale(2.f, 2.f);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

void Player::processInput(sf::Time delta_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_velocity.x      -= Constants::player_accel;
        m_is_accelerating  = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_velocity.x      += Constants::player_accel;
        m_is_accelerating  = true;
    }

    if (!m_is_accelerating)
    {
        m_velocity.x *= Constants::player_friction;
    }
    m_is_accelerating = false;

    m_sprite.move(m_velocity * delta_time.asSeconds());
}

void Player::update(sf::RenderWindow& window)
{
}
