#pragma once
#include <string>

using namespace std;

namespace Logger {
    enum LogLevel { INFO, WARNING, ERROR };

    void log(LogLevel level, const string& message);

    namespace FileLogger {
        void logToFile(const string& filename, const string& message);
    }
}

