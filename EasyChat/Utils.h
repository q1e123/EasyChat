#pragma once
#include <string>

namespace Utils
{
	void memory_error();

	size_t string_to_size_t(std::string string);

	std::string get_query(std::string file);

	void replace(std::string string, std::string substring_to_replace, std::string replacement);
}
