#include "Virologist.hpp"

using namespace std;
namespace pandemic
{
    Virologist::Virologist(Board b, City c) : Player(b, c) {}
    string Virologist::role() { return "Virologist"; }
    Virologist &Virologist::treat(City c) { return *this; }
};