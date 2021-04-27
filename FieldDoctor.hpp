#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        FieldDoctor(Board, City);
        std::string role();
        FieldDoctor &treat(City);
    };
}