#ifndef SDIZO_PROJ_2_ADJLIST_H
#define SDIZO_PROJ_2_ADJLIST_H


#include "AdjNode.h"
#include <iomanip>
#include <iostream>

class AdjList {
public:

    AdjList();
    ~AdjList();

    void display();
    void add(int path, int neighbor);

    int get_size();
    AdjNode * get_list();

private:

    AdjNode * head;
    int size;

};


#endif //SDIZO_PROJ_2_ADJLIST_H
