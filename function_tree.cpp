		#include <fstream>

#include "function_tree.h"
#include "function_lists.h"

bool checkExistance(Information flight, Tree* pTreeHead, Tree*& wanted)
{
	Tree* pTemp = pTreeHead;  //zmienna tymczasowa

	if (!pTemp) {
		return false;
	}
	else {
		while (pTemp) {
			if (pTemp->flightInfo.flightSymbol == flight.flightSymbol) {  //jezeli symbol aktualnego lotu jest rowny temu w drzewie zwraca TRUE oraz zmienia wanted na wskaznik na ten wezel
				wanted = pTemp;
				return true;
			}
			else {
				bool toLeft = (flight.flightSymbol < pTemp->flightInfo.flightSymbol);	//jezeli symbol lotu jest mniejszy to toLeft przyjmuje true
				bool toRight = (flight.flightSymbol > pTemp->flightInfo.flightSymbol);	//jezeli symbol lotu jest wiekszy to toRight przyjmuje true

				if (toLeft) {
					pTemp = pTemp->pLeft;
				}
				else {
					pTemp = pTemp->pRight;
				}
			}
		}
	}
	return false;  //jezeli funkcja przeleci przez cale drzewo i nie znajdzie takiego lotu bedzie wywolana funkcja tworzaca nowy lot ale to juz w dalszej czesci programu
}

void createFlight(Information currFlight, Passenger person, Tree*& pTreeHead)
{
	if (!pTreeHead) {
		pTreeHead = new Tree{ currFlight, nullptr, nullptr };  //stworzenie pierwszego wezla drzewa
		addPassenger(person, pTreeHead->flightInfo.passList, pTreeHead->flightInfo.passAmount);
	}
	else {
		Tree* pTreePom = findSlot(currFlight, pTreeHead);	//wskaznik na lot nad nullptr
		
		bool onLeft = (pTreePom->flightInfo.flightSymbol > currFlight.flightSymbol);

		if (onLeft){
			pTreePom->pLeft = new Tree{ currFlight, nullptr, nullptr };		//jezeli mniejszy to idzie na lewo a jego dzieci to nullptry
			addPassenger(person, pTreePom->pLeft->flightInfo.passList, pTreePom->pLeft->flightInfo.passAmount);
		}
		else{
			pTreePom->pRight = new Tree{ currFlight, nullptr, nullptr };	//jezeli wiekszy to idzie na prawo a jego dzieci to nullptry
			addPassenger(person, pTreePom->pRight->flightInfo.passList, pTreePom->pRight->flightInfo.passAmount);
		}
	}
}

Tree* findSlot(Information currFlight, Tree* pTree)
{
	while (pTree) {  //dopoki istnieja dalsze elementy drzewa
		if (currFlight.flightSymbol < pTree->flightInfo.flightSymbol) { //jezeli aktualny lot jest "wiekszy" od symbolu lotu w drzewie
			if (pTree->pLeft != nullptr) {  //jezeli element na ktory mamy skoczyc istnieje
				pTree = pTree->pLeft;
			}
			else {
				return pTree;
			}
		}
		else {
			if (pTree->pRight != nullptr) {
				pTree = pTree->pRight;
			}
			else {
				return pTree;
			}
		}
	}
	return pTree;
}

void returnTree(Tree* pTreeHead)  //wypisanie drzewa
{
	if(pTreeHead){
		std::string fileName = pTreeHead->flightInfo.flightSymbol;

		std::ofstream newFile(fileName + ".txt");

		newFile << "Symbol lotu: " << pTreeHead->flightInfo.flightSymbol << std::endl;
		newFile << "Lotnisko: " << pTreeHead->flightInfo.airport << std::endl;
		newFile << "Data: " << pTreeHead->flightInfo.term.year << "-" << pTreeHead->flightInfo.term.month << "-" << pTreeHead->flightInfo.term.day << std::endl;
		newFile << std::endl;
		newFile << std::endl;
		newFile << "Lista pasazerow:" << std::endl;
		writePassList(pTreeHead->flightInfo.passList, newFile);
		newFile << std::endl;
		newFile << "Ilosc rezerwacji: " << pTreeHead->flightInfo.passAmount << std::endl;

		newFile.close();

		returnTree(pTreeHead->pLeft);
		returnTree(pTreeHead->pRight);

	}
}

void deleteTree(Tree*& pTreeHead)
{
	if (pTreeHead) {
		deletePassList(pTreeHead->flightInfo.passList);  //usuniecie listy pasazerow lotu spod wartosci pTreeHead
		deleteTree(pTreeHead->pLeft);
		deleteTree(pTreeHead->pRight);
		delete pTreeHead;
		pTreeHead = nullptr;
	}

	return;
}