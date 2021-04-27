#include "Medic.hpp"

using namespace std;
namespace pandemic
{
    Medic::Medic(Board b, City c) : Player(b, c) {}
    string Medic::role() { return "Medic"; }
    Medic &Medic::treat(City c) { return *this; }
};