#include "Crypto_Manager.h"

#include <cmath>

#include <sstream>
#include <iomanip>

#include <openssl/evp.h>
#include <openssl/sha.h>

#include "Utils.h"

std::string Crypto_Manager::bytes_to_hex_string(const std::vector<uint8_t>& bytes)
{
    std::ostringstream stream;
    for (uint8_t b : bytes)
    {
        stream << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(b);
    }
    return stream.str();
}

std::string Crypto_Manager::get_sha3_512_hash(std::string input)
{
    uint32_t digest_length = SHA512_DIGEST_LENGTH;
    const EVP_MD* algorithm = EVP_sha3_512();
    uint8_t* digest = static_cast<uint8_t*>(OPENSSL_malloc(digest_length));
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, algorithm, nullptr);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, digest, &digest_length);
    EVP_MD_CTX_destroy(context);
    std::string output = Crypto_Manager::bytes_to_hex_string(std::vector<uint8_t>(digest, digest + digest_length));
    OPENSSL_free(digest);
    return output;
}

double Crypto_Manager::rsa_encrypt_char(char c)
{
    double message = static_cast<double>(c);
    double encrypted = pow(message, Crypto_Manager::E);
    //encrypted = fmod(encrypted, Crypto_Manager::N);
    return encrypted;
}

char Crypto_Manager::rsa_decrypt_char(double encrypted)
{
    double d1 = 1 / Crypto_Manager::E;
    double d = fmod(d1, Crypto_Manager::PHI);
    double decrypted = pow(encrypted, d);
    decrypted = fmod(decrypted, Crypto_Manager::N);
    char c = static_cast<char>(round(decrypted));
    return c;
}
