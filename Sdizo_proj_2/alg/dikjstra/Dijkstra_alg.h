#ifndef SDIZO_PROJ_2_DIJKSTRA_ALG_H
#define SDIZO_PROJ_2_DIJKSTRA_ALG_H

#include <climits>
#include <iostream>

#include "../../struct_help/que_prio/Que.h"
#include "../../graf/Graf.h"

class Dijkstra_alg {

public:

    Dijkstra_alg(Graf * g);
    ~Dijkstra_alg();

    void solution(Graf * g);
    void display_solution();

private:

    int * prev;
    int * path;

    bool * visited;

    int num_v;
    int start_v;

    Que * que;

    void path_of_v(int v);

};


#endif //SDIZO_PROJ_2_DIJKSTRA_ALG_H
