#include "engine/Tile.hpp"

#include "Constants.hpp"

Tile::Tile(sf::Vector2f cell_pos)
    : verticies { sf::TriangleStrip, 4 }
    , texture {} {
    verticies[0].position = cell_pos * Consts::cell_size;
    verticies[1].position = cell_pos * Consts::cell_size + sf::Vector2f(0.f, Consts::cell_size);
    verticies[2].position = cell_pos * Consts::cell_size + sf::Vector2f(Consts::cell_size, 0.f);
    verticies[3].position = cell_pos * Consts::cell_size
        + sf::Vector2f(Consts::cell_size, Consts::cell_size);
    
    verticies[0].texCoords = sf::Vector2f(0.f, 0.f);
    verticies[1].texCoords = sf::Vector2f(0.f, Consts::texture_size);
    verticies[2].texCoords = sf::Vector2f(Consts::texture_size, 0.f);
    verticies[3].texCoords = sf::Vector2f(Consts::texture_size, Consts::texture_size);
}

Tile::~Tile() {

}

void Tile::set_texture(sf::Texture& texture) { 
    this->texture = &texture;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.texture = this->texture;

    target.draw(verticies, states);
}