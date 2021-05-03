#include "Researcher.hpp"

using namespace std;

namespace pandemic
{
    Researcher::Researcher(Board b, City c) : Player(b, c) {}

    string Researcher::role() { return "Researcher"; }

    Researcher &Researcher::discover_cure(Color c)
    {
        if (myBoard.discoverCure.at(c) == false)
        {
            if (myColors.at(c) < 5)
            {
                throw invalid_argument("Can't discover: There are not enough cards of this color");
            }

            myColors.at(c) -= 5;
            myBoard.discoverCure.at(c) = true;
            int count = 5;

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