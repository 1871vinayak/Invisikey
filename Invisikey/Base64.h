#pragma once
#ifndef BASE64_H
#define BASE64_H

#include <string>
#include <vector>

namespace Base64
{
    /**
     * @brief Encode a string using the base64 algorithm.
     *
     * @param str The string to encode.
     * @return The encoded string.
     */
    std::string base64_encode(const std::string& str);

    /**
     * @brief Encrypt a string using a triple base64 encoding with modifications.
     *
     * @param str The string to encrypt.
     * @return The encrypted string.
     */
    std::string encrypt_base64(std::string str);

    //Constants
    const std::string& SALT1 = "LM::TB::BB";
	const std::string& SALT2 = "_:/_77";
    const std::string& SALT3 = "line=boostedC++";
    const std::string& BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
}

#endif // BASE64_H


