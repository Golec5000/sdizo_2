#ifndef SDIZO_PROJ_2_DIJKSTRA_ALG_H
#define SDIZO_PROJ_2_DIJKSTRA_ALG_H

#include <climits>
#include <iostream>

#include "../../graf/Graf.h"
#include "../../struct_help/que_prio/Heap.h"

class Dijkstra_alg {

public:

    explicit Dijkstra_alg(Graf * g);
    ~Dijkstra_alg();

    void solution_matrix();
    void solution_list();
    void display_solution();

private:

    int * prev;
    int * path;

    bool * visited;

    int num_v;
    int start_v;

    Heap * que;

    Graf * g;

    void path_of_v(int v);

};


#endif //SDIZO_PROJ_2_DIJKSTRA_ALG_H
