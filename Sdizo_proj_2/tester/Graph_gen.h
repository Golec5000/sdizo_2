#ifndef SDIZO_PROJ_2_GRAPH_GEN_H
#define SDIZO_PROJ_2_GRAPH_GEN_H

#include <random>
#include <iostream>

#include "../graf/Graf.h"
#include "../struct_help/edge/Edge.h"

class Graph_gen {

public:

    Graf * generate(int size, bool directed, float density, bool not_negative, int start_v, int end_v);

private:

    std::vector<Edge> all_combinations(int max_v, bool directed,int max_e , bool not_negative);
    std::vector<Edge> random_edges(int max_v, int edges_count, int max_num_of_edges, bool directed, bool not_negative);
    std::vector<Edge> ensures_conections(std::vector<Edge>& all_edges, int max_v);

    std::vector<std::vector<int>> final_data (int size_v,int size_e, int start_v, int end_v, std::vector<Edge> &combinatios);

    std::vector<int> radom_num_gen(int num, int min, int max);

    int min(int num1, int num2);

};


#endif //SDIZO_PROJ_2_GRAPH_GEN_H
