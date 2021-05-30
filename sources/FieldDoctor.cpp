#include"FieldDoctor.hpp"
using namespace pandemic;

      Player& FieldDoctor::treat(City ct) 
      {

          bool t=brd.connection[brd.enumTostringCity[curr]].contains(brd.enumTostringCity[ct]);
          if(!t&&ct!=curr){
               throw std::invalid_argument("error no connection between "+brd.enumTostringCity[curr] + "and :" +brd.enumTostringCity[ct]); }
                string city=brd.enumTostringCity[ct];
        if(brd.levelofhealt[city]==0)
    {
         throw std::invalid_argument("error level of health is 0");
    }
  
    Cards.erase(ct);
    bool cure=false;
    
    string s=brd.enumTostringCity[ct];
    string s1=brd.enumTostringCity[curr];
    string ColorFunc=brd.cityColor[s];
    string ColorOfCurrentCity=brd.cityColor[s1];

Color c;
    string curesCol;
    bool flag=false;
    for(auto it: brd.hasCures)
    {
        Color c=pandemic::Board::getColorwithStr(ColorOfCurrentCity);
        string curesCol=brd.enumTostringColor[it];
        if(it==c)
    {
        flag=true;
    }
    }
    if(flag){
        brd.levelofhealt[city]=0;}
    else
    {
        brd.levelofhealt[city]-=1;
    }


    return *this;
    }      
      
    string FieldDoctor ::role()
    {
            return "FieldDoctor";
    } 
