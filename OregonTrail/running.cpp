#include <iostream>
#include <cstdlib>

#include "Oregon_Trail_H_Files.h"


/* NOTES: 
   having 1 spare wheels means that the count is at 5, since 4 are required to pull caravan
   exception hit when forcing across a river
*/
void setUpCaravan (Caravan&);
void printCaravanInfo (Caravan&);
void changePace(string&);
void changeRation(string&);

int main() 
{
    // seed random # generator
    srand(0);

    // ****** caravan object ****** //
    Caravan car; 
    car.wearDown.tongue = 100; // force fix, see H-file

    // set up stuff for trail blazing -> zigzagging = more distance
    const int PITSTOPS_SIZE = 11;
    location pitStops[PITSTOPS_SIZE] = {
                             {'t', "Kansas City, KS", 2000},
                             {'r', "Kansas River Crossing, KS", 1900},
                             {'r', "Platte River, NE", 1700},
                             {'l', "Chimney Rock, NE", 1650},
                             {'t', "Cheyenne, WY", 1500},
                             {'l', "Independence Rock, WY", 1300},
                             {'r', "Green River Crossing, WY", 1100},
                             {'t', "Salt Lake City, UT", 900},
                             {'l', "Shoshone Falls, ID", 600},
                             {'r', "Grande Ronde, OR", 350},                           
                             {'t', "Portland, OR (destination)",0}
                             };
    
    int stop = 0;                                       // pitStop index
    car.setDistance(pitStops[stop] - pitStops[stop + 1]); // distance to 1st destination
    int loopCount = 0;                                  // for prompting new pacing and rationing

    // set up caravan (people + supplies), pacing, rationing, $$$ done in constructor
        // people in caravan
        string name = ""; int numPeople = 0;
        std::cout << "Who will travel the trail? (max of 4) (0 for done)\n";
        while (numPeople < 4)
        {
            std::cout << "Enter names: ";
            std::getline(std::cin, name);
            if (name == "0")
			{
				if (numPeople == 0) std::cout << "You need at least 1 person to travel the trail.\n";
				else break;
			}
			else
			{
                car.setPerson((string)name);   
                numPeople++;
			}
        }
        //setUpCaravan(car);
    
        // supplies
        visitPitStop(pitStops[stop].name, car);
        
    // ***** Begin Game ***** //
    bool diedAlongTrail = false;
    std::cout << "\nStarting the trail!!\n\n";
    while (true) 
    {
        // check distance
        if (car.getDistance() == 0)
        {
            stop++; // next stop
            if (pitStops[stop].type == 't')
                visitPitStop(pitStops[stop].name, car);              // visit pit-stop
            else if (pitStops[stop].type == 'r')
                visitRiver(pitStops[stop].name, car);
            else // == 'l'
                visitLandmark(pitStops[stop].name, car);
            if (stop == PITSTOPS_SIZE - 1) break; // when at 10th stop -> reached end (stop + 1 DNE)
            car.setDistance(pitStops[stop] - pitStops[stop + 1]); // set distance for next destination
        }
        
        // print information, runCaravan
        car.runCaravan();
        printCaravanInfo(car);
        
        People p; car.first(p);
        int dead = 0; // track the dead
        do
        {
            std::cout << "  " << p.getName() << " is in " << p.getHealth() << " health."
                      << " Sickness: " <<  p.getSickness() << "\n";
            if (p.getSickness() == Ill::illness[6]) dead++;
        } while (car.next(p));
        std::cout << std::endl;
        if (dead == numPeople) {diedAlongTrail = true; break; } // everyone dead
        
        // get new pacing and rationing (uses loopCount)
        string answer = "";
        if (loopCount % 2 == 0)
        {       
            // rationing
            changeRation(answer);
            car.setRationing(answer);

            // pacing
            changePace(answer);
            car.setPacing(answer);

            // rest
            while (answer == Caravan_Pacing::pace[4])
            {
                int days = 0;
                std::cout << "How many days do you want to rest? ";
                std::cin >> days;
                car.restCaravan(days);
                printCaravanInfo(car);
               
                // get new pace
                changePace(answer);
                car.setPacing(answer);
            } // while

            std::cout << std::endl;
        } // if

        loopCount++;    
    } // while
    
    // end message (finish game)
    if (!diedAlongTrail)
    {
        std::cout << "\nCongratulations, you have survived the troubles of the trail.\n"
                  << "You trekked from Washington D.C. all the way to San Francisco in a mere "
                  << car.getDays() << " days.\n"
                  << "Be proud that these members of your caravan lived:\n";
        People person; car.first(person);
        do
        {
            if (person.getSickness() != Ill::illness[6])
            {
                std::cout << "     " << person.getName() << std::endl;
            }
        } while (car.next(person));
        std::cout << " At least here there are no bears to eat you while asleep.\n"
                  << " Play again.\nFarewell.\n";
    }
    else
    {
        std::cout << "\nWhether by bad luck or your own foolishness, everyone's dead.\n"
                  << "The trail proved too much for you and those unfortunate enough to follow you.\n"
                  << "May you find peace half buried on the trail, stepped upon by future travelers.\n"
                  << "Farewell, please try again when you're reincarnated.\n";
    }
    
    system("Pause");
} // main

void setUpCaravan (Caravan& car)
{
        // put people in caravan
        car.setPerson(People("Jacob McNab"));
        car.setPerson(People("Mary Ann"));
        car.setPerson(People("Willy Johanson"));

        // put supplies in caravan, get oxen
        car.addSupply("rifles", 2);
        car.addSupply("bullets", 30);
        car.addSupply("clothes", 10);
        car.addSupply("food", 1800);
        car.setOxen(4);

        // pacing and rationing
        car.setPacing("steady");
        car.setRationing("full");
} // set up caravan

void printCaravanInfo (Caravan& car)
{
    std::cout << "  food = " << car.getCaravanSupplies("food").amount << std::endl
              << "  distance = " << car.getDistance() << std::endl;
}

void changePace(string& r)
{
    std::cout << "\nnew pace? ("
              << Caravan_Pacing::pace[0] << ", "
              << Caravan_Pacing::pace[1] << ", "
              << Caravan_Pacing::pace[2] << ", "
              << Caravan_Pacing::pace[3] << ", "
              << Caravan_Pacing::pace[4] << "): ";
    std::cin >> r;
}

void changeRation(string& r)
{
    std::cout << "new rationing? ("
              << Caravan_Rationing::ration[0] << ", "
              << Caravan_Rationing::ration[1] << ", "
              << Caravan_Rationing::ration[2] << ", "
              << Caravan_Rationing::ration[3] << "): ";
    std::cin >> r;
}
