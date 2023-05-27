#ifndef SDIZO_PROJ_2_KRUSKAL_ALG_H
#define SDIZO_PROJ_2_KRUSKAL_ALG_H

#include "../../struct_help/edge/Edge.h"
#include "../../graf/Graf.h"
#include <vector>

class Kruskal_alg {
public:

    Kruskal_alg(Graf * g, std::vector<std::vector<int>> tmp);
    ~Kruskal_alg();

    void solution();
    void display_solution();

private:

    void make_set();
    int find_set(int v);
    void union_set(int u, int v);
    void quick_sort(int left, int right);
    void add_edge_to_ans(Edge * edge);

    Edge ** edges;
    Edge ** ans;

    int num_of_edges;
    int num_of_v;
    int * group;
    int ans_size;

};


#endif //SDIZO_PROJ_2_KRUSKAL_ALG_H
