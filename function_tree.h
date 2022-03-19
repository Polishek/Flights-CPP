#ifndef FUNCTION_TREE_H
#define FUNCTION_TREE_H

#include "structures.h"

/** Funkcja odpowiedzialna za sprawdzenie czy w drzewie istnieje lot o podanym symbolu
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param pTreeHead Zmienna zawieraj�ca wska�nik na g�ow� drzewa
	@param szukany Zmienna w przypadku znalezienia lotu jest modyfikowana i przyjmuje warto�� wska�nika na dany lot, je�eli lot nie zosta� znaleziony ma warto�� nullptr
	@return Je�eli taki lot istnieje, to funkcja zwraca warto�� true
*/
bool checkExistance(Information currFlight, Tree* pTreeHead, Tree*& szukany);

/** Funkcja odpowiedzialna za stworzenie nowego lotu w drzewie oraz je�eli drzewo jest puste ustawienie poprzez referencj� wska�nika na g�ow� drzewa
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param person Zmienna typu 'Passanger' potrzebna do zapisania nazwiska pasa�era oraz jego numeru miejsca
	@param pTreeHead Zmienna zawieraj�ca wska�nik na g�ow� drzewa
*/
void createFlight(Information currFlight, Passenger person, Tree*& pTreeHead);

/** Funkcja odpowiedzialna za znaleziene w�z�a pod ktorym mo�na umie�ci� nowy lot
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param pTreeHead Zmienna zawieraj�ca wska�nik na g�ow� drzewa
	@return Funkcja zwraca wska�nik na wez� pod kt�rym zostanie zamieszczony nowo stworzony lot
*/
Tree* findSlot(Information currFlight, Tree* pTreeHead);

/** Funkcja odpowiedzialna za otworzenie nowego pliku i stworzenie strumienia wyj�ciowego oraz wypisanie informacji na temat lotu, a tak�e wywo�anie funkcji writePassList i funkcji deletePassList
	@param pTreeHead Zmienna zawieraj�ca wska�nik na g�ow� drzewa
*/
void returnTree(Tree* pTreeHead);

/** Funkcja odpowiedzialna za usuni�cie aktualnego w�z�a z pami�ci oraz ustawienie g�owy drzewa poprzez referencj� na ni�szym w�le
	@param pTreeHead Zmienna zawieraj�ca wska�nik na g�ow� drzewa
*/
void deleteTree(Tree*& pTreeHead);

#endif
