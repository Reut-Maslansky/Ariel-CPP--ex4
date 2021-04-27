#include "Dispatcher.hpp"

using namespace std;
namespace pandemic
{
    Dispatcher::Dispatcher(Board b, City c) : Player(b, c) {}
    string Dispatcher::role() { return "Dispatcher"; }
    Dispatcher &Dispatcher::fly_direct(City c) { return *this; }
};