#pragma once

#include "Board.hpp"
using namespace std;
namespace pandemic{
class Player
{
    protected:
    Board &brd;
   set<City> Cards;
   string rol;
   City curr;
public:
 Player(Board &brd,City ct):brd(brd),curr(ct){}
Player& remove_cards();
virtual Player& discover_cure(Color clr);
virtual Player& drive(City ct);
virtual Player& fly_direct(City ct);
virtual Player& fly_charter(City ct);
virtual Player& fly_shuttle(City ct);
virtual Player& build();
virtual Player& treat(City ct);
virtual string role();
virtual Player& take_card(City ct);
};
}
