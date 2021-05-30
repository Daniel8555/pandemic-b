#include"Board.hpp"
#include"Player.hpp"
#include"OperationsExpert.hpp"
#include"City.hpp"
#include"Scientist.hpp"
#include"Dispatcher.hpp"
#include"Researcher.hpp"
#include "FieldDoctor.hpp"
#include"Medic.hpp"
#include "GeneSplicer.hpp"
#include "Virologist.hpp"
using namespace pandemic;
int main()
{
    Board brd;
//OperationsExpert
//build without card    
    OperationsExpert op{brd,City::Algiers};
    op.build();


//scientist
    Scientist scientist{brd,City::Algiers,4};
       scientist.take_card(City::Algiers); 
       brd[City::Algiers] = 1;
                    scientist.build();
    scientist.take_card(City::Algiers)
                .take_card(City::Baghdad)
                .take_card(City::Cairo)
                .take_card(City::Chennai);
                scientist.discover_cure(Color::Black); 

//dispatcher

    Dispatcher dispatcher(brd, City::Algiers);
    dispatcher.fly_direct(City::Atlanta); 
//Researcher 
//no have station
   Researcher researcher(brd, City::StPetersburg);
   researcher.take_card(City::Atlanta)
                  .take_card(City::Chicago)
                  .take_card(City::Essen)
                  .take_card(City::London)
                  .take_card(City::Madrid);
                  researcher.discover_cure(Color::Blue);
 //FieldDoctor
 //neigh    

   FieldDoctor fieldDoctor(brd, City::Algiers); 
   brd[City::Paris]=1;
   fieldDoctor.treat(City::Paris);  

//GeneSplicer
//diffrent color
    GeneSplicer geneSplicer(brd, City::Algiers);
       geneSplicer.take_card(City::Milan) 
                   .take_card(City::Bangkok) 
                   .take_card(City::Beijing)
                   .take_card(City::Bogota)
                   .take_card(City::Delhi); 
    geneSplicer.discover_cure(Color::Black);

//medic
    Medic medic(brd, City::StPetersburg);
    brd[City::StPetersburg]=1;
    medic.treat(City::StPetersburg);

//virologist
   Virologist virologist(brd, City::Algiers);
    virologist.take_card(City::Washington);
     brd[City::Washington]=1;
    virologist.treat(City::Washington);
    cout<<brd<<endl;

}