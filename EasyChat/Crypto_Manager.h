#pragma once
#include <string>
#include <vector>


namespace Crypto_Manager{
	std::string get_sha3_512_hash(std::string message);
	std::string bytes_to_hex_string(const std::vector<uint8_t>& bytes); 
};

