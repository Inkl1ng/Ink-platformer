#include "Game.hpp"

#include "Constants.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Game::Game()
    : m_window {sf::VideoMode(1280, 960), "Ink-Platformer", sf::Style::Close | sf::Style::Titlebar}
    , m_player {}
{
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
#ifndef NDEBUG
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            m_window.close();
        }
#endif
    }
}

void Game::processInput(sf::Time delta_time)
{
    m_player.processInput(delta_time);
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
