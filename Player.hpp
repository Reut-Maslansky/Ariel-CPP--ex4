#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic
{
    class Player
    {
        Board myBoard;
        City myLocation;
        std::set<City> myCards;

    public:
        Player(Board &, City);
        Player &drive(City);
        Player &fly_direct(City);
        Player &fly_charter(City);
        Player &fly_shuttle(City);
        Player &build();
        Player &discover_cure(Color);
        Player &treat(City);
        std::string role();
        Player &take_card(City);
    };
}