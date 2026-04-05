#include <iostream>
#include "Logger.h"

using namespace std;

int main() {
    using namespace Logger;

    log(INFO, "Application started");
    log(WARNING, "Low memory");
    log(ERROR, "Crash detected");

    FileLogger::logToFile("log.txt", "File log message");

    return 0;
}