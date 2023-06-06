#ifndef SDIZO_PROJ_2_FORD_BELL_ALG_H
#define SDIZO_PROJ_2_FORD_BELL_ALG_H


#include "../../graf/Graf.h"
#include "../../struct_help/que_prio/Heap.h"

class Ford_bell_alg {

public:

    explicit Ford_bell_alg(Graf * g);
    ~Ford_bell_alg();

    void solution_matrix();
    void solution_list();
    void display_solution();

private:

    int * prev;
    int * path;

    bool * visited;

    bool non_neg_cycle;

    Graf * g;

    int num_v;
    int start_v;

    void path_of_v(int v);

};


#endif //SDIZO_PROJ_2_FORD_BELL_ALG_H
