#pragma once
#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <format>

// Define a namespace called Helper to organize our functions and variables
namespace Helper {
	struct DateTime; // Forward declaration of the DateTime struct
	//template <class T> // Template declaration for the ToString function
	//std::string ToString(const T&); // Declare the ToString function to convert T to a string

	// Define the DateTime struct to hold date and time information
	struct DateTime
	{
		int day, month, year, hour, minute, second;

		DateTime(); // Default constructor to initialize the date and time with the current date and time
		DateTime(int day, int month, int year, int hour, int minute, int second); // Parameterized constructor to initialize date and time components
		DateTime(int day, int month, int year); // Parameterized constructor to initialize date components (time defaults to 00:00:00)

		DateTime Now() const; // Member function to get the current date and time
		std::string GetDateString() const; // Member function to get the date as a string
		std::string GetTimeString(const std::string& sep = ":") const; // Member function to get the time as a string 
		std::string GetDateTimeString(const std::string& sep = ":") const; // Member function to get the date and time as a string
	};

	void WriteAppLog(const std::string& s); // Declare the WriteAppLog function to write a log message to a file
}


#endif // HELPER_H


