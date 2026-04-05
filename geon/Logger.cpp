#include "Logger.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace Logger {
    void log(LogLevel level, const string& message) {
        switch (level) {
        case INFO: cout << "[INFO] "; break;
        case WARNING: cout << "[WARNING] "; break;
        case ERROR: cout << "[ERROR] "; break;
        }
        cout << message << "\n";
    }

    namespace FileLogger {
        void logToFile(const string& filename, const string& message) {
            ofstream file(filename, ios::app);
            if (file.is_open()) {
                file << message << "\n";
            }
        }
    }
}
