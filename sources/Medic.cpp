
#include "Medic.hpp"
using namespace pandemic;

Medic ::Medic(Board &brd, City ct) :Player(brd,ct) {
    string role="Medic";
}

Player& Medic::drive(City city) {
    Player::drive(city);
    boolfunc();
    return *this;
}

Player& Medic::fly_direct(City city) {
    Player::fly_direct(city);
    boolfunc();
    return *this;
}
Player& Medic::fly_charter(City city) {
    Player::fly_charter(city);
    boolfunc();
    return *this;
}

Player& Medic::fly_shuttle(City city) {
    Player::fly_shuttle(city);
    boolfunc();
    return *this;
}

    Player& Medic::treat(City ct){ 
    if(brd[curr] <= 0){
        throw std::invalid_argument("cubes in this city is 0");
    }
    brd[curr] = 0;
    return *this;
}

void Medic::boolfunc() {
    string s=brd.enumTostringCity[curr];
    string s1=brd.cityColor[s];
    Color c=pandemic::Board::getColorwithStr(s1);
    if(brd.hasCures.contains(c)){
        brd[curr]=0;
    }
}

string pandemic::Medic::role() {
    return "Medic";
}