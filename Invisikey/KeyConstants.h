// This is a header file that defines a class and a map of key codes to key pairs.

#pragma once
#ifndef KEY_CONSTANTS_H
#define KEY_CONSTANTS_H

#include <map>
#include <string>

// Define a class called KeyPair to hold a key code and a key name.
class KeyPair
{
	public:
		// Constructor to initialize a KeyPair object with a VK name and a key name.
		KeyPair(const std::string &vk = "", const std::string &name = "") : VKName (vk), Name(name) {}

		// Member variables to hold the VK name and key name.
		std::string VKName;
		std::string Name;
};

// Define a class called Keys to hold a map of key codes to key pairs.
class Keys
{
	public:
		static std::map<int, KeyPair> KEYS;
};

#endif