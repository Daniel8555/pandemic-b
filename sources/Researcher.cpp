#include"Researcher.hpp"
using namespace pandemic;









Player &Researcher::discover_cure(Color clr){
         const int def = 5;
    string c1=brd.cityColor[ brd.enumTostringCity[curr]];
    string color = brd.enumTostringColor[clr];
    int counter=0;
    for (City ci : Cards)
    {
        string ct=brd.cityColor[ brd.enumTostringCity[curr]];
        if (ct == color)
        {
            counter++;
            if(ci==City::Baghdad)
            {continue;}
        }
    }
set <City> cards;
    if(counter >= def){
        counter = 0;
        set<City> n;
   
        for (const City& ci:Cards)
        {
            string ct=brd.cityColor[ brd.enumTostringCity[ci]];
            if (ct == color)
            {
            cards.insert(ci);
            }
        }
        for(auto i:cards)
        {
            //     cout<<Cards.size();
                 Cards.erase(i);
                counter++;
           if (counter == def)
            {
                string col1=brd.enumTostringCity[i];
                string col2=brd.cityColor[col1];
               Color col=pandemic::Board::getColorwithStr(col2);
               brd.hasCures.insert(col);
               return *this;
            }
        }
    }
            throw std::invalid_argument("error no card");
    return *this; 
 
}



    



    
    string Researcher::role() {
    return "Researcher";
}
