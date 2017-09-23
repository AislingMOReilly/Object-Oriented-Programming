// Author: Aisling O'Reilly     Class: 062CA

#include <string>

using namespace std;

const unsigned short numComponents = 50;
unsigned short currentDriv, currentVeh, currentCust = 0, currentFare = 0, currentLog = 0;

class Person {
//protected:
public:
    string fullname, phoneNum;
public:
    void getDetails ();
};

class Customer: virtual public Person {
// protected:
public:
    string source, destination, pickUpTime;
    char wheelUse;
    unsigned short passengerNum;
public:
    void getCustDetails ();
    void showLoggedCustomers();
} customers[numComponents] = {};


class Driver: virtual public Person {
//protected:
public:
    string IDnum, address, startDate, license;
    float revGen, mileage;
    bool available;
public:
    Driver (string id, string n, string a, string pn, float kms, string d, string l, float r, bool av) {IDnum = id; fullname = n; address = a; phoneNum = pn; mileage = kms; startDate= d; license = l; revGen = r; available = av;};
    Driver () {};
} dr1("1234567A", "Tom Daly", "14 Green St., Cork",	"087-6543210", 23231.0, "12/08/2008", "B", 0, true),
dr2("2345678B", "Anne O'Brien", "Beach View” Kinsale",	"086-5432109", 11980.0, "09/12/2011", "D", 0, true),
dr3("3456789B", "James Twomey", "14, French St., Cork",	"085-4321098", 18414.0, "14/11/2010", "D1", 0, true),
dr4 ("4567890C", "Mary O'Neill", "23 Castle Road, Youghal",	"089-8765432", 12669.0, "11/02/2014", "B", 0, true),
dr5("5678901D", "Brendan Brown", "98 Nuns Walk, Cork",	"083-2109876", 23864.0, "01/04/2007", "D", 0, true),
dr6("6789012E", "Vincent Coy", "Green Valley, Cobh", "087-8901234", 34196.0, "03/04/1998", "D1", 0, true),
drivers[6] = {dr1, dr2, dr3, dr4, dr5, dr6};

class Vehicle {
// protected:
public:
    string vehType, regNum, make, model;
    unsigned short capacity;
    float vehRevGen, vKMdriven;
    bool wheelAcc, free;
public:
    Vehicle (string vT, string rN, string m, string mod, float vkms, unsigned short cap, bool wA, float vR, bool fr) {vehType = vT; regNum = rN; make = m; model = mod; vKMdriven = vkms; capacity = cap; wheelAcc = wA; vehRevGen = vR; free = fr;};
    Vehicle () {};
} tx1("Taxi", "12C4956", "Hyundai",	"i30 Tourer", 65172.0, 4, true, 0, true),
tx2("Taxi", "14C89365", "Ford",	"Mondeo", 33892.0, 4, true, 0, true),
tx3("Taxi", "15C46046", "VW", "Passat", 23897.0, 4, true, 0, true),
tx4("Taxi", "14C38492", "Nissan", "Primera", 29418.0, 4, true, 0, true),
tx5("Taxi", "10C99393", "Skoda", "Octavia", 89678.0, 4, true, 0, true),
tx6("Taxi", "15C2379", "Seat",	"Toledo", 12812.0, 4, true, 0, true),
bs1("Bus", "10C37209", "Ace",	"Cougar", 28786.0, 48, true, 0, true),
bs2("Bus", "11C882", "Daimler", "Fleetline", 68893.0, 48, false, 0, true),
mb1("Minibus", "14C23908", "Ford", "Transit", 18827.0, 16, true, 0, true),
mb2("Minibus", "10C831", "Fiat", "Ducato	", 32986.0, 16, true, 0, true),
mb3("Minibus", "13C82677", "Mercedes-Benz", "Vario", 18567.0, 20, false, 0, true),
vehicles[11] = {tx1, tx2, tx3, tx4, tx5, tx6, bs1, bs2, mb1, mb2, mb3};


class Fare: public Customer, public Driver, public Vehicle {
//protected:
public:
    string returnTime;
    unsigned short fareNum;
    float jLength, fareCost = 0.0;
private:
    float coCharge = 5.0, pricePerKM = 6.5;
public:
    void getJourneyLength () {cout << "\n\tEnter the Journey Length in Kilometres: "; cin >> jLength;};
    void checkAvailability ();
    void getFareDetails ();
    void showCurrentFares();
    void addDetailsToFare (unsigned short, string, string, string, string, string, string, unsigned short, char, float, string, string);
    float calcCost (float journL);
} fares[6] = {};


class Log: public Fare {
public:
    void markFarecomplete ();
    void fillLogDetails (unsigned short, string, string, string, string, string, string, unsigned short, char, float, string, string, float);
    void showLoggedFares();
} logs[numComponents] = {};



class Report: public Fare {
private:
    float dayKM, revenue;
public:
    void outputTitle () {cout << "\n\n\n\t*******************\n\t End of Day Report \n\t*******************\n\n"; };
    void outputVehicleDetails ();
    void outputDriverDetails ();
} rep;

