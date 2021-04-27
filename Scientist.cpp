#include "Scientist.hpp"

using namespace std;
namespace pandemic
{
    Scientist::Scientist(Board b, City c, int n) : Player(b, c), N(n) {}
    string Scientist::role() { return "Scientist"; }
    Scientist &Scientist::discover_cure(Color c) { return *this; }
};