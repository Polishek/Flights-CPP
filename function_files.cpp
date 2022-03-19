#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "function_files.h"

void divLine(std::istream& sourceFile, Information& currFlight, Passenger& person)
{
	std::string symbol;
	getline(sourceFile, currFlight.flightSymbol, ' ');

	std::string airport;
	getline(sourceFile, currFlight.airport, ' ');

	std::string yearV;  //zmienna pomocnicza year
	getline(sourceFile, yearV, '-');
		std::stringstream convY(yearV);		//konwersja string na int
		convY >> currFlight.term.year;

	std::string monthV;  //zmienna pomocnicza month
	getline(sourceFile, monthV, '-');
		std::stringstream convM(monthV);	//konwersja string na int
		convM >> currFlight.term.month;

	std::string dayV;  //zmienna pomocnicza day
	getline(sourceFile, dayV, ' ');
		std::stringstream convD(dayV);		//konwersja string na int
		convD >> currFlight.term.day;

	std::string surname;
	getline(sourceFile, person.name, ' ');

	std::string seatNumber;
	getline(sourceFile, seatNumber);
		std::stringstream convNo(seatNumber);	//konwersja string na int
		convNo >> person.seatNumber;
}
