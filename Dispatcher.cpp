#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board b, City c) : Player(b, c) {}

    string Dispatcher::role() { return "Dispatcher"; }

    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (myBoard.researchStation.at(c) == true)
        {
            myLocation = c;
        }
        else
        {
            Player::fly_direct(c);
        }
        return *this;
    }
};