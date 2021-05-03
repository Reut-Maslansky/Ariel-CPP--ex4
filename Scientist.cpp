#include "Scientist.hpp"

using namespace std;
namespace pandemic
{
    Scientist::Scientist(Board b, City c, int n) : Player(b, c), N(n) {}
    string Scientist::role() { return "Scientist"; }
    Scientist &Scientist::discover_cure(Color c)
    {
        if (myBoard.discoverCure.at(c) == false)
        {
            if (myBoard.researchStation.at(myLocation) == false)
            {
                throw invalid_argument("Can't discover: This city does not have a research station");
            }
            if (myColors.at(c) < N)
            {
                throw invalid_argument("Can't discover: There are not enough cards of this color");
            }

            myColors.at(c) -= N;
            myBoard.discoverCure.at(c) = true;
            int count = N;

            for (auto it = myCards.begin(); it != myCards.end() && count > 0; ++it)
            {
                if (myBoard.colors.at(*it) == c)
                {
                    myCards.erase(it++);
                    count--;
                }
                else
                {
                    ++it;
                }
            }
        }
        return *this;
    }
};