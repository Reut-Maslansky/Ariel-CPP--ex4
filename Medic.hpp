#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board, City);
        std::string role();
        Medic &treat(City);
    };
}