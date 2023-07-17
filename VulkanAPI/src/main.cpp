#include <stdexcept>
#include <iostream>
#include "App.h"


int main()
{
	
	try {
		App{}.Run();		
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}