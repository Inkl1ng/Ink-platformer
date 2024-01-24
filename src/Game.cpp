#include "Game.hpp"

#include "Constants.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Game::Game()
    : m_window {sf::VideoMode(1280, 960), "Ink-Platformer", sf::Style::Close | sf::Style::Titlebar}
    , m_player {sf::Vector2f(150.f, 150.f)}
{
    m_player.setFillColor(sf::Color::Cyan);
    m_player.setPosition(sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2));
}

void Game::run()
{
    sf::Clock clock;
    sf::Time  delta_time = sf::Time::Zero;

    while (m_window.isOpen())
    {
        delta_time += clock.restart();
        while (delta_time >= Constants::frame_time)
        {
            delta_time -= Constants::frame_time;
            processEvents();
            processInput(Constants::frame_time);
            update();
        }

        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void Game::processInput(sf::Time delta_time)
{
    sf::Vector2f movement;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        movement.x += Constants::player_move_speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movement.x -= Constants::player_move_speed;
    }
    m_player.move(movement * delta_time.asSeconds());
}

void Game::update()
{
}

void Game::render()
{
    m_window.clear();

    m_window.draw(m_player);

    m_window.display();
}
