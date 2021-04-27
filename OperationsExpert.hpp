#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert(Board, City);
        std::string role();
        OperationsExpert &build();
    };
}