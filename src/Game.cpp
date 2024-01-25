#include "Game.hpp"

#include "Constants.hpp"
#include "system/ResourceIDs.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

Game::Game()
    : m_window {sf::VideoMode(1280, 960), "Ink-Platformer", sf::Style::Close | sf::Style::Titlebar}
    , m_view {{640.f, 480.f}, {1280.f, 960.f}}
    , m_player {}
    , m_texture_holder {}
{
    // m_view.zoom(0.5f);
    // m_window.setView(m_view);
    loadResources();
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

void Game::loadResources()
{
    m_texture_holder.load(TextureID::player, "player.png");

    m_player.setTexture(m_texture_holder.get(TextureID::player));
}

void Game::processEvents()
{
    sf::Event event {};
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
