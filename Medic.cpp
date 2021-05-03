#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    Medic::Medic(Board b, City c) : Player(b, c)
    {
        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
    }
    string Medic::role() { return "Medic"; }

    Medic &Medic::drive(City c)
    {
        if (myBoard.neighbors.at(myLocation).count(c) == 0)
        {
            throw invalid_argument("Can't drive: This city is not a neighbor of the current city");
        }
        myLocation = c;
        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_direct(City c)
    {
        if (myCards.count(c) == 0)
        {
            throw invalid_argument("Can't fly: The player does not hold a matching card");
        }
        myCards.erase(c);
        myColors.at(myBoard.colors.at(c))--;
        myLocation = c;
        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_charter(City c)
    {
        if (myCards.count(myLocation) == 0)
        {
            throw invalid_argument("Can't fly: The player does not hold a matching card");
        }
        myCards.erase(myLocation);
        myColors.at(myBoard.colors.at(myLocation))--;
        myLocation = c;

        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_shuttle(City c)
    {
        if (myBoard.researchStation.at(myLocation) == false || myBoard.researchStation.at(c) == false)
        {
            throw invalid_argument("Can't fly: This city does not have a research station");
        }

        myLocation = c;

        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
        return *this;
    }

    Medic &Medic::treat(City c)
    {
        myBoard[c] = 0;
        return *this;
    }
};