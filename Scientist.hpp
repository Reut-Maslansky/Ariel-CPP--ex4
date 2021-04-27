#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
        int N;

    public:
        Scientist(Board, City, int);
        std::string role();
        Scientist &discover_cure(Color);
    };
}