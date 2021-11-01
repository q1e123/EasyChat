#pragma once
#include <string>
#include <vector>

namespace Utils
{
	void memory_error();

	size_t string_to_size_t(std::string string);
	size_t gcd(size_t a, size_t b);

	std::string get_query(std::string file);

	std::string replace(std::string string, std::string substring_to_replace, std::string replacement);

	template <class T>
	std::vector<T> string_to_vector(std::string str);
}
