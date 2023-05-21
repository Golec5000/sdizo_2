#include <iostream>
#include "../file_oi/FileReader.h"
#include "../graf/Graf.h"
#include "../alg/prim/Prim_alg.h"
#include "../alg/kruskal/Kruskal_alg.h"

int main() {

    std::string path = "..//data//";
    std::string file_name = "test4.txt";

    FileReader fileReader;

     auto * g = new Graf(fileReader.readNumbers(path+file_name), false);

     g->display();

     auto * prim = new Prim_alg();

     prim->solution(g);

     auto * kruskal = new Kruskal_alg();


}
