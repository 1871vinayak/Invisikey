#include "Helper.h"

Helper::DateTime::DateTime()
{
	time_t ms;
	time(&ms);

	//struct tm* info = localtime(&ms);

	struct tm info;
	if (localtime_s(&info, &ms) != 0) {
		// Handle error: unable to get local time
		// For example, you can throw an exception or return an error code
		//throw std::runtime_error("Failed to get local time");
	}

	day = info.tm_mday;
	month = info.tm_mon + 1;
	year = info.tm_year + 1900;
	hour = info.tm_hour;
	minute = info.tm_min;
	second = info.tm_sec;
}

Helper::DateTime::DateTime(int day, int month, int year, int hour, int minute, int second)
	: day(day), month(month), year(year), hour(hour), minute(minute), second(second) {}

Helper::DateTime::DateTime(int day, int month, int year)
	: day(day), month(month), year(year), hour(0), minute(0), second(0) {}

Helper::DateTime Helper::DateTime::Now() const
{
	return Helper::DateTime();
}

std::string Helper::DateTime::GetDateString() const
{
	return std::format("{:02}.{:02}:{:04}", day, month, year);
}

std::string Helper::DateTime::GetTimeString() const 
{
	return std::format("{:02}:{:02}:{:02}", hour, minute, second);
}

std::string Helper::DateTime::GetDateTimeString() const
{
	return GetDateString() + " " + GetTimeString();
}

// Define the WriteAppLog() function
void Helper::WriteAppLog(const std::string& s)
{
	std::ofstream file("AppLog.txt", std::ios::app);
	// Write the log message with a timestamp
	file << "[" << Helper::DateTime().GetDateTimeString() << "] " << "\n" << s << std::endl << "\n";
	file.close();
}