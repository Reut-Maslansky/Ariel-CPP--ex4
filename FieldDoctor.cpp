#include "FieldDoctor.hpp"

using namespace std;
namespace pandemic
{
    FieldDoctor::FieldDoctor(Board b, City c) : Player(b, c) {}
    string FieldDoctor::role() { return "FieldDoctor"; }
    FieldDoctor &FieldDoctor::treat(City c)
    {
        if (myLocation != c && myBoard.neighbors.at(myLocation).count(c) == 0)
        {
            throw invalid_argument("Can't treat: This city is not a neighbor of the current city");
        }
        if (myBoard[c] == 0)
        {
            throw invalid_argument("Can't treat: There is no pollution in this city");
        }
        if (myBoard.discoverCure.at(myBoard.colors.at(c)) == true)
        {
            myBoard[c] = 0;
        }
        else
        {
            myBoard[c]--;
        }
        return *this;
    }
};