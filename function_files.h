#ifndef FUNCTION_FILES_H
#define FUNCTION_FILES_H

#include "structures.h"

/** Funkcja odpowiedzialna za podzielenie pojedynczej linii pliku oraz przypisanie poszczególnych informacji odpowednim zmiennym ró¿nych typów
	@param sourceFile Strumieñ wejœca
	@param currFlight Zmienna typu 'Information' potrzebna do zapisania symbolu lotu, lotniska startowego oraz daty lotu
	@param person Zmienna typu 'Passanger' potrzebna do zapisania nazwiska pasa¿era oraz jego numeru miejsca
*/
void divLine(std::istream& sourceFile, Information& currFlight, Passenger& person);

#endif
