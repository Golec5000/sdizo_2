#ifndef SDIZO_PROJ_2_DYM_ARR_H
#define SDIZO_PROJ_2_DYM_ARR_H

#include <cstring>
#include <iostream>

template <typename T> class Dym_arr {

public:

    Dym_arr();
    ~Dym_arr();
    void swap(unsigned index1, unsigned index2);
    int get_size();
    T* get_value(unsigned index);

    void add_front(T value);
    void add_back(T value);
    void pop_front();
    void pop_back();

    void display_ints();
    void display_edges();
    void display_nodes();

    void quick_sort_edges(unsigned left, unsigned right);

private:



    T* tab;
    int size;


};




#endif //SDIZO_PROJ_2_DYM_ARR_H
