#include <iostream>
#include <string>

#include "function_main.h"

#include "nvwa-master/nvwa/debug_new.h"

int main(int argc, char* argv[])
{
	std::string fileName;  //{ "rezerwacje.txt" };  //zmienna testowa gdy nie ma funkcji readArgs()
	
	fileName=readArgs(argc, argv);
	startSorting(fileName);

	return 0;
}