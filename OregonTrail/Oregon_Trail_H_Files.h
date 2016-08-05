/* CHANGES
ppl can get sickness / cured of them
health determined by hunger and pace and sickness (interrelated everywhere) and if 0 food remains
there exist pit-stops
money system
Caravan::wearDown made public for easy use
item / oxen wearDowns + pacing problems resultant

*/

/* ADD
events such as 'lost your way' 
 // RNG events

Continue on trail   DONE
Check supplies      DONE
Change pace         DONE
Change food rations DONE
Stop to rest        DONE
Attempt to trade    PENDING
*/


////////// libraries shared among all classes //////////
#include <map>
#include <sstream>
#include <string>
using std::string;

#include <vector>

#include <cassert>

////////// struct itemInfo, typedef Map_t //////////
#ifndef ITEMINFO
#define ITEMINFO

struct itemInfo
{
    int amount;    // # of units
    double weight; // pounds per unit
    bool operator == (const itemInfo& info);
};

typedef std::map <string, itemInfo> Map_t; // shorten name of map-type

#endif


////////// class Food //////////
#ifndef FOOD
#define FOOD


class Food
{
public:
    // constructors
    Food();

    // mutators
    void     setFood(string name, int amt);

    // for iteration
    void     first(string& name, itemInfo& info); // always exists
    bool     next(string& name, itemInfo& info);

    // general accessors
    itemInfo getFood(string name); // can't be const b/c of map stuff
    double   getWeight() const;

    // Say ok compilerly map <string, itemInfo>::iterator& begin() {return food.begin();}

private:
    double foodWeight;
    Map_t food;
    Map_t::iterator it;
};
#endif


///////////////// class MEDICINE //////////////
#ifndef MEDICINE
#define MEDICINE

class Medicine
{
public:
    // constructors
    Medicine();

    // mutators
    void     setMedicine(string name, int amt);

    // for iteration
    void     first(string& name, itemInfo& info); // always exists
    bool     next(string& name, itemInfo& info);

    // general accessors
    itemInfo getMedicine(string name); // can't be const b/c of map stuff
    double   getWeight() const;
    
private:
    double medicineWeight;
    Map_t medicine;
    Map_t::iterator it;
};
#endif


//////////////// class HUNTINGGEAR ////////////
#ifndef HUNTINGGEAR
#define HUNTINGGEAR

class HuntingGear
{
public:
    // constructors
    HuntingGear();

    // mutators
    void     setHuntingGear(string name, int amt);

    // for iteration
    void     first(string& name, itemInfo& info); // always exists
    bool     next(string& name, itemInfo& info);

    // general accessors
    itemInfo getHuntingGear(string name); // can't be const b/c of map stuff
    double   getWeight() const;
    
private:
    double huntingGearWeight;
    Map_t huntingGear;
    Map_t::iterator it;
};
#endif


///////////////// class PEOPLE ////////////////////
#ifndef PEOPLE
#define PEOPLE

class People // make array while running
{
public:
    // friends

    // constructors
    People();
    People(const string& name);
    People& operator = (const People& p);

    // accessors
    string getName() const;
    string getHealth() const;
    string getHunger() const;
    string getSickness() const;
    
    // mutators
    void setHealth(int);
    void setHunger(int);
    void makeSick();      // RNG + low enough health
    void checkHealth(const string& ration, const string& pace, bool noFood, bool noClothes = false); // calls checkHunger
    void checkHunger(const string& ration, const string& pace, bool noFood);
    void treatSickness(); // cures illness based on health


    const People& getPeople() const {return *this;} //***** shove into CPP FILE, do I really need this since i have caravan iteration?

private:
    string name;
    int health;
    int hunger;
    string sickness;
    const int MAX_HEALTH;
    const int MAX_HUNGER;
};
#endif


////////////////// Structs holding 1 static const string array  //////////////////
#ifndef ILL
#define ILL

struct Ill  // seat illnesses into a struct
{
    static const string illness[7];
};
#endif

#ifndef CARAVAN_RATIONING
#define CARAVAN_RATIONING

struct Caravan_Rationing  // seat caravan ration options into a struct
{
    static const string ration[4];
};
#endif

#ifndef CARAVAN_PACING
#define CARAVAN_PACING

struct Caravan_Pacing  // seat caravan pacing options into a struct
{
    static const string pace[5];
};
#endif

//////////////// class SUPPLIES ///////////
#ifndef SUPPLIES
#define SUPPLIES

class Supplies
{
public:
    // friends

    // constructors
    Supplies();

    // mutators
    void     setSupplies(const string& name, int amt);
    bool     useSupplies(const string& name, int amt);
    void     addSupplies(const string& name, int amt);

    // for iteration
    void     first(string& name, itemInfo& info); // always exists
    bool     next(string& name, itemInfo& info);

    // general accessors
    itemInfo getSupplies(const string& name); // can't be const b/c of map stuff
	double   getWeight() const;
    int      getSize() const;
    
private:
    double suppliesWeight;
    Map_t supplies;
    Map_t::iterator it;
};
#endif

/////////// struct itemWearDonw /////////
#ifndef ITEMWEARDOWN
#define ITEMWEARDOWN

class Caravan;

// only apply wearing if 1+ item exists, reset after losing an item
struct itemWearDown
{
    static const int MAX_WEAR; // maximum durability of the below
    const int BASE_AXLES;  // all caravans have 2 axles
    const int BASE_WHEELS; // all caravans have 4 wheels
    const int BASE_TONGUES;// all caravans have 1 tongue

    int rifle;  // only wearDown if hunt, if (0 rifles) can't hunt
    int cloth;  // if (0 clothes) lose health 
    int axle;   // steep hard
    int wheel;  // mod hard
    int tongue; // steep hard
    int ox;     // steep hard

    itemWearDown(); // constructor
    void applyWearDown(Caravan& car, const string& pace); // calls event tracking for wagon parts + oxen
};
#endif


////////////// class CARAVAN ////////////////
#ifndef CARAVAN
#define CARAVAN

class Caravan
{
public:

    // public variables
    static int slowerPace;
    const double MAX_WEIGHT; // MAX caravan weight
 
    // friends
    friend class Supplies; // for modifying caravanWeight in setSupplies

    // constructor
    Caravan();

    // iteration of people
    void first(People& person); // always exists
    bool next(People& person);

    // event tracking
    itemWearDown wearDown; // track condition of breakable items 
    void event_for_parts(const string& name, int base, int& durability);
    void event_for_oxen();
    void eventHandler(); // RNG events such as 'lost your way'

    // accessors
    double getCaravanWeight() const; 
    int getMoney() const;
    itemInfo getCaravanSupplies(const string& name);
    bool getPerson(People&, const string&);
    int getOxen() const;
    int getDistance() const;
    string getRationing() const;
    string getPacing() const;
    bool caravanIsOverweight() const;
    int getDays() const;

    // mutators
    void setSupply(const string& name, int amt);
    void useSupply(const string& name, int amt);
    void addSupply(const string& name, int amt, int cost = 0);
    void killOxen();
    bool spendMoney(int dollars);
    void earnMoney(int dollars);
    void setPerson(const People&);
    void setOxen(int ox);
    void setDistance(int dist);
    void subDistance(); // subtract distance
    void setRationing(const string&);
    void setPacing(const string& pace);
    bool eatFood(); // # pounds / person / day, calls goHunting()
    bool goHunting(); // get food (RNG + user wishes)
    void sick(bool noFood); // do peoples' sicknesses
    void runCaravan(); // do 1 days' working of the caravan
    void restCaravan(int rest); // do not move caravan, heal, etc
    void showSupplies(); // print supplies
    void trade(); // conduct in trade
    void sellSupplies(); // sell supplies for money

private:
    //Food food;
    //Medicine medicine;
    //HuntingGear huntingGear;
    //int horses;

    Supplies supply;                       // items in caravan
    std::map<string, People> people;       // persons in caravan
    std::map<string, People>::iterator it; // iterator for people
    int oxen;                              // always have 6 unless die
    static double caravanWeight;
    int money;

    int distance; // distance to destination
    int days;     // days traveled
    string rationing; // how much food is eaten / day (full, ample, meager, bare bones)
    string pacing;    // how far to travel / day (blazing, fast, steady, slow)
};
#endif

///////////////////// PIT-STOP F()S ////////////////
// making static struct etc FAILS

///////// struct LOCATION //////
#ifndef LOCATION
#define LOCATION
struct location
{
    char type; // town, river, landmark
    string name;
    int distance;
    int operator- (const location&) const;
};
#endif
///////////////
void visitPitStop(const string& town, Caravan& car); // calls printCityMenu(), visitStore()
void visitRiver (const string& river, Caravan& car); // calls lossOfSupplies
void visitLandmark (const string& name, Caravan& car);
int lossOfSupplies(const string& supplyName, int divisor, Caravan& car, bool parts = false); 
void printCityMenu();                     
void visitStore(Caravan& car);

////////////////////// TESTING F()S ////////////////////////////
void testFood(); // should also cover huntingGear, medicine
void testSupplies();
void testPeople(); // accesses Ill::illness
void testCaravan();
void testClasses();

////////////////////////        //////////////////////////////////