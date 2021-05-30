
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
namespace pandemic{
class Scientist : public Player 
{
    public:
    int n;
    Scientist(Board &brd ,City ct,int n);
        Player& discover_cure(Color) override;
        string role() override;
    
};
}
