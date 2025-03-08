// Speeding Ticket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double CAR_RATE = 1.75;
const double TRUCK_RATE = 2.15;
const double BUS_RATE = 2.35;

char getVehicleType();
int getVehicleSpeed(string prompt);
int getSpeedLimit(string prompt);
double calculateRate(char vehicleType, double vehicleSpeed, int speedLimit);


int main()
{
    char vehicleType = getVehicleType();
    int vehicleSpeed = getVehicleSpeed("Please enter the speed you were going (in mph): ");
    int speedLimit = getSpeedLimit("What is the speed limit (in mph)? ");

    if (vehicleSpeed <= speedLimit) 
    {
        cout << endl << "No speeding ticket. Your speed is within the limit." << endl;
    }
    else 
    {
        double rate = calculateRate(vehicleType, vehicleSpeed, speedLimit);
        cout << fixed << setprecision(2) << showpoint;
        cout << endl << "Your speeding ticket is $" << rate << endl;
    }

    return 0;  
}

char getVehicleType() 
{
    char type;
    do 
    {
        cout << "Please enter the vehicle type (C for Car, T for Truck, B for Bus): ";
        cin >> type;
        if (type != 'B' && type != 'b' && type != 'C' && type != 'c' && type != 'T' && type != 't')
        {
            cout << "Invalid Selection. Please enter C, T, or B for vehicle type." << endl;
        }
    } while (type != 'B' && type != 'b' && type != 'C' && type != 'c' && type != 'T' && type != 't');
    return type;
}

int getVehicleSpeed(string prompt) 
{
    int speed;
   
    do 
    {
        cout << prompt;
        cin >> speed;
        if (speed <= 0) 
        {
            cout << "Invalid Selection. Speed must be greater than 0 for the vehicle to be moving." << endl;
        }
    } while (speed <= 0);
    return speed;
} 

int getSpeedLimit(string prompt) 
{
    int limit;
    do 
    {
        cout << prompt;
        cin >> limit;
        if (limit <= 0) 
        {
            cout << "Invalid selection. The speed limit must be greater than 0." << endl;
        }
    } while (limit <= 0);
    return limit;
}
// this parameter shows us how we find the calculations
double calculateRate(char vehicleType, double vehicleSpeed, int speedLimit)
{
    double rate;
    double excessSpeed = vehicleSpeed - speedLimit;
    if (vehicleType == 'C' || vehicleType == 'c')
    {
        rate = CAR_RATE * excessSpeed;
    }
    else if (vehicleType == 'T' || vehicleType == 't')
    {
        rate = TRUCK_RATE * excessSpeed;
    }
    else
    {
        rate = BUS_RATE * excessSpeed;
    }
    return rate;
}

/*
program should ask user if driving a truck,car, or bus
program will ask what the speed limit was
program will ask how fast vehicle was moving
program will then calculate how much the speeding ticket fine is based on rate for vehicle type and how fast over time
*/