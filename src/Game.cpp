#include "Game.hpp"

#include "Constants.hpp"

Game::Game()
    : window { sf::VideoMode(1280, 960), "Ink-Platformer", sf::Style::Close | sf::Style::Titlebar }
    , texture_holder {}
    , entity {} {
    load_resources();
}

void Game::run() {
    sf::Clock clock {};
    sf::Time delta_time { sf::Time::Zero };

    while (window.isOpen()) {
        process_events();
        delta_time += clock.restart();

        while (delta_time > Consts::frame_time) {
            delta_time -= Consts::frame_time;
            process_events();
            process_input();
            update(Consts::frame_time);
        }

        render();
    }
}

void Game::load_resources() {
    // texture_holder.load(Texture_id::player, "media/textures/player.png");
    texture_holder.load(Texture_id::tile, "media/textures/tile.png");

    entity.set_texture(texture_holder.get(Texture_id::tile));
}

void Game::process_events() {
    sf::Event event {};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // close the window on pressing Esc if in a debug build
        #ifndef NDEBUG
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        #endif
    }
}

void Game::process_input() {
}

void Game::update(sf::Time dt) {
    entity.update(dt);
}

void Game::render() {
    window.clear();
    window.draw(entity);
    window.display();
}
