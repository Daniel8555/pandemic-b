
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic{
class Virologist : public Player 
{
    public:
    Virologist(Board &brd ,City ct);
      Player& treat(City) override;
    string role() override;
    
};
}
