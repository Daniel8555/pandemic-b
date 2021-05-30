
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic{
class GeneSplicer : public Player 
{
    public:
    GeneSplicer(Board &brd ,City ct);
        Player& discover_cure(Color) override;
        string role() override;
    
};
}

