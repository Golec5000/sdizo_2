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
    void add(int num);
    bool find_key(int num);
    int get_size();
    int * get_list();
private:
    AdjNode * head;
    int size;
};


#endif //SDIZO_PROJ_2_ADJLIST_H
