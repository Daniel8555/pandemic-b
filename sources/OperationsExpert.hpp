
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic{
class OperationsExpert : public Player 
{
    public:
    OperationsExpert(Board &brd ,City ct);
    Player& build() override;
    string role() override;

};
}
