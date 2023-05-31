#ifndef SDIZO_PROJ_2_FORD_BELL_ALG_H
#define SDIZO_PROJ_2_FORD_BELL_ALG_H


#include "../../graf/Graf.h"
#include "../../struct_help/que_prio/Que.h"

class Ford_bell_alg {

public:

    Ford_bell_alg(Graf * g);
    ~Ford_bell_alg();

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


#endif //SDIZO_PROJ_2_FORD_BELL_ALG_H
