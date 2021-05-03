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
        Medic &drive(City);
        Medic &fly_direct(City);
        Medic &fly_charter(City);
        Medic &fly_shuttle(City);
        Medic &treat(City);
    };
}