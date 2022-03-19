#ifndef FUNCTION_TREE_H
#define FUNCTION_TREE_H

#include "structures.h"

/** Funkcja odpowiedzialna za sprawdzenie czy w drzewie istnieje lot o podanym symbolu
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param pTreeHead Zmienna zawieraj¹ca wskaŸnik na g³owê drzewa
	@param szukany Zmienna w przypadku znalezienia lotu jest modyfikowana i przyjmuje wartoœæ wskaŸnika na dany lot, je¿eli lot nie zosta³ znaleziony ma wartoœæ nullptr
	@return Je¿eli taki lot istnieje, to funkcja zwraca wartoœæ true
*/
bool checkExistance(Information currFlight, Tree* pTreeHead, Tree*& szukany);

/** Funkcja odpowiedzialna za stworzenie nowego lotu w drzewie oraz je¿eli drzewo jest puste ustawienie poprzez referencjê wskaŸnika na g³owê drzewa
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param person Zmienna typu 'Passanger' potrzebna do zapisania nazwiska pasa¿era oraz jego numeru miejsca
	@param pTreeHead Zmienna zawieraj¹ca wskaŸnik na g³owê drzewa
*/
void createFlight(Information currFlight, Passenger person, Tree*& pTreeHead);

/** Funkcja odpowiedzialna za znaleziene wêz³a pod ktorym mo¿na umieœciæ nowy lot
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param pTreeHead Zmienna zawieraj¹ca wskaŸnik na g³owê drzewa
	@return Funkcja zwraca wskaŸnik na wezê³ pod którym zostanie zamieszczony nowo stworzony lot
*/
Tree* findSlot(Information currFlight, Tree* pTreeHead);

/** Funkcja odpowiedzialna za otworzenie nowego pliku i stworzenie strumienia wyjœciowego oraz wypisanie informacji na temat lotu, a tak¿e wywo³anie funkcji writePassList i funkcji deletePassList
	@param pTreeHead Zmienna zawieraj¹ca wskaŸnik na g³owê drzewa
*/
void returnTree(Tree* pTreeHead);

/** Funkcja odpowiedzialna za usuniêcie aktualnego wêz³a z pamiêci oraz ustawienie g³owy drzewa poprzez referencjê na ni¿szym wêŸle
	@param pTreeHead Zmienna zawieraj¹ca wskaŸnik na g³owê drzewa
*/
void deleteTree(Tree*& pTreeHead);

#endif
