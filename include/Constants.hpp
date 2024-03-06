#pragma once

#include <SFML/Graphics.hpp>

namespace Consts {
    /// Sets game to update at 60 ticks a second
    inline const sf::Time frame_time { sf::seconds(1.f / 60.f) };

    inline constexpr float cell_size { 64.f };
    inline constexpr float texture_size { 32.f };
}