#include "Utils.h"

#include <iostream>

void Utils::memory_error()
{
	std::cerr << "MEMORY ERROR: server connection" << std::endl;
	exit(EXIT_FAILURE);
}
