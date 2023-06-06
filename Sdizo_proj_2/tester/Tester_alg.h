#ifndef SDIZO_PROJ_2_TESTER_ALG_H
#define SDIZO_PROJ_2_TESTER_ALG_H


#include "../alg/prim/Prim_alg.h"
#include "../alg/kruskal/Kruskal_alg.h"
#include "../alg/dikjstra/Dijkstra_alg.h"
#include "../alg/ford_bell/Ford_bell_alg.h"
#include "Graph_gen.h"
#include "../time_watch/TimeWatch.h"
#include "../file_oi/FileWriter.h"
#include <vector>

class Tester_alg {

public:

    void test_alg(int chose,int size,float density, std::string type);

private:

    Prim_alg * prim;
    Kruskal_alg * kruskal;
    Dijkstra_alg * dijkstra;
    Ford_bell_alg * ford_bell;
    Graf * g;

    Graph_gen gen_graph;
    TimeWatch timer;
    FileWriter writer;

    void test_prim_matrix(int size, float density);
    void test_kruskal_matrix(int size, float density);
    void test_dijkstra_matrix(int size, float density);
    void test_bell_ford_matrix(int size, float density);

    void test_prim_list(int size, float density);
    void test_kruskal_list(int size, float density);
    void test_dijkstra_list(int size, float density);
    void test_bell_ford_list(int size, float density);

};


#endif //SDIZO_PROJ_2_TESTER_ALG_H
