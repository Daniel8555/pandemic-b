#include"OperationsExpert.hpp"
using namespace pandemic;
OperationsExpert ::OperationsExpert(Board &brd, City ct) :Player(brd,ct) {
    string role="OperationsExpert";
}
Player& OperationsExpert::build() {
    brd.station.insert(curr);
    return *this;
}

string OperationsExpert::role() {
    return "OperationsExpert";
}
