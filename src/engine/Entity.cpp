#include "engine/Entity.hpp"

#include "Constants.hpp"

Entity::Entity()
    : velocity { 0.f, 0.f } 
    , verticies { sf::TriangleStrip, 4 }
    , texture {} {
    verticies[0].position = sf::Vector2f(0.f, 0.f);
    verticies[1].position = sf::Vector2f(0.f, Consts::cell_size);
    verticies[2].position = sf::Vector2f(Consts::cell_size, 0.f);
    verticies[3].position = sf::Vector2f(Consts::cell_size, Consts::cell_size);

    verticies[0].texCoords = sf::Vector2f(0.f, 0.f);
    verticies[1].texCoords = sf::Vector2f(0.f, Consts::texture_size);
    verticies[2].texCoords = sf::Vector2f(Consts::texture_size, 0.f);
    verticies[3].texCoords = sf::Vector2f(Consts::texture_size, Consts::texture_size);
}

Entity::~Entity() {
    
}

void Entity::update(sf::Time dt) {
    move(velocity * dt.asSeconds());
}

void Entity::set_texture(sf::Texture& texture) {
    this->texture = &texture;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = texture;

    target.draw(verticies, states);
}