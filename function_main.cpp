#include <iostream>
#include <string>
#include <fstream>
//#include <sstream>

#include "structures.h"
#include "function_files.h"
#include "function_lists.h"
#include "function_tree.h"

std::string readArgs(int argc, char* argv[])
{
	std::string error{ "error" };
	
	if (argc < 3) {
		std::cout << "Podaj odpowiednia ilosc argumentow!" << std::endl;
	}

	for (int i = 0; i < argc; i++) {
		std::string Temp = argv[i];
		if (Temp == "-i") {
			return argv[i+1];
		}
	}

	std::cout << "Podana bledne polecenia!" << std::endl;
	return error;
}

void startSorting(std::string fileName)
{
	std::ifstream sourceFile(fileName);  //otworzenie pliku o nazwie rezerwacje.txt

	std::string line;
	
	Tree* pTreeHead = nullptr;

	if (sourceFile.is_open()){	//jezeli uda³o sie otworzyc plik		
		while (!sourceFile.eof()){
			
			Information currFlight;		//pomocnicza zmienna typu Information do zapisywania informacji pochadzacych z pojedynczej linii pliku  "current flight"
			Passenger person;			//pomocnicza zmienna typu Person do zapisania informacji o osobie wyczytanej z linii
			divLine(sourceFile, currFlight, person); //dzielenie linii pliku na symbol, lotnisko, date, nazwisko oraz nr miejsca pasazera
			
			if (currFlight.flightSymbol == "\n") {	//jezeli linia jest pusta przejdz do kolejnego przejsca petli
				continue;
			}
			//JAK SPRAWDZIC CZY WCZYTANY LOT NIE JEST PUSTY???
			
			Tree* pWantedFlight = nullptr;

			if (checkExistance(currFlight, pTreeHead, pWantedFlight)){		//jezeli lot istnieje to "pWantedFlight" przyjmuje wskaznik na ten wezel, a cala funkcja TRUE
				addPassenger(person, pWantedFlight->flightInfo.passList, pWantedFlight->flightInfo.passAmount);		//WARTOSCI MNIEJSZE IDA NA LEWO A WIEKSZE NA PRAWO!!!
			}
			else {
				createFlight(currFlight,person, pTreeHead);		//jezeli lot nie zostal znaleziony to zostaje wywolana funkcja createFlight odpowiedzialna za stworzenie nowego lotu
			}
		}
		
		sourceFile.close();
		
		returnTree(pTreeHead);		
		deleteTree(pTreeHead);
		
		//if (pWantedFlight) {			//jesli istnieje to usuniecie wartosci spod wskaznika pWantedFlight
		//	delete pWantedFlight;
		//	pWantedFlight = nullptr;
		//}
	}
	else
	{
		std::cout << "Nieudalo sie otworzyc pliku!" << std::endl;
	}
}