
#pragma once
#include "City.hpp"
#include"Color.hpp"
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include "string"
#include "vector"
using namespace std;
namespace pandemic{

class Board
{
    public:
    Board();
 
     //virtual ~Board()= default;
    
    set<Color> hasCures ;
    set<City> station;
    map<std::string, int> levelofhealt;
    map<City,std::string> enumTostringCity;
   map<string,set<std::string>> connection ;
    map<std::string,std::string> cityColor;
    map<Color,std::string> enumTostringColor;
    bool connect(City from,City to);
    void setStation(City c);
    Color getColor(City c);
      static Color getColorwithStr(string const &c);
    bool  curesBool(Color c) const;
    void setCure(Color c);
//Board& operator=(int x);
int& operator[](City ct );
friend ostream &operator<<(ostream &os, Board &brd);
bool is_clean() ;
void remove_cures();
void remove_stations();

};
}  