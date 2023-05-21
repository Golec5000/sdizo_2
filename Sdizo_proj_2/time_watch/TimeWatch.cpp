#include "TimeWatch.h"

void TimeWatch::startStopwatch() {
    start = std::chrono::high_resolution_clock::now();
}

long long int TimeWatch::stopStopwatch() {
    stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(TimeWatch::stop - TimeWatch::start).count();
}
