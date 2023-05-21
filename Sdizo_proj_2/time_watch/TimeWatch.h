#ifndef SDIZO_PROJ_V1_TIMEWATCH_H
#define SDIZO_PROJ_V1_TIMEWATCH_H

#include <chrono>

class TimeWatch {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
public:
    void startStopwatch();
    long long int stopStopwatch();

};


#endif //SDIZO_PROJ_V1_TIMEWATCH_H
