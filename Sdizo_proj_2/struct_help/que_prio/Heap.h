#ifndef SDIZO_PROJ_2_HEAP_H
#define SDIZO_PROJ_2_HEAP_H


#include "../dym_arr/Dym_arr.h"
#include "QueElement.h"
#include <iomanip>
#include <iostream>

class Heap {

public:

    Heap();
    ~Heap();

    void push(QueElement new_element);
    int pop();
    int get_size();
    bool empty();


private:

    Dym_arr<QueElement> * heap;

    void repair_heap_up(int index);
    void repair_heap_down(int index);

    int parent_index(int index);
    int left_child_index(int index);
    int right_child_index(int index);

    QueElement * get_left_child(int index);
    QueElement * get_right_child(int index);
    int get_min_index_child(int index);


};


#endif //SDIZO_PROJ_2_HEAP_H
