#pragma once
#include <string>
#include <vector>


namespace Crypto_Manager{
	const size_t P = 99371;
	const size_t Q = 93911;
	const size_t N = P * Q;
	const size_t PHI = (P - 1) * (Q - 1);

	std::string get_sha3_512_hash(std::string message);
	std::string bytes_to_hex_string(const std::vector<uint8_t>& bytes);
	std::string rsa_encrypt(std::string message);
	std::string rsa_decrypt(std::string message);
};

