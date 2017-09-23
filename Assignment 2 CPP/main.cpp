// Author: Aisling O'Reilly     Class: 062CA

#include <iostream>
#include <iomanip>
#include "methods.cpp"
#include <fstream>

using namespace std;

unsigned short outputMenu ();
void callAddFare ();
void exit ();


/*############################## Main Program ################################*/
int main () {
    bool quit = false;

    do {
        unsigned short choice = outputMenu ();

        switch (choice) {
         case 1: customers[currentCust].getDetails();
                 customers[currentCust].getCustDetails();
                 customers[currentCust].showLoggedCustomers();
                 fares[currentFare].checkAvailability();
                 break;
         case 2: logs[currentLog].markFarecomplete ();
                 break;
         case 3: rep.outputTitle();
                 rep.outputVehicleDetails();
                 break;
         case 4: exit (); quit = true;
                 break;
        default: cout << "\n\n" << choice << " is not a valid option. Please re-enter choice when prompted.\n\t";
        }
    }
    while (!quit);

    return 0;
}

unsigned short outputMenu () {
     unsigned short option;

     cout << "\n\n\t_______________________________________"
          << "\n\n\t Welcome to Call Out Dispatch Services"
          << "\n\t_______________________________________"
          << "\n\n\n\t Please select from the following options:\n"
          << "\n\n\t1: Enter Customer Details\n"
          << "\t2: Mark Fare as Complete\n"
          << "\t3: Generate Report\n"
          << "\t4: Exit Program\n"
          << "\n\n\tChoice> ";
     cin >> option;

    return option;
}

void exit () {}
