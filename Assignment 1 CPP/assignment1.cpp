//  Class: 062CA    Object: Aisling O'Reilly

#include <iostream>
#include <iomanip>

using namespace std;

/***********************Customer Class*****************************/
class Customer {
private:
    string firstname, fullname, address1, address2, address3;
public:
    Customer () {};
    void printCustomer () {cout << "\n\tName:\t" << fullname << "\n\tAddress:\t" << address1 << "\n\t\t\t\t" << address2 << "\n\t\t\t\t" << address3;};
    void printFirstname() {cout << firstname;};
    void getCustomerDetails ();
} customer1;

/*************************Time Class*****************************/
class Time {
public:
    unsigned short hours, mins;
    Time () {};
    Time (unsigned short h, unsigned short m) {hours = h; mins = m;};
    void getFlightTime();
    Time operator-(Time);
    Time operator+(Time);
} depTime, arrTime;

/*************************Journey Class*****************************/
class Journey {
public:
    string depAirport, arrAirport, depDate, arrDate;
    float cost = 0;
    Journey() {};
    Time totalFlightTime = Time(), flightTime = Time(), depTime = Time(), arrTime = Time();
    void getFlightDetails();
    void printTickets();
};

/**********************Travel Agent Class***************************/
class TravelAgent {
private:
    bool done = false;
    unsigned short flightCounter = 0;
    float journeyCost, totalFlightCost, commission;
public:
    Journey flight1, flight2;
    unsigned short outputMenu();
    void printLetter();
    void genReport();
    void exit() {done = true;};
    bool quit() {return done;};
} agent;


/*####################### Main Program ##########################*/
int main () {

  do {
    unsigned short option = agent.outputMenu();

	  switch (option) {
         case 1: customer1.getCustomerDetails(); break;
         case 2: agent.flight1.getFlightDetails(); agent.flight2.getFlightDetails(); break;
         case 3: agent.flight1.printTickets(); agent.flight2.printTickets(); break;
         case 4: agent.printLetter(); break;
         case 5: agent.genReport(); break;
         case 6: agent.exit(); break;
        default: cout << "\n\n" << option << " is not a valid option. Please re-enter choice when prompted.\n\t";
        }
  }
  while (!agent.quit());

    return 0;
}

/*-----------------------Output Menu Method - (ref: TravelAgent)------------------------------*/
unsigned short TravelAgent::outputMenu() {
    //Outputs main menu

     unsigned short option;

     cout << "\n\t_____________________"
          << "\n\n\tWelcome to LDF Travel"
          << "\n\t_____________________"
          << "\n\n\t Please select from the following options:\n"
          << "\t\t1. Add New Customer.\n"
          << "\t\t2. Enter Flight Details.\n"
          << "\t\t3. Print Tickets.\n"
          << "\t\t4. Print Letter.\n"
          << "\t\t5. Generate Report.\n"
          << "\t\t6. Exit the program."
          <<"\n\n\t\tChoice> ";
     cin >> option;
     return option;
}


/*----------------------Get Customer Details Method - (ref: Customer)-------------------------*/
void Customer::getCustomerDetails(){
    //Reads in Customer name, address and finds first name

    cin.ignore();

    cout << "\n\tEnter the customer's name:\t";
    getline(cin, fullname, '\n');

    unsigned short spcInd = fullname.find(" ");
    firstname = fullname.substr(0, spcInd);

    cout << "\n\tEnter the first line of the customer's address:\t";
    getline(cin, address1, '\n');
    cout << "\n\tEnter the second line of the customer's address:";
    getline(cin, address2, '\n');
    cout << "\n\tEnter the last line of the customer's address:\t";
    getline(cin, address3, '\n');

}

/*----------------------Get Flight Details Method - (ref: Journey)------------------------------*/
void Journey::getFlightDetails(){
    /* Reads in and validates Arrival and Departure Airports and Times and
    calls the 'getFlightTime' method for the Departure Date and Arrival date objects */

    bool val1 = false, val2 = false, val3 = false, val4 = false;

    cin.ignore();

    do {
        cout << "\n\tEnter the Departure Date (in the form dd.mm.yyyy):\t";
        getline(cin, depDate, '\n');
        if (depDate.length() != 10)
                cout << "\n\tInvalid input. Please enter in the form dd.mm.yyyy";
        else
            val1 = true;
    } while(!val1);

    do {
        cout << "\n\tEnter the Departure Airport:\t";
        getline(cin, depAirport, '\n');
        if (depAirport.length() != 3)
            cout << "\n\tInvalid input. Please enter Airport as 3 letter prefix (e.g. LHR)";
        else
            val2 = true;
    } while(!val2);


    depTime.getFlightTime();
    cout << "\n\t________________________________\n\n";

    cin.ignore();

    do {
        cout << "\n\tEnter the Arrival Date (in the form dd.mm.yyyy):\t";
        getline(cin, arrDate, '\n');
        if (arrDate.length() != 10)
                cout << "\n\tInvalid input. Please enter in the form dd.mm.yyyy";
        else
            val3 = true;
    } while(!val3);

    do {
        cout << "\n\tEnter the Arrival Airport:\t";
        getline(cin, arrAirport, '\n');
        if (arrAirport.length() != 3)
                cout << "\n\tInvalid input. Please enter Airport as 3 letter prefix (e.g. LHR)";
        else
            val4 = true;
     } while(!val4);


    arrTime.getFlightTime();
    cout << "\n\t________________________________\n\n";

    cout << "\n\tEnter the Flight Cost:\tE";
    cin >> cost;
    cout << "\n\n\n";
}


/*----------------------Get Flight Time Method - (ref: Time)------------------------------*/
void Time::getFlightTime(){
    // Reads in and validates the hours and mins for depTime and arrTime objects when called
    bool valid1 = false, valid2 = false;

    do {
        cout << "\n\tEnter the Hours:\t";
        cin >> hours;
        if (hours > 24 || hours < 0)
            cout << "\n\tInvalid input. Please enter a number between 0 and 24";
        else
            valid1 = true;
    } while(!valid1);

    do {
        cout << "\n\tEnter the Minutes:\t";
        cin >> mins;
        if (mins > 60 || mins < 0)
            cout << "\n\tInvalid input. Please enter a number between 0 and 60";
        else
            valid2 = true;
    } while(!valid2);

}


/*----------------------Overloading -Operator - (ref: Time)------------------------------*/
Time Time::operator-(Time temp) {
    // Overloads the - operator enabling subtraction of one Time class object from another in order to calculate the duration of a flight
    Time duration (hours - temp.hours, mins - temp.mins);

    if (duration.mins > 60) {
        temp.mins+=60;
        temp.hours--;
    }
    if (duration.hours < 0) {
        temp.hours+=24;
    }
    return duration;
}

/*----------------------Overloading +Operator - (ref: Time)------------------------------*/
Time Time::operator+(Time temp2) {
    // Overloads the + operator enabling the addition of 2 Time class objects
    Time totalDuration (hours + temp2.hours, mins + temp2.mins);

    if (totalDuration.mins > 60) {
        temp2.mins-=60;
        temp2.hours++;
    }
    return totalDuration;
}

/*----------------------Print Tickets Method - (ref: Journey)------------------------------*/
void Journey::printTickets(){
    // Outputs flight Boarding Pass in rectangular box

    // Calculates the duration of a flight
    flightTime = arrTime - depTime;

    cout << "\n" << char(218) << setfill(char(196)) << setw(76) << char(191)
         << "\n" << char(179) << setfill(' ') << setw(76) << char(179)
         << "\n" << char(179) << setw(17) << "BOARDING PASS" << setw(27) << "CLASS: ECONOMY" << setw(20) << "COST: E" << setw(7) << setiosflags (ios::fixed) << setprecision(2) << cost << setw(5) << char(179)
         << "\n" << char(179) << setw(76) << char(179)
         << "\n" << char(179) << setw(76) << char(179)
         << "\n" << char(179) << setw(8) << "FROM" << setw(26) << "DATE" << setw(27) << "TIME" << setw(15) << char(179)
         << "\n" << char(179) << setw(7) << depAirport << setw(33) << depDate << setw(19) << depTime.hours << ":" << setfill('0') << setw(2) << depTime.mins << setfill(' ') << setw(14) << char(179)
         << "\n" << char(179) << setw(76) << char(179)
         << "\n" << char(179) << setw(6) << "TO" << setw(70) << char(179)
         << "\n" << char(179) << setw(7) << arrAirport << setw(33) << arrDate << setw(19) << arrTime.hours << ":" << setfill('0') << setw(2) << arrTime.mins << setfill(' ') << setw(14) << char(179)
         << "\n" << char(179) << setw(76) << char(179)
         << "\n" << char(179) << setw(26) << "EXPECTED FLIGHT TIME: " << setw(2) << flightTime.hours << "h " << setfill('0') << setw(2) << flightTime.mins << "m" << setfill(' ') << setw(43) << char(179)
         << "\n" << char(179) << setw(76) << char(179)
         << "\n" << char(192) << setfill(char(196)) << setw(76) << char(217)
         << "\n\n\n";
    flightTime = Time();
}

/*----------------------Print Letter Method - (ref: Travel Agent)------------------------------*/
void TravelAgent::printLetter() {
     // Outputs Summary Letter including Customer Details and the Journey Summary in rectangular box

     // Calculates Journey Cost
     journeyCost = flight1.cost + flight2.cost;

     // Calculates the total Journey time (i.e. total time in the air)
     Time totalFlightTime = flight1.flightTime + flight2.flightTime;

    if (flight1.depDate != flight2.arrDate)
        totalFlightTime.hours += 24;

     cout << "\n\t" << setfill(char(196)) << setw(80)
          << "\n\n\tLDF TRAVEL";
          customer1.printCustomer();
     cout << "\n\tREF:" << flight1.depAirport << "/" << flight2.arrAirport << "/" << flight2.arrDate;
     cout << "\n\n\tDear ";
          customer1.printFirstname();
     cout << ",\n\n"
          << "\tPlease find enclosed your boarding passes for your flight from " << flight1.depAirport << " to " << flight2.arrAirport
          << ".\n\n\tYour Journey is as follows:\n";

     cout << "\n\t" << char(218) << setfill(char(196)) << setw(68) << char(191)
          << "\n\t" << char(179) << setfill(' ') << setw(22) << "SUMMARY OF JOURNEY" << setw(18) << "CLASS: ECONOMY" << setw(11) << "COST: E" << setw(7) << setiosflags (ios::fixed) << setprecision (2) << journeyCost << setw(10) << char(179)
          << "\n\t" << char(179) << setw(68) << char(179)
          << "\n\t" << char(179) << setw(68) << char(179)
          << "\n\t" << char(179) << setw(8) << "FROM" << setw(22) << "DATE" << setw(18) << "TIME" << setw(20) << char(179)
          << "\n\t" << char(179) << setw(7) << flight1.depAirport << setw(29) << flight1.depDate << setw(10) << flight1.depTime.hours << ":" << setfill('0') << setw(2) << flight1.depTime.mins << setfill(' ') << setw(19) << char(179)
          << "\n\t" << char(179) << setw(68) << char(179)
          << "\n\t" << char(179) << setw(6) << "TO" << setw(62) << char(179)
          << "\n\t" << char(179) << setw(7) << flight2.arrAirport << setw(29) << flight2.arrDate << setw(10) << flight2.arrTime.hours << ":" << setfill('0') << setw(2) << flight2.arrTime.mins << setfill(' ') << setw(19) << char(179)
          << "\n\t" << char(179) << setw(68) << char(179)
          << "\n\t" << char(179) << setw(16) << "TOTAL TIME: " << setw(3) << totalFlightTime.hours << "h" << setw(2) << setfill('0') << totalFlightTime.mins << "m" << setfill(' ') << setw(45) << char(179)
          << "\n\t" << char(192) << setfill(char(196)) << setw(68) << char(217)
          << "\n\n\n\t" << setfill(char(196)) << setw(80);

     // Updates the number of flights sold
     flightCounter += 2;

     // Updates the total cost of flights
     totalFlightCost += journeyCost;
}

/*----------------------Generate Report - (ref: Travel Agent)------------------------------*/
void TravelAgent::genReport() {
    // Outputs End of Day Report

    // Calculates the Travel Agents Commission
    commission = totalFlightCost*.1;

     cout << "\n\t" << char(218) << setfill(char(196)) << setw(66) << char(191)
          << "\n\t" << char(179) << setfill(' ') << setw(66) << char(179)
          << "\n\t" << char(179) << setw(31) << "LDF TRAVEL: END OF DAY REPORT" << setw(35) << char(179)
          << "\n\t" << char(179) << setw(31) << "_____________________________" << setw(35) << char(179)
          << "\n\t" << char(179) << setw(66) << char(179)
          << "\n\t" << char(179) << setw(66) << char(179)
          << "\n\t" << char(179) << setw(26) << "NUMBER OF FLIGHTS SOLD: " << setw(5) << flightCounter << setw(35) << char(179)
          << "\n\t" << char(179) << setw(26) << "TOTAL COST OF FLIGHTS: E" << setw(9) << setiosflags (ios::fixed) << setprecision (2) << totalFlightCost << setw(31) << char(179)
          << "\n\t" << char(179) << setw(22) << "COMMISSION EARNED: E" << setw(7) << setiosflags (ios::fixed) << setprecision (2) << commission << setw(37) << char(179)
          << "\n\t" << char(179) << setw(66) << char(179)
          << "\n\t" << char(192) << setfill(char(196)) << setw(66) << char(217)
          << "\n\n\n";
}
