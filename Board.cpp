#include "Board.hpp"
#include "City.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    Board::Board(){};
    bool Board::is_clean() {}

    ostream &operator<<(ostream &os, const Board &b)
    {
        return os;
    }
};