#ifndef SDIZO_PROJ_2_PRIM_ALG_H
#define SDIZO_PROJ_2_PRIM_ALG_H

#include "../../graf/Graf.h"
#include "../../struct_help/que_prio/Heap.h"
#include "../../struct_help/edge/Edge.h"

#include <climits>

class Prim_alg {
public:

    explicit Prim_alg(Graf * g);
    ~Prim_alg();

    void solution_list();
    void solution_matrix();
    void display_solution();

private:

    Heap * que;
    Dym_arr<Edge> * mst;

    int * k;
    int * p;

    bool * visited;

    Graf * g;

    void creat_mst(Graf *g);

};


#endif //SDIZO_PROJ_2_PRIM_ALG_H
