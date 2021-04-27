#include "Researcher.hpp"

using namespace std;
namespace pandemic
{
    Researcher::Researcher(Board b, City c) : Player(b, c) {}
    string Researcher::role() { return "Researcher"; }
    Researcher &Researcher::discover_cure(Color c) { return *this; }
};