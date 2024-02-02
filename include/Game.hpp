#pragma once

#include <SFML/Graphics.hpp>
#include "system/ResourceHolder.hpp"
#include "engine/Entity.hpp"

class Game {
public:
            Game();

    void    run();

private:
    void    load_resources();
    void    process_events();
    void    process_input();
    void    update(sf::Time dt);
    void    render();

private:
    sf::RenderWindow    window;
    Texture_holder      texture_holder;
    Entity              entity;
};