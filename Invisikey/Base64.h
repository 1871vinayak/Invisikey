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
    inline constexpr std::string_view SALT1 = "LM::TB::BB";
    inline constexpr std::string_view SALT2 = "_:/_77";
    inline constexpr std::string_view SALT3 = "line=boostedC++";
    inline constexpr std::string_view BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
}

#endif // BASE64_H


