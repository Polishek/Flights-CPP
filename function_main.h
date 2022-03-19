#ifndef FUNCTION_MAIN_H
#define FUNCTION_MAIN_H

#include "structures.h"

/** Funkcja odpowiedzialna za odczytanie odpowiedniego prze��cznika z linii polece� zawieraj�cego nazw� pliku w kt�rym znajduj� si� dane dotycz�ce rezerwacji lot�w 
	@param argc Ilo�� podanych argument�w w linii polece�
	@param argv Warto�ci podanych argument�w
	@return Nazwa pliku wej�ciowego
*/
std::string readArgs(int argc, char* argv[]);

/** Funkcja odpowiedzialna za rozpocz�cie g��wnego zadania programu, czyli sortowania oraz tworzenia plik�w z danymi
	@param fileName Nazwa pliku wej�ciowego w kt�rym zapisane s� wszystkie dane na temat lotu oraz pasa�era
*/
void startSorting(std::string fileName);

#endif //!FUNKCJE_MAIN_H
