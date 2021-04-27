#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board, City);
        std::string role();
        Dispatcher &fly_direct(City);
    };
}