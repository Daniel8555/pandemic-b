#include"Virologist.hpp"
using namespace pandemic;
Virologist ::Virologist(Board &brd, City ct) :Player(brd,ct) {
    string role="Virologist";
}
Player& Virologist::treat(City ct) {//check if have a problem with current

    
    if(!Cards.contains(ct)&&ct!=curr){
              throw std::invalid_argument("city:"+brd.enumTostringCity[ct]+"is not equal to"+brd.enumTostringCity[curr]);}


      string city=brd.enumTostringCity[ct];
    if(brd.levelofhealt[city]==0)
    {
         throw std::invalid_argument("error level of healt in"+brd.enumTostringCity[ct] +"is 0");
    }
    bool cure=false;
    Color c=brd.getColor(ct);
   if(brd.curesBool(c))
    {
        brd.levelofhealt[city]=0;
    }
    if((brd.levelofhealt[city]>0))
    {
        brd.levelofhealt[city]--;}
    

    Cards.erase(curr);
    return *this;
    }



string Virologist::role() {
    return "Virologist";
}
