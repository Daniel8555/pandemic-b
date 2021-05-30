#pragma once
#include "Player.hpp"
namespace pandemic{
class Researcher : public Player 
{
    public:
    Researcher(Board& brd ,City ct): Player (brd,ct){}
      Player  &discover_cure(Color)override ;
        string role()override ;



};
}

