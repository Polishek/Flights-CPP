#ifndef FUNCTION_LISTS_H
#define FUNCTION_LISTS_H

#include "structures.h"

/** Funkcja odpowiedzialna za stworzenie listy w przypadku gdy takiej jeszcze nie ma dla danego lotu lub za wywo³anie innej funkcji dotycz¹cej umieszczenia pasa¿era na liscie
	@param person Zmienna zawieraj¹ca nazwisko oraz numer miejsca pasa¿era
	@param pList Zmienna przechowuj¹ca wskaŸnik na pierwszy element listy pasa¿erów danego lotu
	@param passengersAmount Zmienna aktualizuj¹ca przez referencje iloœæ pasa¿erów dla danego lotu
*/
void addPassenger(Passenger person, ListOfPassengers*& pList, int& passengersAmount);

/** Funkcja odpowiedzialna za umieszczenie pasa¿era we w³aœciwym miejscu listy, tak aby by³a zachowana kolejnoœæ rosn¹ca wzglêdem numerów zajmowanych miejsc
	@param person Zmienna zawieraj¹ca nazwisko oraz numer miejsca pasa¿era
	@param pHead Zmienna przechowuj¹ca wskaŸnik na listê pasa¿erów danego lotu
*/
void addInPlace(Passenger person, ListOfPassengers*& pList);

/** Funkcja odpowiedzialna za wypisanie listy pasa¿erów do pliku
	@param pHead Zmienna przechowuj¹ca wskaŸnik na listê pasa¿erów danego lotu
	@param newFile Strumieñ wyjœcia
*/
void writePassList(ListOfPassengers* pHead, std::ostream& newFile);

/** Funkcja odpowiedzialna za usuwanie listy pasa¿erów po wypisaniu jej do pliku
	@param pHead Zmienna przechowuj¹ca wskaŸnik na listê pasa¿erów danego lotu
*/
void deletePassList(ListOfPassengers* pHead);

#endif
