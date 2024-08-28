#pragma once
#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include "Helper.h"
#include "Base64.h"

namespace IO
{
    /**
     * @brief Returns the path to the application's data directory.
     *
     * @param append_separator Whether to append a directory separator at the end of the path.
     * @return The path to the application's data directory.
     */
    std::string getOurPath(const bool append_separator = false);

    /**
     * @brief Creates a single directory.
     *
     * @param path The path to the directory to create.
     * @return True if the directory was created successfully, false otherwise.
     */
    bool mkOneDir(const std::string& path);

    /**
     * @brief Creates a directory and all its parents if they do not exist.
     *
     * @param path The path to the directory to create.
     * @return True if the directory was created successfully, false otherwise.
     */
    bool mkDir(const std::string& path);

    /**
     * @brief Writes a log entry to a file.
     *
     * @tparam T The type of the log entry.
     * @param t The log entry to write.
     * @return The name of the log file.
     */
    template <class T>
    std::string writeLog(const T& t);
}


#endif // IO_H
