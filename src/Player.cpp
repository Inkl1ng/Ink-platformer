#include "Player.hpp"

#include "Constants.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

Player::Player()
    : m_shape    {sf::Vector2f {100.f, 100.f}}
    , m_velocity {}
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
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

    m_shape.move(m_velocity * delta_time.asSeconds());
}

void Player::update(sf::RenderWindow& window)
{
}
