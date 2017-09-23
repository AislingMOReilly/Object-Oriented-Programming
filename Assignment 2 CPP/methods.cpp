// Author: Aisling O'Reilly     Class: 062CA

#include <iostream>
#include "classes.h"
#include <conio.h>


void Person::getDetails () {
    bool validNum = true;

    cout << "\n\n\tEnter the person's full name: ";
    cin.ignore();
    getline(cin, fullname, '\n');

    do {
        cout << "\n\tEnter the person's phone number: ";
        getline(cin, phoneNum, '\n');
        if (phoneNum.length () != 10) {
            validNum = false;
            cout << "\n\tPlease enter a 10 digit phone number\n";
        }
        else {
            validNum = true;
            for (unsigned short i = 0; i <= 9; i++) {
                if (!isdigit (phoneNum.at(i)))
                    validNum = false;
                else
                     validNum = true;
            }
            if (!validNum)
                cout << "\n\tOnly digits are accepted\n";
        }
    } while (!validNum);
}


void Customer::getCustDetails () {
    bool validTime = true;

    cout << "\n\tEnter the passenger's pick up point: ";
    getline(cin, source, '\n');
    cout << "\n\tEnter the passenger's destination: ";
    getline(cin, destination, '\n');
    cout << "\n\tEnter the number of passengers: ";
    cin >> passengerNum;

    do {
        cout << "\n\tEnter the pick up time in the format hh:mm\t";
        cin >> pickUpTime;
        if (pickUpTime.length () != 5) {
            validTime = false;
            cout << "\n\tThe format of the time has to be hh:mm\n";
        }
        else {
            bool outputMessage;
            validTime = true;

            for (unsigned short i = 0; i <= 1; i++) {
                if (!isdigit (pickUpTime.at(i))) {
                    validTime = false;
                    outputMessage = true;
                }
                else {
                    validTime = true;
                    outputMessage = false;
                }
            }

            for (unsigned short i = 3; i <= 4; i++) {
                if (!isdigit (pickUpTime.at(i))) {
                    validTime = false;
                    outputMessage = true;
                }
                else {
                    validTime = true;
                    outputMessage = false;
                }
            }

            if (outputMessage == true)
                cout << "\n\tPlease enter digits\n";

            if (pickUpTime.at(2) != ':') {
                validTime = false;
                cout << "\n\tThe format of the time has to be hh:mm\n";
            }
        }
    } while (!validTime);

    cout << "\n\tIs wheelchair access required?(Y/N): ";
    cin >> wheelUse;
}

void Customer::showLoggedCustomers() {
    cout << "\n\n\n\tCurrent Customer Details\n\t________________________\n\n";
    for (unsigned short i = 0; i <= currentCust; i++) {
        cout << "\n\tCustomer Number (" << i + 1 << ")\n"
             << "\n\tName:\t\t\t\t" << customers[i].fullname
             << "\n\tPhone Number:\t\t\t" << customers[i].phoneNum
             << "\n\tSource:\t\t\t\t" << customers[i].source
             << "\n\tDestination:\t\t\t" << customers[i].destination
             << "\n\tNo. of Passengers:\t\t" << customers[i].passengerNum
             << "\n\tPick Up Time:\t\t\t" << customers[i].pickUpTime
             << "\n\tWheelchair Access Needed:\t" << customers[i].wheelUse << "\n\n\n";
    }
    cout << "\n\n";
}


void Fare::checkAvailability () {
    if (currentFare == 5)
        cout << "\n\n\tWe are fully booked at present. We apologise for any incovenience caused\n\n";
    else {
        fares[currentFare].getJourneyLength ();

        bool vpass1 = false, vpass2 = false, dpass = false, found = false;
        unsigned short i = 0;

        cout << "\n\n\tCapacity Needed: " << customers[currentCust].passengerNum << "\n\n";


        /////////////////////////// Suitable Vehicle Criteria //////////////////////////

         do {
            //Available vehicle with correct capacity
            if (vehicles[i].free == true && vehicles[i].capacity >= customers[currentCust].passengerNum)
                vpass1 = true;
            else
                vpass1 = false;


            //Wheelchair access if needed
            if (toupper(customers[currentCust].wheelUse) == 'Y' && vehicles[i].wheelAcc == false)
                vpass2 = false;
            else
                vpass2 = true;

            if (vpass1 == false || vpass2 == false)
                i++;
            else
                cout << "\n\tSuitable vehicle available.\n\n";
        } while((!vpass1 || !vpass2) && i < 10);



        if (vpass1 && vpass2) {

            /////////////////////////// Suitable Driver Criteria ///////////////////////////
            unsigned short j = 0;

                do {
                    //Available Driver with valid license
                    if (drivers[j].available == true && vehicles[i].vehType == "Taxi")
                        dpass = true;
                    else if (drivers[j].available == true && vehicles[i].vehType == "Bus" && drivers[j].license == "D")
                        dpass = true;
                    else if (drivers[j].available == true && (vehicles[i].vehType == "Minibus" && (drivers[j].license == "D" || drivers[j].license == "D1")))
                        dpass = true;
                    else
                        dpass = false;

                    if (dpass == false)
                        j++;
                    else {
                        cout << "\n\tSuitable driver available.\n\n";
                        currentDriv = j;
                    }
                } while(!dpass && j < 5);


                if (dpass == false)
                    cout << "\n\n\tNo available drivers at this time. We apologise for any incovenience caused.\n\n\n";
        }
        else
            cout << "\n\n\tNo available vehicles at this time. We apologise for any incovenience caused.\n\n\n";


        /////////////////////////// Make booking ////////////////////////
        if (vpass1 && vpass2 && dpass) {

            //Update relevant driver and vehicle details
            drivers[currentDriv].available = false;
            vehicles[i].free = false;

            currentVeh = i;

            //Add details of drivers[currentDriv] and vehicles[currentVeh] to fare
            cout << "\n\n\tBooking confirmed. The driver will be with you shortly.\n\n\n";

            found = true;

            fares[currentFare].getFareDetails ();

            //Add details to Fare
            fares[currentFare].addDetailsToFare (fares[currentFare].fareNum, drivers[currentDriv].IDnum, drivers[currentDriv].fullname, vehicles[currentVeh].regNum,
                                                 vehicles[currentVeh].vehType, customers[currentCust].source, customers[currentCust].destination,
                                                 customers[currentCust].passengerNum, customers[currentCust].wheelUse, fares[currentFare].jLength,
                                                 customers[currentCust].pickUpTime, fares[currentFare].returnTime);
            fares[currentFare].showCurrentFares();

            //Increment Fare
            currentFare ++;
        }

        //Increment Customer
        currentCust ++;
    }
}


void Fare::getFareDetails () {
    fares[currentFare].fareNum = currentFare + 1;
    fares[currentFare].returnTime = "pending";
}


void Fare::addDetailsToFare (unsigned short fN, string id, string n, string rN, string vT, string so, string dest, unsigned short pN, char wU, float jL, string pT, string rT) {

    fareNum = fN;

    //driver details
    IDnum = id;
    fullname = n;

    //vehicle details
    regNum = rN;
    vehType = vT;

    //customer details
    source = so;
    destination = dest;
    passengerNum = pN;
    wheelUse = wU;

    //fare details
    jLength = jL;
    pickUpTime = pT;
     returnTime = rT;
}


void Fare::showCurrentFares() {
    cout << "\n\n\n\n\tCurrent Fare Details\n\t____________________\n";

    for (unsigned short i = 0; i <= currentFare; i++) {
        cout << "\n\n\tFare Number: " << fares[i].fareNum
             << "\n\n\tDriver ID: " << fares[i].IDnum
             << "\n\n\tDriver Name: " << fares[i].fullname
             << "\n\n\tRegistration Number: " << fares[i].regNum
             << "\n\n\tVehicle Type: " << fares[i].vehType
             << "\n\n\tSource: " << fares[i].source
             << "\n\n\tDestination: " << fares[i].destination
             << "\n\n\tPassenger Number: " << fares[i].passengerNum
             << "\n\n\tWheelchair Access: " << fares[i].wheelUse
             << "\n\n\tJourney Length: " << fares[i].jLength
             << "\n\n\tPick Up Time: " << fares[i].pickUpTime
             << "\n\n\tReturn Time: " << fares[i].returnTime
             << "\n\n\t";
    }
}

void Log::markFarecomplete () {
     unsigned short fNum;
     bool invalidNum = true;

     do {
         cout << "\n\tEnter the number of the Fare? ";
         cin >> fNum;

         if (fNum - 1 > currentFare)
            cout << "\n\tInvalid Fare Number. Please re-enter when prompted\n\n";
         else
            invalidNum = false;
     } while(invalidNum);


     bool validTime = true;

     do {
        cout << "\n\tEnter the return time in the format hh:mm\t";
        cin >> returnTime;

        fares[fNum-1].returnTime = returnTime;

        if (returnTime.length () != 5) {
            validTime = false;
            cout << "\n\tThe format of the time has to be hh:mm\n";
        }
        else {
            bool outputMessage;
            validTime = true;

            for (unsigned short i = 0; i <= 1; i++) {
                if (!isdigit (returnTime.at(i))) {
                    validTime = false;
                    outputMessage = true;
                }
                else {
                    validTime = true;
                    outputMessage = false;
                }
            }

            for (unsigned short i = 3; i <= 4; i++) {
                if (!isdigit (returnTime.at(i))) {
                validTime = false;
                outputMessage = true;
                }
                else {
                    validTime = true;
                    outputMessage = false;
                }
            }

            if (outputMessage == true)
                cout << "\n\tPlease enter digits\n";

            if (returnTime.at(2) != ':') {
                validTime = false;
                cout << "\n\tThe format of the time has to be hh:mm\n";
            }
        }
     } while (!validTime);

    //Calculate cost of fare
    fares[fNum-1].fareCost = fares[fNum-1].calcCost (fares[fNum-1].jLength);

    //Add Fare details to Log
    logs[currentLog].fillLogDetails (fares[fNum-1].fareNum, fares[fNum-1].IDnum, fares[fNum-1].fullname, fares[fNum-1].regNum,
                                     fares[fNum-1].vehType, fares[fNum-1].source, fares[fNum-1].destination, fares[fNum-1].passengerNum,
                                     fares[fNum-1].wheelUse, fares[fNum-1].jLength, fares[fNum-1].pickUpTime, fares[fNum-1].returnTime,
                                     fares[fNum-1].fareCost);
    logs[currentLog].showLoggedFares();

    //Increment Log Details
    currentLog ++;


    //Update Driver details
    for (unsigned short i = 0; i<= 5; i++) {
        if (drivers[i].IDnum == fares[fNum-1].IDnum) {
            drivers[i].mileage += fares[fNum-1].jLength;
            drivers[i].revGen += fares[fNum-1].fareCost;
            drivers[i].available = true;
        }
    }

    //Update Vehicle details
    for (unsigned short i = 0; i<= 10; i++) {
        if (vehicles[i].regNum == fares[fNum-1].regNum) {
            vehicles[i].vKMdriven += fares[fNum-1].jLength;
            vehicles[i].vehRevGen += fares[fNum-1].fareCost;
            vehicles[i].free = true;
        }
    }

    //Remove Fare Details
    for (unsigned short i = fNum - 1 ; i <= currentFare; i++) {
        fares[i] = fares[i + 1];
        currentFare--;
    }

    fares[currentFare].showCurrentFares();
}


float Fare::calcCost (float journL) {
    fareCost = coCharge + (pricePerKM * journL);

    cout << "\n\tTotal Cost of Fare : " << fareCost;

    return fareCost;
}


void Log::fillLogDetails (unsigned short fN, string id, string n, string rN, string vT, string so, string dest, unsigned short pN, char wU, float jL, string pT, string rT, float fC) {

    fareNum = fN;

    //driver details
    IDnum = id;
    fullname = n;

    //vehicle details
    regNum = rN;
    vehType = vT;

    //customer details
    source = so;
    destination = dest;
    passengerNum = pN;
    wheelUse = wU;

    //fare details
    jLength = jL;
    pickUpTime = pT;
    returnTime = rT;
    fareCost = fC;
}


void Log::showLoggedFares() {

    cout << "\n\n\n\n\tLogged Fare Details\n\t___________________\n\n";
    for (unsigned short i=0; i<= currentLog; i++) {
        cout << "\n\n\tDriver ID: " << logs[i].IDnum
             << "\n\n\tDriver Name: " << logs[i].fullname
             << "\n\n\tRegistration Number: " << logs[i].regNum
             << "\n\n\tVehicle Type: " << logs[i].vehType
             << "\n\n\tSource: " << logs[i].source
             << "\n\n\tDestination: " << logs[i].destination
             << "\n\n\tPassenger Number: " << logs[i].passengerNum
             << "\n\n\tWheelchair Access: " << logs[i].wheelUse
             << "\n\n\tJourney Length: " << logs[i].jLength
             << "\n\n\tFare Number: " << logs[i].fareNum
             << "\n\n\tPick Up Time: " << logs[i].pickUpTime
             << "\n\n\tReturn Time: " << logs[i].returnTime
             << "\n\n\tFare Cost: " << logs[i].fareCost
             << "\n\n\t";
     }
}


void Report::outputVehicleDetails() {
    cout << "\n\n\t_______________\n\n\tVehicle Details\n\t_______________\n\n";

    for (unsigned short i=0; i<=10; i++) {
        cout << "\n\n\tVehicle:\t\t\t" << vehicles[i].regNum
             << "\n\tTotal Kilometres Driven:\t" << vehicles[i].vKMdriven << "\n"
             << "\tRevenue Generated:\t\tEuro " << vehicles[i].vehRevGen << "\n";
    }

    rep.outputDriverDetails ();
}

void Report::outputDriverDetails () {
     cout << "\n\n\n\t______________\n\n\tDriver Details\n\t______________\n\n";

     for (unsigned short i=0; i<=5; i++) {
        cout << "\n\n\tDriver:\t\t\t\t" << drivers[i].IDnum
             << "\n\tTotal Kilometres Driven:\t" << drivers[i].mileage << "\n"
             << "\tRevenue Generated:\t\tEuro " << drivers[i].revGen << "\n";
     }
}

