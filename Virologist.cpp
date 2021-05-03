#include "Virologist.hpp"

using namespace std;
namespace pandemic
{
    Virologist::Virologist(Board b, City c) : Player(b, c) {}
    string Virologist::role() { return "Virologist"; }
    Virologist &Virologist::treat(City c)
    {
        if (myCards.count(c) == 0)
        {
            throw invalid_argument("Can't build: The player does not hold a matching card");
        }
        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
        else
        {
            myBoard[c]--;
        }
        myCards.erase(c);
        myColors.at(myBoard.colors.at(c))--;
        return *this;
    }
};