#ifndef FUNCTION_LISTS_H
#define FUNCTION_LISTS_H

#include "structures.h"

/** Funkcja odpowiedzialna za stworzenie listy w przypadku gdy takiej jeszcze nie ma dla danego lotu lub za wywo�anie innej funkcji dotycz�cej umieszczenia pasa�era na liscie
	@param person Zmienna zawieraj�ca nazwisko oraz numer miejsca pasa�era
	@param pList Zmienna przechowuj�ca wska�nik na pierwszy element listy pasa�er�w danego lotu
	@param passengersAmount Zmienna aktualizuj�ca przez referencje ilo�� pasa�er�w dla danego lotu
*/
void addPassenger(Passenger person, ListOfPassengers*& pList, int& passengersAmount);

/** Funkcja odpowiedzialna za umieszczenie pasa�era we w�a�ciwym miejscu listy, tak aby by�a zachowana kolejno�� rosn�ca wzgl�dem numer�w zajmowanych miejsc
	@param person Zmienna zawieraj�ca nazwisko oraz numer miejsca pasa�era
	@param pHead Zmienna przechowuj�ca wska�nik na list� pasa�er�w danego lotu
*/
void addInPlace(Passenger person, ListOfPassengers*& pList);

/** Funkcja odpowiedzialna za wypisanie listy pasa�er�w do pliku
	@param pHead Zmienna przechowuj�ca wska�nik na list� pasa�er�w danego lotu
	@param newFile Strumie� wyj�cia
*/
void writePassList(ListOfPassengers* pHead, std::ostream& newFile);

/** Funkcja odpowiedzialna za usuwanie listy pasa�er�w po wypisaniu jej do pliku
	@param pHead Zmienna przechowuj�ca wska�nik na list� pasa�er�w danego lotu
*/
void deletePassList(ListOfPassengers* pHead);

#endif
