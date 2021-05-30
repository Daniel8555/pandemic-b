#include"GeneSplicer.hpp"
using namespace pandemic;
GeneSplicer ::GeneSplicer(Board &brd, City ct) :Player(brd,ct) {
     string role="GeneSplicer";
}
//////////////////////////have a probleemmm //////////////////
Player& GeneSplicer::discover_cure(Color clr)
{
 const int def = 5;
    string color = brd.enumTostringColor[clr];
    if(!brd.station.contains(curr)){
  throw std::invalid_argument("error no station in " + brd.enumTostringCity[curr]);
    }
    int counter=0;
    for (City ci : Cards){
            counter++;
            if(ci==City::Baghdad)
            {continue;}
    }
    set <City> cards;
    if(counter >= def){
        counter = 0;
        set<City> n;
   
        for (const City& ci:Cards)
        {
            string ct=brd.cityColor[ brd.enumTostringCity[ci]];
          cards.insert(ci);
        
        }
        for(auto i:cards)
        {
                 //cout<<Cards.size();
              Cards.erase(i);
              counter++;
           if (counter == def)
            {
               Color col=brd.getColor(i);
               brd.hasCures.insert(col);
               return *this;
            }
        }
    }
    throw std::invalid_argument("error no cards");
    
    return *this; 
}

     string GeneSplicer::role() 
     {
         return "GeneSplicer";
     }
