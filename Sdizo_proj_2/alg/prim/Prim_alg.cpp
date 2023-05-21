#include "Prim_alg.h"

Prim_alg::Prim_alg() : que(new Que) {}

Prim_alg::~Prim_alg() {
    delete que;
}

void Prim_alg::solution(Graf * g) {

    auto k = new long long [g->get_number_v()];   //tablica dróg
    auto p = new long long [g->get_number_v()];   //tablica poprzednika dla każdego wierzchołka
    auto visited = new bool [g->get_number_v()];  //zbiór wierzchołków odwiedzonych

    for(int i = 0; i < g->get_number_v(); i++) {
        k[i] = LONG_LONG_MAX;
        p[i] = LONG_LONG_MAX;
        visited[i] = false;
    }

    k[g->get_start_v()] = 0;    //oznacza, że wierzchołek startowy nie ma drogi do siebie
    p[g->get_start_v()] = -1;   // oznacza to, że wierzchołek startowy nie ma poprzednika
    visited[g->get_start_v()] = true;   //wierzchołek startowy znajduje się w zbiorze wierzchołków rozpatrzonych

    for(int i = 0; i < g->get_number_v(); i++)  //dodajemy wszystkie wierzchołki do kolejki
        que->push(k[i], i);

    while (!que->empty()){

        auto u = que->pop();    //pobieramy wierzchołek o najmniejszym kluczu
        auto adj = g->get_adj(u)->get_list();     //pobieramy jego listę sąsiedztwa
        auto size = g->get_adj(u)->get_size();        //pobieramy jej rozmiar

//        std::cout << u << std::endl;
//        for (int i = 0; i < size; ++i) {
//            std::cout << adj[i];
//        }
//        std::cout<<std::endl;

        for(int i = 0; i < size; i++){

            auto v = adj[i];
            auto w = g->get_matrix(u,v);
            if(!visited[v] && w < k[v]){

                k[v] = w;
                p[v] = u;
                visited[v] = true;
            }

        }

    }

    long long mst = 0;

    std::cout<<"Prim alg"<<std::endl;
    std::cout<<"Edge          "<< "Weight"<<std::endl;

    for(int i = 0; i < g->get_number_v(); i++)
        if (k[i] != LONG_LONG_MAX && k[i] != 0) {
            std::cout << "(" << p[i] << "," << i << ")     ->     " << k[i] << std::endl;
            mst += k[i];
        }
    std::cout<<"MST: " << mst << std::endl;

    delete [] k;
    delete [] p;
    delete [] visited;

}
