#include "OperationsExpert.hpp"

using namespace std;
namespace pandemic
{
    OperationsExpert::OperationsExpert(Board b, City c) : Player(b, c) {}
    string OperationsExpert::role() { return "OperationsExpert"; }
    OperationsExpert &OperationsExpert::build()
    {
        myBoard.researchStation.at(myLocation) = true;
        return *this;
    }
};