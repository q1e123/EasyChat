#pragma once
#include <string>
#include <vector>


namespace Crypto_Manager{
	const double P = 13;
	const double Q = 11;
	const double N = P * Q;
	const double PHI = (P - 1) * (Q - 1);
	const double E = 7;

	std::string get_sha3_512_hash(std::string message);
	std::string bytes_to_hex_string(const std::vector<uint8_t>& bytes);
	std::vector<size_t> rsa_encrypt(std::string message);
	std::string rsa_decrypt(std::vector<size_t> encrypted_message);

	double rsa_encrypt_char(char c);
	char rsa_decrypt_char(double encrypted);
};

