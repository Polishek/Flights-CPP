#ifndef FUNCTION_MAIN_H
#define FUNCTION_MAIN_H

#include "structures.h"

/** Funkcja odpowiedzialna za odczytanie odpowiedniego prze³¹cznika z linii poleceñ zawieraj¹cego nazwê pliku w którym znajduj¹ siê dane dotycz¹ce rezerwacji lotów 
	@param argc Iloœæ podanych argumentów w linii poleceñ
	@param argv Wartoœci podanych argumentów
	@return Nazwa pliku wejœciowego
*/
std::string readArgs(int argc, char* argv[]);

/** Funkcja odpowiedzialna za rozpoczêcie g³ównego zadania programu, czyli sortowania oraz tworzenia plików z danymi
	@param fileName Nazwa pliku wejœciowego w którym zapisane s¹ wszystkie dane na temat lotu oraz pasa¿era
*/
void startSorting(std::string fileName);

#endif //!FUNKCJE_MAIN_H
