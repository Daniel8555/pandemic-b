
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
 namespace pandemic{
class FieldDoctor : public Player 
{   
    public:
    FieldDoctor(Board &brd ,City ct):Player(brd,ct){}
    
    Player& treat(City) override;
    string role() override;
    
};
}

