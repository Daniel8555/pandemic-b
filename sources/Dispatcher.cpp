#include"Dispatcher.hpp"

using namespace pandemic;
Dispatcher ::Dispatcher(Board &brd, City ct) :Player(brd,ct) {
    string role="Dispatcher";
}

Player& Dispatcher::fly_direct(City ct)
{
    if(ct==curr)
    {
         throw std::invalid_argument("city:"+brd.enumTostringCity[ct]+"is not equal to"+brd.enumTostringCity[curr]);}
    if(brd.station.contains(curr))
    {
            curr=ct;
    return *this;
    }
    if(!brd.station.contains(curr)&&Cards.contains(ct))
    {
    Cards.erase(ct);
    curr=ct;
    return *this;
    }
    throw std::invalid_argument("isnt legal fly_direct");


}
string Dispatcher::role() {
    return "Dispatcher";
}
