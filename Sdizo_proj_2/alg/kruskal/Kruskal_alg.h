#ifndef SDIZO_PROJ_2_KRUSKAL_ALG_H
#define SDIZO_PROJ_2_KRUSKAL_ALG_H

#include "../../struct_help/edge/Edge.h"


class Kruskal_alg {
public:
    Kruskal_alg();
    ~Kruskal_alg();
    void solution();
private:
    void make_set();
    void find_set();
    void union_set();
    Edge * edges;
};


#endif //SDIZO_PROJ_2_KRUSKAL_ALG_H
