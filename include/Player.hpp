#pragma once

#include <SFML/Graphics.hpp>

#include "engine/Entity.hpp"

class Player : public Entity {
public:
    Player();
    ~Player();
    void    update(sf::Time dt);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
private:
};