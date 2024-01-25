#pragma once

#include <SFML/System.hpp>

namespace Constants
{
// Sets the game logic to run at 60 fps
inline const sf::Time frame_time {sf::seconds(1.f / 60.f)};

// TODO: find good values for these
inline constexpr float player_accel {50.f};
inline constexpr float player_friction {0.925f};
inline constexpr float max_player_vel {500.f};

// NOTE: The textures for the tiles are actually 32x32 but they will be scaled up to 64x64
inline constexpr float tile_size {64.f};
}
