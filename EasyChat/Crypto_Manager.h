#pragma once
#include <string>
#include <vector>


class Crypto_Manager
{
public:
	Crypto_Manager(const double p, const double q, )
		: p(p),
		  q(q)
	{
		this->n = p * q;
		this->phi = (p - 1) * (q - 1);
	}

	std::string get_sha3_512_hash(std::string message);
	std::string rsa_decrypt(std::vector<double> encrypted_message);
	std::vector<double> rsa_encrypt(std::string message);


private:
	double p;
	double q;
	double n;
	double phi;
	const double E = 7;

	std::string bytes_to_hex_string(const std::vector<uint8_t>& bytes);
	double rsa_encrypt_char(char c);
	char rsa_decrypt_char(double encrypted);
};

