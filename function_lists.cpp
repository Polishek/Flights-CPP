#include <iostream>

#include "function_lists.h"

void addPassenger(Passenger person, ListOfPassengers*& pList, int& passengersAmount)
{
	if (!pList)
		pList = new ListOfPassengers{ person, nullptr };
	else
	{
		addInPlace(person, pList);  //dodaje pasazera na odpowiednie miejsce w liscie
	}

	passengersAmount++;  //zwiekszenie liczby pasazerow
}

void addInPlace(Passenger person, ListOfPassengers*& pList)
{
	if (pList->passData.seatNumber < person.seatNumber)
	{
		if (pList->pNext == nullptr)
		{
			auto pNew = new ListOfPassengers{ person,nullptr };
			pList->pNext = pNew;
		}
		else
		{
			return addInPlace(person, pList->pNext);  //zwroc nastepny wezel 
		}
	}
	else
	{
		ListOfPassengers* pNew = new ListOfPassengers{ person, pList };
		pList = pNew;
	}
}

void writePassList(ListOfPassengers* pHead, std::ostream& newFile)  //wypisanie listy
{
	if(pHead){
		if (pHead->passData.seatNumber <= 9) {
			newFile << "0";
		}
		
		newFile << pHead->passData.seatNumber << " " << pHead->passData.name << std::endl;
		writePassList(pHead->pNext, newFile);
	}
}

void deletePassList(ListOfPassengers* pHead)
{
	ListOfPassengers* pTemp = pHead;

	while (pHead)
	{
		pTemp = pHead->pNext;
		delete pHead;
		pHead = pTemp;
	}
}