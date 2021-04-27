#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
    public:
        Researcher(Board, City);
        std::string role();
        Researcher &discover_cure(Color);
    };
}