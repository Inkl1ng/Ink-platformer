#include "Game.hpp"

#include <iostream>

int main()
{
#ifndef NDEBUG
    std::cout << "*******************\n";
    std::cout << "*** DEBUG BUILD ***\n";
    std::cout << "*******************\n";
#endif

    Game game;
    game.run();

    return 0;
}
