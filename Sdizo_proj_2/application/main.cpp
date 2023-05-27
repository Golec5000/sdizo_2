#include <iostream>

#include "../file_oi/FileReader.h"
#include "../graf/Graf.h"

#include "../alg/prim/Prim_alg.h"
#include "../alg/kruskal/Kruskal_alg.h"
#include "../alg/dikjstra/Dijkstra_alg.h"

int main() {

    std::string path = "..//data//";
    std::string file_name = "test2.txt";

    FileReader fileReader;

     auto * g = new Graf(fileReader.readNumbers(path+file_name), true);
     g->display();

     auto prim = new Prim_alg(g->get_number_v());
     //prim->solution(g);
     //prim->display_solution(g);

     auto kruskal = new Kruskal_alg(g,fileReader.readNumbers(path + file_name));

     //kruskal->solution();
     //kruskal->display_solution();


     auto dijkstra = new Dijkstra_alg(g);

     dijkstra->solution(g);
     dijkstra->display_solution();

     delete g;

     delete prim;
     delete kruskal;
     delete dijkstra;


}
