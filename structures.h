#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>

struct Passenger
{
	std::string name;
	int seatNumber{ 0 };
};

struct ListOfPassengers
{
	Passenger passData;
	ListOfPassengers* pNext{ nullptr };
};

struct Date
{
	int year, month, day;
};

struct Information
{
	std::string flightSymbol, airport;
	Date term{ 0,0,0 };
	ListOfPassengers* passList{ nullptr };
	int passAmount{ 0 };
};

struct Tree
{
	Information flightInfo;
	Tree* pRight,
		* pLeft;
};

#endif