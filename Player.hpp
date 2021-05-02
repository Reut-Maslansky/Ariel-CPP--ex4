#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic
{
    class Player
    {
    protected:
        Board &myBoard;
        City myLocation;
        std::set<City> myCards;

    public:
        Player(Board &, City);
        virtual Player &drive(City);
        virtual Player &fly_direct(City);
        virtual Player &fly_charter(City);
        virtual Player &fly_shuttle(City);
        virtual Player &build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);
        virtual std::string role();
        virtual Player &take_card(City);
    };
}