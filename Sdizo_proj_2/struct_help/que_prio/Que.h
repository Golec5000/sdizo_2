#ifndef SDIZO_PROJ_2_QUE_H
#define SDIZO_PROJ_2_QUE_H

#include "QueNode.h"
#include <limits>

class Que {
public:
    Que();
    ~Que();
    void push(long long prio, int key);
    int pop();
    bool empty();
    bool contains(int key);
private:
    QueNode * head;
    QueNode * tail;
};


#endif //SDIZO_PROJ_2_QUE_H
