#ifndef SDIZO_PROJ_2_PRIM_ALG_H
#define SDIZO_PROJ_2_PRIM_ALG_H

#include "../../graf/Graf.h"
#include "../../struct_help/que_prio/Que.h"
#include <limits>

class Prim_alg {
public:
    Prim_alg();
    ~Prim_alg();
    void solution(Graf * g);
private:
    Que * que;
};


#endif //SDIZO_PROJ_2_PRIM_ALG_H
