#ifndef SDIZO_PROJ_2_KRUSKAL_ALG_H
#define SDIZO_PROJ_2_KRUSKAL_ALG_H

#include "../../struct_help/edge/Edge.h"
#include "../../graf/Graf.h"
#include "../../struct_help/dym_arr/Dym_arr.h"
#include "../../struct_help/set_krus/Dataset.h"

class Kruskal_alg {
public:

    Kruskal_alg(Graf * g);
    ~Kruskal_alg();

    void solution_matrix();
    void solution_list();
    void display_solution();

private:

    void make_set();
    int find_set(int v);
    void union_set(Edge e);

    Dym_arr <Edge> * edges;
    Dym_arr <Edge> * mst;

    Dataset * dataset;

    Graf * g;

    int num_of_v;

};


#endif //SDIZO_PROJ_2_KRUSKAL_ALG_H
