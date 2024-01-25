#pragma once

#include "Player.hpp"
#include "system/ResourceHolder.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game
{
public:
    Game();

    void run();

private:
    void loadResources();
    void processEvents();
    void processInput(sf::Time delta_time);
    void update();
    void render();

private:
    sf::RenderWindow m_window;
    sf::View         m_view;
    Player           m_player;
    TextureHolder    m_texture_holder;
};
