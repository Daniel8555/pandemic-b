

#include"Player.hpp"
#include"Board.hpp"
using namespace pandemic;

using namespace std;
Player& Player:: remove_cards()
{
    Cards.clear();
    return *this;
}
Player& Player:: drive(City ct)
{
    string str=brd.enumTostringCity[ct];
    string str1=brd.enumTostringCity[curr];

    if(ct==curr){
  
            throw std::invalid_argument ("error drive " +brd.enumTostringCity[ct]+" equal to: "+ brd.enumTostringCity[curr] );}
    if(!brd.connection.at(str).contains(str1))
    {
            throw std::invalid_argument("error no connection between "+str + "and :" +str1);
    }
    curr=ct;
    return *this;

}
Player& Player:: fly_direct(City ct)
   {

      if(ct==curr){
("error fly direct " +brd.enumTostringCity[ct]+" equal to: "+ brd.enumTostringCity[curr] );}

    if(!Cards.contains(ct)){
           throw std::invalid_argument("you dont have a card to fly :" + brd.enumTostringCity[ct]  );}
    // //cout<<Cards.size()<<endl;
         Cards.erase(ct);
        curr=ct;

     return *this;

   }

     Player& Player::fly_charter(City ct) {
        if(curr==ct)
        {
            throw std::invalid_argument ("error drive " +brd.enumTostringCity[ct]+" equal to: "+ brd.enumTostringCity[curr] );}
        
        if(!Cards.contains(curr))  {
            cout<<brd.enumTostringCity[curr];
               throw std::invalid_argument("you dont have a card to fly :" + brd.enumTostringCity[ct]  );}

  
      Cards.erase((curr));
      curr=ct;
               return *this;
}

Player& Player::fly_shuttle(City ct)
{

 if(ct==curr)
     {     
     throw std::invalid_argument("error fly shuttle " +brd.enumTostringCity[ct]+" equal to: "+ brd.enumTostringCity[curr] );
     }

 if(brd.station.contains(ct)&&brd.station.contains(curr))
  {
    curr=ct;
    return *this;
  } 
         throw std::invalid_argument("error fly shuttle city_curr");

}
Player& Player::build()
{
      if(brd.station.contains(curr)){
           return *this;
    }
    if(!Cards.contains(curr)){
           throw std::invalid_argument("you dont have a card to build :" + brd.enumTostringCity[curr]  );
    }

        brd.station.insert(curr);
     Cards.erase(curr);

    
    return *this;

}
Player& Player:: discover_cure(Color clr){
      const int def = 5;
    string c1=brd.cityColor[ brd.enumTostringCity[curr]];
    string color = brd.enumTostringColor[clr];
    if(!brd.station.contains(curr)){
    throw std::invalid_argument("error no station in " + brd.enumTostringCity[curr]);
    }
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


Player& Player::treat(City ct)
{

    if(ct!=curr)
{
         throw std::invalid_argument("city:"+brd.enumTostringCity[ct]+"is not equal to"+brd.enumTostringCity[curr]);
}
        string city=brd.enumTostringCity[ct];
    if(brd.levelofhealt[city]==0)
    {
                 throw std::invalid_argument("error level of healt in"+brd.enumTostringCity[ct] +"is 0");
    }
  

    // Cards.erase(ct);
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
string Player:: role()
{ return "";}
Player& Player::take_card(City ct)
{
if(!Cards.contains(ct)){
    Cards.insert(ct);}
     return *this;
     }
