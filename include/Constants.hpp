#pragma once

#include <SFML/System.hpp>

namespace Constants
{
// Sets the game logic to run at 60 fps
inline const sf::Time frame_time = sf::seconds(1.f / 60.f);

inline constexpr float player_move_speed = 100.f;
}
