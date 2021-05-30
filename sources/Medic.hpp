
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic{
class Medic : public Player 
{
    public:
    Medic(Board &brd ,City ct);
         Player& drive(City) override;
         Player& fly_direct(City) override;
         Player& fly_charter(City) override;
         Player& fly_shuttle(City) override;
         Player& treat(City) override;
         string role() override;
        void boolfunc();


};
}
