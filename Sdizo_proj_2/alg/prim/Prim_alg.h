#ifndef SDIZO_PROJ_2_PRIM_ALG_H
#define SDIZO_PROJ_2_PRIM_ALG_H

#include "../../graf/Graf.h"
#include "../../struct_help/que_prio/Que.h"

#include <climits>

class Prim_alg {
public:

    Prim_alg(int number_of_v);
    ~Prim_alg();

    void solution(Graf * g);
    void display_solution(Graf * g);

private:

    Que * que;

    int * k;
    int * p;

    bool * zwr;

};


#endif //SDIZO_PROJ_2_PRIM_ALG_H
