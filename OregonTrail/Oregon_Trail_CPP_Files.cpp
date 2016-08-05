/*
TODO: list item weights in shop - Line 1390
      --> DONE -> push into separate f(): ostream& fails, string fails

	  in VisitRiver - Line 1260
	    account for caravan weight for floating
		"                        " and oxen for fording
*/

////////// libraries shared among all classes //////////
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using std::string;

#include <cassert>
#include <cstdlib>

/////// class declarations + inlines ///////////////
#include "Oregon_Trail_H_Files.h"



///////////////////////////////// SICKNESS + CARAVAN PACING/RATIONING ///////////////////////
const string Ill::illness[7] = {"dysentary", "measels", "cholera",
                                "diphtheria", "typhoid", "none", "dead"};
const string Caravan_Rationing::ration[4] = {"bare", "meager", "ample", "full"};
const string Caravan_Pacing::pace[5] = {"slow", "steady", "fast", "blazing", "rest"};


//////////////////////////// ITEMINFO ////////////////////////////////
bool itemInfo::operator == (const itemInfo& info)
{
    if (info.amount == amount && info.weight == weight)
        return true;
    return false;
} // operator ==




//////////////////////////// FOOD //////////////////////////////////
// bild map, set member variables
/*
Food::Food() 
{
    // add meat
      // fish
      itemInfo info = {0, 1.1}; food["fish"] = info;

      // birds
      info.weight = 1.3; food["duck"] = info;
      info.weight = 1.3; food["chicken"] = info;
      info.weight = 0.1; food["egg"] = info;  // 1 egg

      // lighter animals
      info.weight = 1.5; food["pork"] = info;
      info.weight = 1.2; food["rabbit"] = info;
      info.weight = 1.8; food["venison"] = info; // deer
      info.weight = 1.8; food["mutton"] = info;  // sheep

      // heavier animals
      info.weight = 2.5; food["beef"] = info;
      info.weight = 3.0; food["buffalo"] = info;

    // add vegetables
    info.weight = 0.3; food["corn"] = info;
    info.weight = 0.4; food["lettuce"] = info;
    info.weight = 0.6; food["tomato"] = info;
    info.weight = 0.8; food["potato"] = info;
    
    // add fruits
    info.weight = 0.5; food["apple"] = info;
    info.weight = 0.5; food["orange"] = info;
    info.weight = 0.3; food["banana"] = info;
    info.weight = 0.1; food["grapes"] = info; // plural

    // add canned goods
    info.weight = 0.7; food["soup"] = info;
    info.weight = 0.4; food["coffee"] = info;
    info.weight = 0.8; food["beans"] = info;
    info.weight = 0.6; food["peaches"] = info;
    
    // add dry goods    
    info.weight = 0.3; food["pasta"] = info;
    info.weight = 0.3; food["cornmeal"] = info;
    info.weight = 0.4; food["crackers"] = info;
    info.weight = 0.2; food["oatmeal"] = info;

    // add liquids (1 cup unit)
    info.weight = 0.3; food["water"] = info;
    info.weight = 0.3; food["liquer"] = info;
    info.weight = 0.4; food["oil"] = info;
    info.weight = 0.2; food["grease"] = info;

    // set weight, iterator
    foodWeight = 0;
    it = food.begin();
} // constructor


// set amount for some food
void Food::setFood(string name, int amt) // amt >= 0, ensure such
{
    assert(amt >= 0); // ensure non-negative amount

    // get old food info
    itemInfo info = food[name];     // get info for specified food
    if (amt == info.amount) return; // no change

    // remove/add proper weight
    if (amt < info.amount) foodWeight -= (info.amount - amt) * info.weight; // less food
    else foodWeight += (amt - info.amount) * info.weight;                   // more food

    // store new amount
    info.amount = amt; 
    food[name] = info; 
} // setFood


// get first item in map (key + value)
void Food::first(string& name, itemInfo& info)
{
    assert(food.begin() != food.end()); // ensure map not empty

    it = food.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}


// get next item in map (key + value)
bool Food::next(string& name, itemInfo& info) 
{
    it++;
    if (it == food.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}


// get food info
itemInfo Food::getFood(string name) // can't be const b/c of map stuff
{
    return food[name];
}


// get total weight over all foods
double Food::getWeight() const 
{
    return foodWeight;
}


///////////////////////////////////// MEDICINE /////////////////////////////////////////
// bild map, set member variables
Medicine::Medicine() 
{
    // add surgicals
    itemInfo info = {0, .2}; medicine["bandage"] = info; // 1 bandage
    info.weight = 1.0; medicine["disinfectant"] = info;
    info.weight = 0.8; medicine["styptic"] = info;
    info.weight = 0.5; medicine["ointment"] = info;
    info.weight = 0.1; medicine["suture kit"] = info;

    // add internal meds
    info.weight = 1.2; medicine["antivenom"] = info;
    info.weight = 0.4; medicine["digestives"] = info;
    info.weight = 0.6; medicine["ibuprofin"] = info;
    info.weight = 0.3; medicine["penicilin"] = info;
    info.weight = 0.9; medicine["cough syrup"] = info;
    info.weight = 0.7; medicine["cough drops"] = info;
    info.weight = 0.4; medicine["antibiotic"] = info;

    // add miscenallenous
    info.weight = 0.2; medicine["cotton balls"] = info;
    info.weight = 1.1; medicine["rubbing alcohol"] = info;
    info.weight = 0.6; medicine["tylenol"] = info;
    info.weight = 2.0; medicine["steroids"] = info;
    info.weight = 2.1; medicine["viagra"] = info;

    // set weight, iterator
    medicineWeight = 0;
    it = medicine.begin();
} // constructor


// set amount for some medicine
void Medicine::setMedicine(string name, int amt) // amt >= 0, ensure such
{
    assert(amt >= 0); // ensure non-negative amount

    // get old food info
    itemInfo info = medicine[name]; // get info for specified medicine
    if (amt == info.amount) return; // no change

    // remove/add proper weight
    if (amt < info.amount) medicineWeight -= (info.amount - amt) * info.weight; // less medicine
    else medicineWeight += (amt - info.amount) * info.weight;                   // more medicine

    // store new amount
    info.amount = amt; 
    medicine[name] = info; 
} // setMedicine


// get first item in map (key + value)
void Medicine::first(string& name, itemInfo& info)
{
    assert(medicine.begin() != medicine.end()); // ensure map not empty

    it = medicine.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}


// get next item in map (key + value)
bool Medicine::next(string& name, itemInfo& info) 
{
    it++;
    if (it == medicine.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}


// get medicine info
itemInfo Medicine::getMedicine(string name) // can't be const b/c of map stuff
{
    return medicine[name];
}


// get total weight over all medicines
double Medicine::getWeight() const 
{
    return medicineWeight;
}


//////////////////////////////////// class HUNTINGGEAR ////////////////////////////////
HuntingGear::HuntingGear()
{
    // add weapons
    itemInfo info = {0, 14.0}; huntingGear["shotgun"] = info; 
    info.weight = 18.0; huntingGear["rifle"] = info;
    info.weight = 7.0; huntingGear["bow"] = info;
    info.weight = 4.0; huntingGear["bear trap"] = info; // also an ammo
    info.weight = 3.0; huntingGear["rope trap"] = info; // also an ammo

    // add ammo
    info.weight = 0.4; huntingGear["shells"] = info;  // 1 shotgun shell
    info.weight = 0.3; huntingGear["bullets"] = info; // 1 rifle bullet
    info.weight = 0.2; huntingGear["arrows"] = info;  // 1 arrow for bow

    // set weight, iterator
    huntingGearWeight = 0;
    it = huntingGear.begin();
} // constructor


// set amount for some huntingGear
void HuntingGear::setHuntingGear(string name, int amt) // amt >= 0, ensure such
{
    assert(amt >= 0); // ensure non-negative amount

    // get old food info
    itemInfo info = huntingGear[name]; // get info for specified huntingGear
    if (amt == info.amount) return;    // no change

    // remove/add proper weight
    if (amt < info.amount) huntingGearWeight -= (info.amount - amt) * info.weight; // less huntingGear
    else huntingGearWeight += (amt - info.amount) * info.weight;                   // more huntingGear

    // store new amount
    info.amount = amt; 
    huntingGear[name] = info; 
} // setHuntingGear


// get first item in map (key + value)
void HuntingGear::first(string& name, itemInfo& info)
{
    assert(huntingGear.begin() != huntingGear.end()); // ensure map not empty

    it = huntingGear.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}


// get next item in map (key + value)
bool HuntingGear::next(string& name, itemInfo& info) 
{
    it++;
    if (it == huntingGear.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}


// get huntingGear info
itemInfo HuntingGear::getHuntingGear(string name) // can't be const b/c of map stuff
{
    return huntingGear[name];
}


// get total weight over all medicines
double HuntingGear::getWeight() const 
{
    return huntingGearWeight;
}

*/
///////////////////////////////////// SUPPLIES ///////////////////////////////////////


Supplies::Supplies()
{
    // in order post map-sorting: axles, bullets, clothes, food, rifles, tongues, wheels

    // add hunting gear
    itemInfo info = {0, 0};
    info.weight = 28.0; supplies["rifles"] = info;
    info.weight = 0.2; supplies["bullets"] = info; // 20 / box
	
    // add general goods
    info.weight = 1.5; supplies["clothes"] = info; // 1 set / person
    info.weight = 1.0; supplies["food"] = info; // in pounds

    // add wagon parts
    info.weight = 25.0; info.amount = 4; supplies["wheels"] = info; // caravans have 4 wheels
    info.weight = 40.0; info.amount = 2; supplies["axles"] = info;  // caravans have 2 axles
    info.weight = 30.0; info.amount = 1; supplies["tongues"] = info;// caravans have 1 tongue

    // set weight, iterator
    suppliesWeight = 0;
    it = supplies.begin();
} // constructor

// set amount for some supplies, adjust suppliesWeight + caravanWeight
void Supplies::setSupplies(const string& name, int amt)
{
    assert(amt >= 0); // ensure non-negative amount

    // get old supplies info
    itemInfo info = supplies[name]; // get info for specified supplies
    if (amt == info.amount) return; // no change

    // remove/add proper weight
    //   remove -> weight = info.amount - amt 
    //   add    -> weight = amt - info.amount
    double weight = (info.amount - amt) * info.weight;
    if (amt < info.amount)
    {
        suppliesWeight -=  weight; // less supplies
        Caravan::caravanWeight -= weight;
    }
    else
    {
        weight = -1 * weight; // amt - info.amount
        suppliesWeight += weight;  // more supplies
        Caravan::caravanWeight += weight;
    }

    // store new amount
    info.amount = amt; 
    supplies[name] = info; 
} // setSupplies

bool Supplies::useSupplies(const string& name, int amt)
{
    int num = getSupplies(name).amount; // get # of supplies of type name

    if (num < amt) // want to use more than exist
    {
        if (name != "food") return false; // not enough supplies
        amt = num;                        // use remaining food
    }

    setSupplies(name, num - amt); // set for 'what i have' - 'what i want to use'
    return true;
} // useSupplies

void Supplies::addSupplies(const string& name, int amount)
{
    setSupplies(name, getSupplies(name).amount + amount);
} // addSupplies

// get first item in map (key + value)
void Supplies::first(string& name, itemInfo& info)
{
    assert(supplies.begin() != supplies.end()); // ensure map not empty

    it = supplies.begin(); // set iterator to beginning of map
    name = it->first;
    info = it->second;
}

// get next item in map (key + value)
bool Supplies::next(string& name, itemInfo& info) 
{
    it++;
    if (it == supplies.end()) return false;

    name = it->first;
    info = it->second;
    return true;
}

// get supplies info
itemInfo Supplies::getSupplies(const string& name) // can't be const b/c of map stuff
{
    return supplies[name];
}

// get total weight over all supplies
double Supplies::getWeight() const 
{
    return suppliesWeight;
}

// get # of supply items in supplies map_t
int Supplies::getSize() const {return supplies.size();}


/////////////////////////////////////// PEOPLE ////////////////////////////////////////
// adjust checkHealth so pacing and stuff done first, then indiv ppl in a loop
//   since don't really need to call this 4 separate times... may dep on checkHunger

// multi-liners
People::People(): MAX_HEALTH(100), MAX_HUNGER(100)
{
    name = "John Wilkenson";
    health = MAX_HEALTH;  // very good
    hunger = MAX_HUNGER;  // stuffed
    sickness = Ill::illness[5];
} // constructor
People::People(const string& name): MAX_HEALTH(100), MAX_HUNGER(100)
{
    this->name = name;    
    health = MAX_HEALTH;  // very good
    hunger = MAX_HUNGER;  // stuffed
    sickness = Ill::illness[5];
} // constructor w/ name
People& People::operator = (const People& p)
{
    this->name = p.name;
    this->health = p.health;
    this->hunger = p.hunger;
    this->sickness = p.sickness;
    return *this;
} // operator =
string People::getHealth() const 
{
    if (health == 100) return "very good";
    if (health >= 75)  return "good";
    if (health >= 50)  return "okay";
    if (health >= 25)  return "poor";
    return "very poor";
} // getHealth
string People::getHunger() const
{
    if (hunger == 100) return "stuffed";
    if (hunger >= 75)  return "sated";
    if (hunger >= 50)  return "hungry";
    if (hunger >= 25)  return "very hungry";     
    return "starving";
} // getHunger
void People::makeSick()
{
    if (sickness != Ill::illness[5] || sickness == Ill::illness[6]) return; // already sick / dead
    int num = rand() % 100;
    if ((health < 50 && num > 40) || num > 90) sickness = Ill::illness[4]; // got typhoid fever
    else if ((health < 60 && num > 50) || num > 80) sickness = Ill::illness[3]; // got diphtheria
    else if ((health < 68 && num > 60) || num > 75) sickness = Ill::illness[2]; // got cholera
    else if ((health < 75 && num > 70) || num > 70) sickness = Ill::illness[1]; // got measels
    else if ((health < 80 && num > 80) || num > 65) sickness = Ill::illness[0]; // got dysentary
} // makeSick
void People::checkHealth(const string& ration, const string& pace, bool noFood, bool noClothes)
{
    if (sickness != Ill::illness[6]) // can't get/treat sicknesses if dead
    {
        // determine healing/hunger effect from rationing
        int healing = -3; int hungry = -15;          // bare
        if (noFood) { healing = -20; hungry = -20; } // out of food
        else if (ration == Caravan_Rationing::ration[1]) { healing = -1; hungry = -8; }
        else if (ration == Caravan_Rationing::ration[2]) { healing = 3; hungry = -4; }
        else if (ration == Caravan_Rationing::ration[3]) { healing = 7; hungry = 4; }

        // account for pacing
        if (pace == Caravan_Pacing::pace[3]) { healing += -5; hungry += -6; }
        else if (pace == Caravan_Pacing::pace[2]) { healing += -2; hungry += -2; }
        else if (pace == Caravan_Pacing::pace[1]) { healing += 5; hungry += 2; }
        else if (pace == Caravan_Pacing::pace[0]) { healing += 8; hungry += 6; }
        else { healing += 10; hungry += 10; } // stopped

        // apply hungry to hunger
        hunger += hungry;
        if (hunger > MAX_HUNGER) hunger = MAX_HUNGER;
        else if (hunger < 0) hunger = 0;

        // apply hunger to healing
        if (hunger > 90) healing += 5;
        else if (hunger >= 80) healing += 2;
        else if (hunger < 50) healing += -10;
        else if (hunger < 60) healing += -8;
        else if (hunger < 70) healing += -5;
        else healing += -2; // hunger < 80

        // determine ailment effect from sickness
        int ailment = 0;
        if (sickness != Ill::illness[5])
        {
            int i = 0;
            for (i; i < 5; i++)
                if (sickness == Ill::illness[i]) // else has a different disease
                {
                    ailment = -2 * (i + 1); // 2 4 6 8 10
                    break;
                }
        }

        // account for absence of clothes
        if (noClothes) healing += -10;

        // apply healing/ailment from hunger, set hunger
        // checkHunger(ration, pace, noFood);

        // apply effects, check if at max health or dead
        health += healing + ailment;
                

        if (health > MAX_HEALTH) health = MAX_HEALTH;
        else if (health < 1) {health = 0; sickness = Ill::illness[6];}
    } // if alive
} // checkHealth
void People::checkHunger(const string& ration, const string& pace, bool noFood)
{
    /* MOVED INTO CHECKHEALTH */
    // determine detriment/aid from rationing
    int hungry = 0;           // ration == "ample"
    if (noFood) hungry = -20; // out of food
    else if (ration == Caravan_Rationing::ration[0]) hungry = -8;
    else if (ration == Caravan_Rationing::ration[1]) hungry = -4;
    else if (ration == Caravan_Rationing::ration[3]) hungry = 4;
 
    // determine detriment/aid from pace
    if (pace == Caravan_Pacing::pace[3]) hungry += -6;
    else if (pace == Caravan_Pacing::pace[2]) hungry += -2;
    else if (pace == Caravan_Pacing::pace[1]) hungry += 2;
    else if (pace == Caravan_Pacing::pace[0]) hungry += 6;
    else hungry += 10; // pace == "stopped"

    // apply hungry to hunger, determine health detriment/aid
    hunger += hungry;
    if (hunger > MAX_HUNGER) hunger = MAX_HUNGER;
    else if (hunger < 0) hunger = 0;

        // aid health
        if (hunger > 90) health += 5;
        else if (hunger >= 80) health += 2;

        // detriment to health
        else if (hunger < 50) health += -10;
        else if (hunger < 60) health += -8;
        else if (hunger < 70) health += -5;
        else health += -2; // hunger < 80
} // checkHunger
void People::treatSickness()
{
    //********************* account for resting for a few days.
    // see makeSick for details
    if( (sickness == Ill::illness[0] && health >= 85) // dysentary: short-term
     || (sickness == Ill::illness[1] && health >= 80) // measels: short-medium
     || (sickness == Ill::illness[2] && health >= 75) // cholera: medium
     || (sickness == Ill::illness[3] && health >= 65) // diphtheria: medium
     || (sickness == Ill::illness[4] && health >= 60)) // typhoid: toughest
     sickness = Ill::illness[5]; // cured 
} // treatSickness


// 1-liners
string People::getName() const {return name;}         // getName
string People::getSickness() const {return sickness;} // getSickness
void People::setHealth(int health) {this->health = health;} // setHealth
void People::setHunger(int hunger) {this->hunger = hunger;} // setHunger


///////////// ITEMWEARDOWN ///////////
const int itemWearDown::MAX_WEAR = 100; // for testing, really = 100
itemWearDown::itemWearDown(): BASE_AXLES(2), BASE_WHEELS(4), BASE_TONGUES(1)
{
    // percents of intactness
    rifle = MAX_WEAR;
    cloth = MAX_WEAR;
    axle = MAX_WEAR;
    wheel = MAX_WEAR;
    tongue = MAX_WEAR; // for some reason assembly lines up
                       // w/ this and erases it, forcefully fixed in CPP
    ox = MAX_WEAR;
} // constructor

// only call once per day
void itemWearDown::applyWearDown(Caravan& car, const string& pace)
{
    // amounts of wearable items
    int cl = car.getCaravanSupplies("clothes").amount; 
    int ax = car.getCaravanSupplies("axles").amount;
    int wh = car.getCaravanSupplies("wheels").amount;  
    int to = car.getCaravanSupplies("tongues").amount;
    int oxn = car.getOxen();

    // wear down items based on caravan speed
    if (pace == Caravan_Pacing::pace[3]) // blazing
    {
        if (cl > 0) cloth -= 20; 
        if (ax > 0) axle -= 5;
        if (wh > 0) wheel -= 12;
        if (to > 0) tongue -= 8;
        if (oxn > 0) ox -= 7;
    }

    else if (pace == Caravan_Pacing::pace[2]) // fast
    {
        if (cl > 0) cloth -= 16; 
        if (ax > 0) axle -= 4;
        if (wh > 0) wheel -= 9;
        if (to > 0) tongue -= 6;
        if (oxn > 0) ox -= 6;
    }

    else if (pace == Caravan_Pacing::pace[1]) // steady
    {
        if (cl > 0) cloth -= 10; 
        if (ax > 0) axle -= 3;
        if (wh > 0) wheel -= 6;
        if (to > 0) tongue -= 4;
        if (oxn > 0)  ox -= 3;
    }

    else if (pace == Caravan_Pacing::pace[0]) // slow
    {
        if (cl > 0) cloth -= 8; 
        if (ax > 0) axle -= 2;
        if (wh > 0) wheel -= 3;
        if (to > 0) tongue -= 2;
        if (oxn > 0) ox -= 2;
    }
    
    else // stopped
    {
        if (cl > 0) cloth -= 5; 
        if (ax > 0) axle -= 1;
        if (wh > 0) wheel -= 1;
        if (to > 0) tongue -= 1;
        if (oxn > 0)
        {
            ox += 15;            // oxen gain health while stopped
            if (ox > MAX_WEAR)
                ox = MAX_WEAR;   // cap ox health at MAX_WEAR
        }
    }

    // check conditon of items
    if (cloth <= 0)
    {
        car.useSupply("clothes", 1);
        cloth = MAX_WEAR;
    }

    if (wheel <= 0)
        car.event_for_parts("wheels", car.wearDown.BASE_WHEELS, wheel);

    if (axle <= 0)
        car.event_for_parts("axles", car.wearDown.BASE_AXLES, axle);
    
    if (tongue <= 0)
        car.event_for_parts("tongues", car.wearDown.BASE_TONGUES, tongue);

    if (ox <= 0 && oxn > 0)
    {
        car.event_for_oxen();
        ox = MAX_WEAR;
    }
} // applyWearDown

////////////// CARAVAN ////////////////////
// statics
double Caravan::caravanWeight = 0; // needed for Supplies::useSupplies()
int Caravan::slowerPace = 0; // [-35, 0], changed by broken wagon parts + dead oxen, use anywhere that deals w/ pacing...
                               // dealt w/: subDistance... does it even effect anything else?

// multi-liners
Caravan::Caravan(): MAX_WEIGHT(2000)
{
    // caravan Weight
    //caravanWeight = food.getWeight();
    //caravanWeight += medicine.getWeight();
    //caravanWeight += huntingGear.getWeight();
    //caravanWeight = supply.getWeight();
    //caravanWeight = 0;
    oxen = 4;
    rationing = Caravan_Rationing::ration[3]; // full
    distance = 2000;
    money = 1500;
    days = 0;
    pacing = Caravan_Pacing::pace[1]; // steady
    it = people.begin();
} // constructor 
bool Caravan::getPerson(People& p, const string& name)
{
    // no people OR no such name
    if (people.empty()) return false;
    if (people.find(name) == people.end()) return false; // map.find returns an iterator
    
    // get person
    p = people[name]; ///////////*************** FIX ******************
    return true;
} // getPeople
bool Caravan::eatFood()
{
    int eaten = people.size() * 2; // 2 pounds per person
    if (rationing == Caravan_Rationing::ration[3]) eaten *= 5;
    else if (rationing == Caravan_Rationing::ration[2]) eaten *= 4;
    else if (rationing == Caravan_Rationing::ration[1]) eaten *= 2;
    
    supply.useSupplies("food", eaten);

    // check on food
    if (supply.getSupplies("food").amount <= 100)
        if (!goHunting()) // if true -> food won't be at 0
            if (supply.getSupplies("food").amount == 0) return true;

    return false;
} // eatFood
void Caravan::subDistance()
{
    int travel = 20; // pacing == slow
    if (pacing == Caravan_Pacing::pace[3]) travel = 60;
    else if (pacing == Caravan_Pacing::pace[2]) travel = 45;
    else if (pacing == Caravan_Pacing::pace[1]) travel = 30;
    
    // account for broken parts and dead oxen
    travel += slowerPace;
    if (travel < 10) travel = 10; // avoid negative travel

    distance -= travel;
    if (distance < 0) distance = 0;
} // subDistance
void Caravan::sick(bool noFood)
{
    bool noClothes = supply.getSupplies("clothes").amount <= 0;

    for (it = people.begin(); it != people.end(); it++)
    {
        it->second.checkHealth(rationing, pacing, noFood, noClothes);
        it->second.treatSickness();
        it->second.makeSick();
    } // iterate over people in caravan
} // sick
void Caravan::restCaravan(int rest)
{
    while (rest > 0)
    {
        // deal w/ food
        bool noFood = eatFood();
        bool noClothes = supply.getSupplies("clothes").amount <= 0;
        
        // deal w/ people
        for (std::map<string, People>::iterator iter = people.begin(); iter != people.end(); iter++)
        {
            iter->second.checkHealth(rationing, Caravan_Pacing::pace[4], noFood, noClothes);
            iter->second.treatSickness();
        }

        wearDown.applyWearDown(*this, Caravan_Pacing::pace[4]); // wear on items during rest
        days++;
        rest--;
    } // while
} // restCaravan
void Caravan::runCaravan()
{
    subDistance();
    sick(eatFood()); // eat food, do sick stuffs
    wearDown.applyWearDown(*this, pacing); // wear on items
    days++;
} // runCaravan
bool Caravan::goHunting()
{
    // variables
    int foodGained = 0;
    int ammo = supply.getSupplies("bullets").amount;
    char answer = 'y';
    bool hasRifle = true;
    int bullets = 1; // bullets to invest in hunting
    if (supply.getSupplies("rifles").amount == 0) hasRifle = false;

    // prompt
    std::cout << "\nYou have " << supply.getSupplies("food").amount
              << " pounds of food left, and your caravan can hold "
              << (int)(MAX_WEIGHT - caravanWeight) << " more pounds."
              << " Would you like to go hunting(y/n)? ";
    std::cin >> answer;

    // don't hunt
    if (answer != 'y' && answer != 'Y') return false;
    else if (ammo <= 0)
    {
        std::cout << "You don't have any bullets left.\n";
        return false;
    }
    else if (!hasRifle)
    {
        std::cout << "You don't have a rifle.\n";
        return false;
    }
    else if (caravanWeight >= MAX_WEIGHT)
    {
        std::cout << "Caravan cannot hold anymore weight.\n";
        return false;
    }

    // hunt
    while(answer == 'y' || answer == 'Y')
    {
        // how many bullets to spend
        std::cout << "How many bullets would you like to invest? ";
        std::cin >> bullets;
        if (bullets > ammo) bullets = ammo; // cap at how many left in supply

        while (bullets > 0)
        {
            // check on rifle
            if (wearDown.rifle <= 0 || !hasRifle)
            {
                std::cout << "Your rifle is broken, ";
                if (hasRifle)
                {
                    supply.useSupplies("rifles", 1); // rifle broken
                    if (supply.getSupplies("rifles").amount == 0)
                        hasRifle = false; // no more rifles
                    wearDown.rifle = 100; // reset rifle condition (in prep for new rifle)
                }

                if (!hasRifle)
                {
                    std::cout << "you don't have a replacement.\n";
                    goto hunting_end;  // hunted at least once
                }

                std::cout << "you found a replacement.\n";
            } // if broken rifle or none exist

            // do hunting
            int bulletsUsed = rand() % 4 + 1;            // bullets to use this round       
            if (bulletsUsed > bullets) bulletsUsed = bullets;  // don't use more bullets than requested
            supply.useSupplies("bullets", bulletsUsed);  // shot the bullets
            bullets -= bulletsUsed;                      // bullets left to use
            wearDown.rifle -= (rand() % 4 + 1);          // wear on rifle
            foodGained += (rand() % 15) + 5;             // got some food (5-20 pounds)
        } // while 
        

        // print hunting results
        ammo = supply.getSupplies("bullets").amount;
        std::cout << "\nYou have " << ammo
                  << " bullets left and gained " << foodGained 
                  << " pounds of food total.\n";        
        if (ammo == 0) break; // out of bullets      

        // prompt continuation
        std::cout << "Keep hunting(y/n)? ";
        std::cin >> answer;
    } // while
hunting_end:
    // cap food gain at 300 pounds, less of caravan goes over weight limit
    int weightCheck = foodGained + caravanWeight;
    if (foodGained > 300 || weightCheck > MAX_WEIGHT) 
    {
        if (foodGained > 300)
        {
            foodGained = 300;
            std::cout << "You were only able to carry back 300 pounds.\n";
        }
        else
        {
            foodGained = MAX_WEIGHT - caravanWeight;
            std::cout << "Your wagon could only hold " << foodGained << " pounds more.\n";
        }
    }

    // add food gain to supplies
    supply.addSupplies("food", foodGained);
    return true;
}
void Caravan::first(People& person)
{
    assert(people.begin() != people.end());

    it = people.begin();
    person = it->second;
}
bool Caravan::next(People& person)
{
    it++;
    if (it == people.end()) return false;
    person = it->second;
    return true;
}
bool Caravan::spendMoney(int dollars)
{
    if (dollars > money) return false;
    money -= dollars;
    return true;
} // spendMoney
void Caravan::addSupply(const string& name, int amt, int cost /*=0*/)
{
    // fix slowerPace if necessary, do 1st since adding supplies changes things
    if (slowerPace < 0) // don't do anything if not set 
    {
        int have = supply.getSupplies(name).amount; // number of parts caravan has

        // see if any parts are currently broken (amount owned < BASE)
        if (name == "wheels" && have < wearDown.BASE_WHEELS)
        {
            // +1 for each replaced wheel
            for (have; have < wearDown.BASE_WHEELS; have++) {slowerPace += 1;}
        }

        if (name == "axles" && have < wearDown.BASE_AXLES)
        {
            // +3 for each replaced axle
            for (have; have < wearDown.BASE_AXLES; have++) {slowerPace += 3;}
        }

        if (name == "tongues" && have < wearDown.BASE_TONGUES)
        {
            slowerPace += 5; // +5 for the replaced tongue            
        }
    } // if slowerPace is set

    money -= cost; // make purchase
    supply.addSupplies(name, amt);
} // addSupply
void Caravan::showSupplies()
{
    // supply info
    string name; itemInfo info;
    supply.first(name, info);

    // print supply name + amount
    std::cout << "\nYour curent supplies (caravan weight is "
              << (int)caravanWeight << " pounds):\n";
    do
    {
        std::cout << name;
        int spaces = 10 - name.size();
        for (int i = 0; i < spaces; i++) std::cout << " ";
        std::cout << info.amount;
        if (name == "bullets")
        {
            std::cout << " bullets" << std::endl;
            continue; // stop if not on conditioned item
        }
		else if (name == "food")
		{
			std::cout << " pounds" << std::endl;
			continue;
		}

        // print current item's condition
        if (info.amount != 0) // only bother if item exists
        {
            std::cout << ", ";
            if (name == "clothes")      std::cout << "current set at " << wearDown.cloth;
            else if (name == "rifles")  std::cout << "current rifle at " << wearDown.rifle;
            else if (name == "axles")   std::cout << "worst axle at " << wearDown.axle;
            else if (name == "tongues") std::cout << "current tongue at " << wearDown.tongue;
            else std::cout << "worst wheel at " << wearDown.wheel;
            std::cout << "% health.\n";
        }

        else std::cout << std::endl;
    } while (supply.next(name, info));

    std::cout << "oxen      " << oxen << ", sickest one at "
              << wearDown.ox << "% health.\n";
} // showSupplies
void Caravan::event_for_parts(const string& name, int base, int& durability)
{
    int numParts = supply.getSupplies(name).amount;
    if (numParts > 0)  // else (== 0) all parts broken -> don't do anything
    {
        // print event message
        std::cout << "1 of the " << name << " has broken.";
        if (numParts > base)
            std::cout << " You replaced it with a spare.\n";
        else // no spare parts (ie 5 wheels = 1 spare)
        {
            std::cout << " You could not find a spare,"
                       << " but managed to fix it somehow.\n";

            // pace slowers since dealing w/ broken stuff
            if      (name == "wheels") slowerPace += -1; // 4 broken wheels = -4
            else if (name == "axles")  slowerPace += -3; // 2 broken axles = -6
            else                       slowerPace += -5; // name == "tongues"; 1 broken tongue = -5
            assert (slowerPace < 1 && slowerPace > -36); // max = -15 + -5x(# of dead oxen)
        }

        // use 1 part in supply, reset durability
        supply.useSupplies(name, 1);
        durability = itemWearDown::MAX_WEAR;
    }
} // event for broken wagon parts
void Caravan::event_for_oxen()
{
    // cannot replenish oxen
    std::cout << "1 of the oxen has succumbed to illness and died.\n";
    killOxen();
    slowerPace += -3; // permanent
}
void Caravan::trade()
{
    // iterate to 2 random supplies
    int num1 = rand() % supply.getSize(); // your item - the number they want from you
    int num2 = rand() % supply.getSize(); // their item - the number they're willing to give to you
    string s1, s2; itemInfo info1, info2;
    supply.first(s1, info1); for (int i = 0; i < num1; i++) supply.next(s1, info1);
    supply.first(s2, info2); for (int i = 0; i < num2; i++) supply.next(s2, info2);
	if (info1.amount == 0) info1.amount = 1; // account for 0
	if (info2.amount == 0) info2.amount = 1; // "           "

    // get amount of items
    int amount1 = (rand() % info1.amount) + 1; // yours
    int amount2 = (rand() % info2.amount) + 1; // theirs

    // print your items in trade
    std::cout << "You are offered to trade " << amount1;
    if (s1 == "food") std::cout << " pounds";
    std::cout << " of your " << s1
              << " in exchange for " << amount2;
    if (s2 == "food") std::cout << " pounds";
    std::cout << " of their " << s2 << ".\n";

    // print current caravan weight
    std::cout << "Your caravan can carry at most " << (int)(MAX_WEIGHT - caravanWeight) << " pounds more.\n";

    // prompt for answer
    char answer;
    std::cout << "Do you accept?(y/n): ";
    std::cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
		if (info1.amount > supply.getSupplies(s1).amount) // if they want more than you have...
		{
			std::cout << "You don't have enough of that item to trade.\n";
		}
		else // you have enough items for the trade
		{
            int weightChange = (amount2 * info2.weight) - (amount1 * info1.weight);
            if (caravanWeight + weightChange > MAX_WEIGHT)
            {
                std::cout << "Cannot trade, caravan will become overweight.\n";
            }
            else
            {
                supply.useSupplies(s1, amount1); // trade out your items
                supply.addSupplies(s2, amount2); // trade in their items
			}
		}
    }   
} // trade
void Caravan::sellSupplies()
{
    // supplies to sell
    int item = 1; int amount = 0; string supplyName = "";
    int prices[7] = {3, 1, 1, 15, 30, 20, 20}; // clothes, bullet box, food, wheel, axle, tongue, rifle
                                               // index by item - 2 since options start at choice #2
    int earn = 0; // price * amount
    int earnTotal = 0; // total earnings

    while (true)
    {
    // print menu
    std::cout << "\nWelcome to the store's buyback counter:"
              << " You have $" << money << " in your pocket.\n\n"
			  
              // options
              << "0 See your supplies\n"
              << "1 Done selling\n"
              << "2 Sell sets of clothes: $" << prices[0] << std::endl 
              << "3 Sell boxes of bullets: $" << prices[1] << std::endl
              << "4 Sell pounds of food: $" << prices[2] << std::endl
              << "5 Sell wheels: $" << prices[3] << std::endl
              << "6 Sell axles: $" << prices[4] << std::endl
              << "7 Sell tongues: $" << prices[5] << std::endl
              << "8 Sell rifles: $" << prices[6] << std::endl

              // choice
              << "Enter the number for your choice: ";

    // determine course of action
    while (true)
    {
        std::cin >> item;
        if (item > 8 || item < 0) std::cout << "INVALID OPTION, RETRY: ";
        else break;
    }

    // chose 'see supply' option
    if (item == 0) {showSupplies(); continue;}

    // if done then leave, otherwise move on
    if (item == 1) return;
    std::cout << "How much do you want to sell?: ";

    // determine name of item to sell
    if (item == 2) supplyName = "clothes";
    else if (item == 3) supplyName = "bullets";
    else if (item == 4) supplyName = "food";
    else if (item == 5) supplyName = "wheels";
    else if (item == 6) supplyName = "axles";
    else if (item == 7) supplyName = "tongues";
    else supplyName = "rifles";

    // get + validate amount
    while (true)
    {
        std::cin >> amount;
        if (supplyName == "bullets") amount *= 20; // selling by the box

        if (amount < 0) std::cout << "INVALID AMOUNT, RETRY: ";
        else if (amount > supply.getSupplies(supplyName).amount)
            std::cout << "You don't have enough of this item, retry (0 to stop): "; 
        else break;
    }

    // if nothing to sell then reselect
    if (amount == 0) continue; 

    // process transaction
    supply.useSupplies(supplyName, amount); // remove inventory
    earn = prices[item - 2] * amount; // get $ earned from supplies
    money += earn; // add earnings to total money
    std::cout << "You have earned $" << earn << ", and now"
              << " you have $" << money << std::endl;
    } // while (run f())
} // sellSupplies
void Caravan::setRationing(const string& ration)
{
    if (ration == rationing) return;
    
    if (ration == Caravan_Rationing::ration[0]
     || ration == Caravan_Rationing::ration[1]
     || ration == Caravan_Rationing::ration[2]
     || ration == Caravan_Rationing::ration[3])
        rationing = ration;
} // setRationing
void Caravan::setPacing(const string& pace) 
{
    if (pace == pacing) return;
    if (pace == Caravan_Pacing::pace[0]
      || pace == Caravan_Pacing::pace[1]
      || pace == Caravan_Pacing::pace[2]
      || pace == Caravan_Pacing::pace[3]
      || pace == Caravan_Pacing::pace[4])
        pacing = pace;
}  // setPacing



// 1-liners
int Caravan::getDays() const {return days;}
bool Caravan::caravanIsOverweight() const {return caravanWeight > MAX_WEIGHT;}
double Caravan::getCaravanWeight() const {return caravanWeight;}                            // getCaravanWeight
itemInfo Caravan::getCaravanSupplies(const string& name) {return supply.getSupplies(name);} // getCaravanSupplies
int Caravan::getMoney() const {return money;}   // getMoney
void Caravan::killOxen() {if (oxen > 0) oxen--;}// killOxen
void Caravan::setSupply(const string& name, int amt) {supply.setSupplies(name, amt);} // setSupply
void Caravan::setPerson(const People& p) {people[p.getName()] = p;}                   // setPerson
void Caravan::useSupply(const string& name, int amt) {supply.useSupplies(name, amt);} // useSupply
int Caravan::getDistance() const {return distance;}    // getDistance
void Caravan::setDistance(int dist) {distance = dist;} // setDistance
int Caravan::getOxen() const {return oxen;}  // getOxen
void Caravan::setOxen(int ox) {oxen = ox;}   // setOxen
string Caravan::getRationing() const {return rationing;}               // getRationing
string Caravan::getPacing() const {return pacing;}            // getPacing
void Caravan::earnMoney(int dollars) {money += dollars;} // add money

// working on




///////////////////// PIT-STOP F()S ///////////////////////
// making static struct etc FAILS
int location::operator - (const location& loc) const
{
    return (this->distance - loc.distance);
}
void visitPitStop(const string& town, Caravan& car)
{
    // print city name
    std::cout << "\n\nVisiting " << town << std::endl << "-------------\n";

    // loop city menu
    while (true)
    {
        printCityMenu();
        int answer = 1;
        std::cin >> answer;
        std::cout << std::endl;

        if (answer == 2) car.goHunting();
        else if (answer == 3) visitStore(car);
        else if (answer == 4) car.restCaravan(1);
        else if (answer == 5) car.showSupplies();
        else if (answer == 6) car.trade();
        else if (answer == 7) car.sellSupplies();
        else  // answer == 1
        {
            if (car.caravanIsOverweight())
            {
                std::cout << "Caravan overweight, cannot move.\n";
            }
            else break;
        }
    }
} // visitPitStop

void visitRiver (const string& river, Caravan& car)
{
    std::cout << "\n\nYou have arrived upon the " << river << ".\n"
              << "----------------------------------------------\n"
              << "How would you like to handle crossing it?\n";

    int answer = 1; int cost = 25;
    std::cout << "1 Ferry across (safest, costs $" << cost << ")\n"
              << "2 Float caravan (not too safe, takes 2 days to prepare)\n"
              << "3 Forcefully drive oxen to pull caravan across (dangerous, can go immediately)\n";
    std::cin >> answer;

    // ferry
    if (answer == 1)
    {
        int moneyHave = car.getMoney();
        if (moneyHave < cost)
        {
            std::cout << "You only have $" << moneyHave << ", choose another option: ";
            std::cin >> answer;
            if (answer == 1) answer = 2;
        }
        else 
        {
            car.spendMoney(cost);
            std::cout << "You safely ferried across.\n\n";
        }
    } // if ferried

    // float
    else if (answer == 2)
    {
        car.restCaravan(2);
        std::cout << "After 2 days of preparation, you attempt to float across the river.\n";

        if ((rand() % 100) >= 75)
        {
            std::cout << "You successfully floated across!\n\n";
        }
        else
        {
            std::cout << "You failed to float across. You lost:\n";
            std::cout << "  " << lossOfSupplies("bullets", 2, car) << " bullets\n"
                      << "  " << lossOfSupplies("clothes", 3, car) << " sets of clothes\n"
                      << "  " << lossOfSupplies("food", 4, car) << " pounds of food\n"
                      << "  " << lossOfSupplies("wheels", 3, car, true) << " wheels\n"
                      << "  " << lossOfSupplies("axles", 2, car, true) << " axles\n\n";                      
        }        
    } // if floated

    // force
    else
    {
        std::cout << "You decide that man was made to tame nature, NOT the other way around.\n"
                  << "You attempt to force your way through the long puddle and... you ";
        
        if (rand() % 2 == 1)
        {
            std::cout << "succeeded.\n"
                      << "Nature knows not who it trifles with!.\n\n";
        }
        else
        {
            bool deadOx = rand() % 5 < 3; // 3/5 chance lose an oxen

            std::cout << "failed.\n"
                      << "Truely you know not your true place in the world; you have lost: \n";
            std::cout << "  " << lossOfSupplies("rifles", 1, car) << " rifles\n"
                      << "  " << lossOfSupplies("bullets", 2, car) << " bullets\n"
                      << "  " << lossOfSupplies("clothes", 1, car) << " sets of clothes\n"
                      << "  " << lossOfSupplies("food", 2, car) << " pounds of food\n"
                      << "  " << lossOfSupplies("wheels", 1, car, true) << " wheels\n"
                      << "  " << lossOfSupplies("axles", 1, car, true) << " axles\n"
                      << "  " << lossOfSupplies("tongues", 1, car, true) << " tongues\n";
            if (deadOx)
            {
                car.killOxen();
                std::cout << "  1 ox drowned\n\n";
            }
        } // if failed
    } // if forced
} // visitRiver

int lossOfSupplies(const string& supplyName, int divisor, Caravan& car, bool parts)
{
    int have = car.getCaravanSupplies(supplyName).amount;
	if (have == 0) return 0;    // if you had nothing, then you lost nothing
    int loss = (rand() % have) / divisor;
    if (parts) // parts in use count towards supplies
    {
        // ensure don't break anything in use
        if (supplyName == "wheels") { if (have <= 4) return 0; }
        else if (supplyName == "axles") { if (have <= 2) return 0; }
        else if (supplyName == "tongues") if (have <= 1) return 0;

        if (loss > have) loss = loss - have; 
    }
    else if (loss > have) loss = have; // non-parts can get used up
    car.useSupply(supplyName, loss);
    return loss;
}

void visitLandmark (const string& name, Caravan& car)
{
    std::cout << "Welcome to " << name << ".\n"
              << "------------------------\n"
              << "What would you like to do?\n"
              << "1 Rest for a day\n"
              << "2 Trade with fellow travelers\n"
              << "3 Stare at " << name << "'s beauty\n";
    int answer = 3;
    std::cin >> answer;

    if (answer == 1)
    {
        car.restCaravan(1);
        std::cout << "You decided to camp for the day and had a relaxing night.\n";
    }

    else if (answer == 2)
    {
		char trade = 'y';
        if (rand() % 4 == 0) do
        {
            car.trade();
            trade = 'y';
            std::cout << "Would you like to trade more(y/n)? ";
            std::cin >> trade;
        } while (trade == 'y' || trade == 'Y');

        else std::cout << "You could not find anyone with whom to trade.\n";
    }

    else // answer == 3
    {
        std::cout << "You stare at this landmark for what feels like 15 minutes.\n"
                  << "Then your party members drag you away and you continue the journey.\n";
    }
} // visitLandmark

void printCityMenu()
{
    std::cout << "\n1 Return to the trail\n"
              << "2 Hunt\n"
              << "3 Shop\n"
              << "4 Rest\n"
              << "5 Check supplies\n"
              << "6 Attempt to trade\n"
              << "7 Sell supplies\n"
              << "Enter the number for your choice: ";
} // printCityMenu
void visitStore(Caravan& car)
{
    // supplies to purchase
    int item = 1; int amount = 0; string supplyName = "";
    int cost[7] = {5, 20, 3, 35, 70, 53, 43}; // clothes, bullet box, food, wheel, axle, tongue, rifle
                                             // index by item - 2 since options start at choice #2
    int spend = 0; // cost * amount
	Supplies sup;  // needed for weights

    while(true)
    {
    // print menu
    std::cout << "\nWelcome to the store:\n"

              // current caravan weight + money
              << "Your caravan can carry "
              << (int)(car.MAX_WEIGHT - car.getCaravanWeight())
              << " more pounds.\n"
              << "You have $" << car.getMoney() << std::endl

              // options
              << "1 Done shopping\n"
			  << std::fixed << std::setprecision(2)
			  << "2 Buy sets of clothes: $" << cost[0] << " (" << sup.getSupplies("clothes").weight << " lbs)" << std::endl
              << "3 Buy boxes of bullets (20/box): $"  << cost[1] << " (" << sup.getSupplies("bullets").weight << " lbs)" << std::endl
              << "4 Buy pounds of food: $" << cost[2] << " (" << sup.getSupplies("food").weight << " lbs)" << std::endl
              << "5 Buy wheels: $" << cost[3] << " (" << sup.getSupplies("wheels").weight << " lbs)" << std::endl
              << "6 Buy axles: $" << cost[4] << " (" << sup.getSupplies("axles").weight << " lbs)" << std::endl
              << "7 Buy tongues: $"  << cost[5] << " (" << sup.getSupplies("tongues").weight << " lbs)" << std::endl
              << "8 Buy rifles: $" << cost[6] << " (" << sup.getSupplies("rifles").weight << " lbs)" << std::endl
              
              // choice
              << "Enter the number for your choice: ";

    // determine course of action
    while (true)
    {
        std::cin >> item;
        if (item > 8) std::cout << "INVALID OPTION, RETRY: ";
        else break;
    }

    if (item == 1) return;
    std::cout << "How much do you want to buy?: ";
    std::cin >> amount;

    // process transacition
        // find + display cost
        spend = cost[item - 2] * amount; // get cost of supplies
        std::cout << "Your total comes to $" << spend << std::endl;

        // determine name of item to buy
        if (item == 2) supplyName = "clothes";
        else if (item == 3) {supplyName = "bullets"; amount *= 20;}
        else if (item == 4) supplyName = "food";
        else if (item == 5) supplyName = "wheels";
        else if (item == 6) supplyName = "axles";
        else if (item == 7) supplyName = "tongues";
        else supplyName = "rifles";
        
        // check potential caravan weight + monetary status
        while (true)
        {
            double itemWeight = car.getCaravanSupplies(supplyName).weight;
            double potentialWeight = car.getCaravanWeight() + (itemWeight * amount);
            if (potentialWeight > car.MAX_WEIGHT)
            {
                int purchaseMax = (car.MAX_WEIGHT - car.getCaravanWeight()) / itemWeight;
                std::cout << "Too much, caravan will go over weight limit."
                          << " Can purchase at most " << purchaseMax << std::endl;

                std::cout << "How much do you want to buy?: ";
                std::cin >> amount;
                continue;
            }

            if (spend > car.getMoney())
            {
                int purchaseMax = car.getMoney() / cost[item - 2];
                std::cout << "You don't have enough money."
                          << " You can purchse at most " << purchaseMax << std:: endl;

                std::cout << "How much do you want to buy?: ";
                std::cin >> amount;              // get new amount
                spend = cost[item - 2] * amount; // get new cost
            } 
            else break;
        } // while (check weight)

        // add in the supplies
        car.addSupply(supplyName, amount, spend);   
    } // while (run f())
} // visitStore

///////////////////////// TESTING F()S ////////////////////////
/*
void testFood()
{
    // verify f() called
    std::cout << "checking on food\n";

    // variables for helpful'ness
    string name;
    itemInfo info;

    // constructor
    Food f;

    // setFood
    name = "apple"; f.setFood(name, 5); // >
    name = "beans"; f.setFood(name, 11);
    f.setFood(name, 11);                // ==
    name = "apple"; f.setFood(name, 3); // <

    // getWeight -> 3 apples (1.5) + 11 beans (8.8) = 10.3
    //   off at most by .5
    assert(f.getWeight() >= 10.2 && f.getWeight() <= 10.4);

    // getFood, first, next
    f.first(name, info);
    do {assert(info == f.getFood(name));}
        while (f.next(name, info));
          
        // set rest of food
        f.first(name, info);
        do
        {
            f.setFood(name, 5);     // set current food
            info = f.getFood(name); // get new info
        } while (f.next(name, info));

    // next thing to test...
         // std::cout << name << ": " << info.amount
         //         << " " << info.weight << std::endl;
} // testFood
void testSupplies()
{
    // verify f() called
    std::cout << "checking on supplies\n";

    // variables for helpful'ness
    string name;
    itemInfo info;

    // constructor
    Supplies s;

    // getSupplies
    name = "rifle"; s.setSupplies(name, 5); // >
    name = "clothes"; s.setSupplies(name, 11);
    s.setSupplies(name, 11);                // ==
    name = "rifle"; s.setSupplies(name, 3); // <

    // getWeight -> 3 rifles (84) + 11 setsOfClothes (16.5) = 100.5
    //   off at most by .5
    assert(s.getWeight() >= 100.0 && s.getWeight() <= 101.1);

    // getSupplies, first, next
    s.first(name, info);
    do {assert(info == s.getSupplies(name));}
        while (s.next(name, info));
          
        // set rest of supplies to 5 each
        s.first(name, info);
        do
        {
            s.setSupplies(name, 5);     // set current supply
            info = s.getSupplies(name); // get new info
        } while (s.next(name, info));

    // useSupplies
    std::cout << "Old wagon weight = " << s.getWeight() << std::endl; // 628.5
    if (s.useSupplies("clothes", 3)) // had 5, use 3, now have 2 -> weight -= 4.5
    {
        std::cout << "clothes = " << s.getSupplies("clothes").amount;
        std::cout << "\nNew wagon weight = " << s.getWeight() << std::endl; // 624
    }
    else std::cout << "FAIL\n";
} // testSupplies
void testPeople()
{ 
    // verify f() called
    std::cout << "checking on people\n";

    // default constructor, accessors
    People ppl;
    assert("John Wilkenson" == ppl.getName());
    assert("very good" == ppl.getHealth());
    assert("stuffed" == ppl.getHunger());
    assert(ppl.getSickness().empty()); 

    // name constructor, mutators
    People person("Harry Henderson");
    assert("Harry Henderson" == person.getName());
    person.setHealth(49); assert("poor" == person.getHealth());
    person.setHunger(66); assert("hungry" == person.getHunger());
    person.makeSick(); std::cout << person.getSickness() << std::endl; // uses RNG
} // testPeople
void testCaravan()
{
    // verify f() called
    std::cout << "checking on caravan\n";

    // constructor: weight, oxen, distance
    Caravan car; 
    assert(car.getCaravanWeight() == 0 && car.getOxen() == 0);

    // mutators + accessors
        // create 3 People objects and set 2
        People p1("Matt Beaux"); People p2; People p3("Hank");
        p1.setHealth(50);
        p2.setHunger(10); 

        // mutators
        car.setSupply("rifle", 2); // calls supplies.setSupplies
        car.setPerson(p1);
        car.setOxen(15);
        car.setPerson(p2);
        car.setDistance(545);
        car.setRationing("Ample");
        car.setPacing("fast");

        // accessors - most
        assert(2 == car.getCaravanSupplies("rifle").amount); // calls supplies.getSupplies
        assert(car.getCaravanWeight() == 56);
        assert(car.getOxen() == 15);
        assert(car.getDistance() == 545);
        assert(car.getRationing() == "Ample");
        assert(car.getPacing() == "fast");

        // accessor - getPerson
        assert(car.getPerson(p3, "John Wilkenson")); // p3 = p2
        assert(p3.getHunger() == "starving"); 

        // subDistance
        int dist = car.getDistance();
        car.subDistance();
        assert(car.getDistance() == (dist - 15));
} // testCaravan
void testClasses()
{
    srand(0); // seed random # generator

    //testFood();
    //std::cout << "food ran\n\n";

    testPeople();
    std::cout << "people ran\n\n";

    testCaravan();
    std::cout << "caravan ran\n\n";

    testSupplies();
    std::cout << "supplies ran\n\n";

    system("Pause");
}
*/
////////////////////////          ///////////////////////////