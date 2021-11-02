#pragma once
#include <sstream>
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
	std::string vector_to_string(std::vector<T> v)
	{
		std::stringstream string_stream;
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(string_stream, " "));
		std::string result = string_stream.str();
		return result;
	}

	template <class T>
	std::vector<T> string_to_vector(std::string str)
	{
		std::vector<T> result;
		std::stringstream stream(str);
		T element;
		while (stream >> element)
		{
			result.push_back(element);
		}
		return result;
	}
}
