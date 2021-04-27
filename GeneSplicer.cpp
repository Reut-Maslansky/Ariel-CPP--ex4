#include "GeneSplicer.hpp"

using namespace std;
namespace pandemic
{
    GeneSplicer::GeneSplicer(Board b, City c) : Player(b, c) {}
    string GeneSplicer::role() { return "GeneSplicer"; }
    GeneSplicer &GeneSplicer::discover_cure(Color c) { return *this; }
};