
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic{
class Dispatcher : public Player 
{
    public:
    Dispatcher(Board &brd ,City ct);
          Player& fly_direct(City) override;
             string role() override; 
    
};
}
