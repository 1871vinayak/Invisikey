#include "Base64.h"

namespace Base64 
{
	/**
	 * @brief Encode a string using the base64 algorithm.
	 *
	 * This function takes a string as input, converts each character to its ASCII value,
	 * and then represents each value as a 6-bit binary number. The resulting binary
	 * numbers are then grouped into 4-character blocks, with padding added as necessary.
	 *
	 * @param str The string to encode.
	 * @return The encoded string.
	 */
	std::string base64_encode(const std::string& str)
	{
		std::string enStr; // The encoded string
		int value = 0; // The current value being processed
		int bits = -6; // The number of bits in the current block
		const unsigned int b63 = 0x3F; // The maximum value for a 6-bit binary number

		// Iterate over each character in the input string
		for (const auto& ch : str)
		{
			value = (value << 8) + ch; // Convert the character to its ASCII value and add it to the current value
			bits += 8; // Increment the number of bits in the current block

			// While there are enough bits to form a complete block
			while(bits >= 0)
			{
				// Extract the next 6-bit block from the current value
				enStr.push_back(BASE64_CODES[(value >> bits) & b63]);
				bits -= 6; // Decrement the number of bits in the current block
			}
		}

		// If there are any remaining bits, add padding as necessary
		if (bits > -6)
			enStr.push_back(BASE64_CODES[((value << 8) >> (bits + 8)) & b63]);
		
		// Add padding to the end of the encoded string as necessary
		while (enStr.size() % 4)
			enStr.push_back('=');

		return enStr; // Return the encoded string
	}

	/**
	 * @brief Encrypt a string using a triple base64 encoding with modifications.
	 *
	 * This function takes a string as input, adds salt values to the beginning and end,
	 * and then applies the base64 encoding algorithm three times with modifications.
	 *
	 * @param str The string to encrypt.
	 * @return The encrypted string.
	 */
	std::string encrypt_base64(std::string str)
	{
		str = std::string(SALT1) + str + std::string(SALT2) + std::string(SALT3); // Add salt values to the beginning and end of the input string
		str = base64_encode(str); // Apply the base64 encoding algorithm for the first time
		str.insert(7, std::string(SALT3)); // Insert the third salt value at position 7
		str += SALT1;
		str = base64_encode(str);
		str = std::string(SALT2) + std::string(SALT3) + str + std::string(SALT1);
		str = base64_encode(str);
		str.insert(1, "L");
		str.insert(7, "M");
		return str;
	}
}