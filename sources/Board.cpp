
#include "Board.hpp"
#include "fstream"
#include "sstream"
using namespace std;


using namespace pandemic;
 namespace pandemic{
 ostream &operator<< (ostream &os,  Board &brd)
 
{
    const int number=48 ;
    cout<<"city and color and levelofhealth"<<endl;
   for (int i = 0; i < number; i++) 
   {
       string city=brd.enumTostringCity[(City)i];
      cout<< "City: "<<brd.enumTostringCity[(City)i]<<" |Color: "<<brd.cityColor[city]<<" |Level: "<<brd.levelofhealt[city]<<endl;
       
}
return os;
}
bool Board::is_clean()
{
    for(const auto &it:levelofhealt)
    {
        if(it.second>0)
        {

            return false;
        }

    }
    return true;
}
Board::Board()
{

enumTostringColor[Color::Black]="Black";
enumTostringColor[Color::Blue]="Blue";
enumTostringColor[Color::Red]="Red";
enumTostringColor[Color::Yellow]="Yellow";

    std::string tofile;
   int y=0;
    ifstream file("cities_map.txt");
    while(getline(file,tofile))
    {
        string county;
 
    int counter=0;
    size_t countword=0;
   size_t countlast=0;
    string word2 ;
    for (auto x : tofile) 
    {
        if (x == ' ')
        {  
            countword++;
            countlast=countword;
       
            if(counter==0)
            {
            county="";
             enumTostringCity[static_cast<City>(y)]=word2;
              county=word2;

                word2= "";
            }
        if(counter==1)
        {
         cityColor[county]=word2;
         word2= "";
         }
         if(counter>1)
         {
        connection[county].insert(word2);
          word2= "";
        }
            counter++;
        }

        else 
        {
            countword++;
            word2 += x;
        }
        
    }
        string end=tofile.substr(countlast,tofile.length());
        connection[county].insert(end);
        
        y++;
  
    }


}

int &Board::operator[](City c)
{
    string city =enumTostringCity[c];
    return levelofhealt[city];
}


void Board::remove_stations()
{
    station.clear();
}
void Board::remove_cures()
{
hasCures.clear();
}
    bool Board::connect(City from,City to)
    {
        return connection[enumTostringCity[from]].contains(enumTostringCity[to]); 

   }
    void Board:: setStation(City c)
    {
        station.insert(c);
    }
    Color Board::getColor(City c)
    {
        string cl1=enumTostringCity[c];
        string cl =cityColor[cl1];
        if(cl=="Red")
        {
            return Color::Red;
        }
          if(cl==("Yellow"))
        {
            return Color::Yellow;
        }
          if(cl=="Blue")
        {
            return Color::Blue;
        }
          if(cl=="Black")
        {
            return Color::Black;
        }
         throw std::invalid_argument("error color get color is not b or y or r or blue"); //--------------------------------------------------------- can be error

    }
     
    bool Board  ::curesBool(Color c) const
    {
        return hasCures.contains(c);
    }
    void Board:: setCure(Color c)
    {
        hasCures.insert(c);
    }
     Color Board::getColorwithStr(string const &c)
     {
       if(c=="Red")
        {
            return Color::Red;
        }
          if(c=="Yellow")
        {
            return Color::Yellow;
        }
          if(c=="Blue")
        {
            return Color::Blue;
        }
          if(c=="Black")
        {
            return Color::Black;
        }
         throw std::invalid_argument("error color get color is not b or y or r or blue"); //--------------------------------------------------------- can be error

    }
     
 }