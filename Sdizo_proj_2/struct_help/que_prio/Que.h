#ifndef SDIZO_PROJ_2_QUE_H
#define SDIZO_PROJ_2_QUE_H

#include "QueNode.h"
#include <iostream>

class Que {
public:
    Que();
    ~Que();
    void push(int prio, int key);
    int pop();
    bool empty();
    bool contains(int key);
    void display();
private:
    QueNode * head;
    QueNode * tail;
};


#endif //SDIZO_PROJ_2_QUE_H
