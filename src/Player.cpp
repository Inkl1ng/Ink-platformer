#include "Player.hpp"

Player::Player()
    : Entity() {

}

Player::~Player() {

}

void Player::update(sf::Time dt) {
    
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = texture;

    target.draw(verticies, states);
}