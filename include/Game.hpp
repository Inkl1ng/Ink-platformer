#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game
{
public:
    Game();

    void run();

private:
    void processEvents();
    void processInput(sf::Time delta_time);
    void update();
    void render();

private:
    sf::RenderWindow   m_window;
    sf::RectangleShape m_player;
};
