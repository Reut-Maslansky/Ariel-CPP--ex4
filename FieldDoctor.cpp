#include "FieldDoctor.hpp"

using namespace std;
namespace pandemic
{
    FieldDoctor::FieldDoctor(Board b, City c) : Player(b, c) {}
    string FieldDoctor::role() { return "FieldDoctor"; }
    FieldDoctor &FieldDoctor::treat(City c) { return *this; }
};