#include "GeneSplicer.hpp"

using namespace std;
namespace pandemic
{
    GeneSplicer::GeneSplicer(Board b, City c) : Player(b, c) {}
    string GeneSplicer::role() { return "GeneSplicer"; }
    GeneSplicer &GeneSplicer::discover_cure(Color c)
    {
        if (myBoard.discoverCure.at(c) == false)
        {
            if (myBoard.researchStation.at(myLocation) == false)
            {
                throw invalid_argument("Can't discover: This city does not have a research station");
            }
            if (myCards.size() < 5)
            {
                throw invalid_argument("Can't discover: There are not enough cards");
            }

            myBoard.discoverCure.at(c) = true;
            int count = 5;

            for (auto it = myCards.begin(); it != myCards.end() && count > 0; ++it)
            {
                myCards.erase(it++);
                myColors.at(myBoard.colors.at(*it))--;
                count--;
            }
        }
        return *this;
    }
};