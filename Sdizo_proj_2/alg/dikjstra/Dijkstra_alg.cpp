#include "Dijkstra_alg.h"

Dijkstra_alg::Dijkstra_alg(Graf * g) : que(new Que), num_v(g->get_number_v()){

    path = new int [num_v];
    prev = new int [num_v];
    visited = new bool [num_v];

}

Dijkstra_alg::~Dijkstra_alg() {

    delete [] path;
    delete [] prev;

    delete [] visited;

    delete que;

}

void Dijkstra_alg::solution(Graf *g) {


    for(int i = 0; i < num_v; i++){

        path[i] = INT_MAX;
        prev[i] = INT_MAX;
        visited[i] = false;

    }

    path[g->get_start_v()] = 0;     //wierzchołek startowy nie ma do siebie drogi
    prev[g->get_start_v()] = -1;    //wierzchołek startowy nie ma poprzednika

    for(int i = 0; i < num_v; i++){
        que->push(path[i], i );
    }

    while (!que->empty()){

        auto u = que->pop();                            //pobieramy wierzchołek o najmniejszym kluczu
        auto adj = g->get_adj(u)->get_list();     //pobieramy jego listę sąsiedztwa
        auto size = g->get_adj(u)->get_size();     //pobieramy jej rozmiar

        visited[u] = true;

        for(int i = 0; i < size; i++){

            auto v = adj[i];                            //przypisujemy po kolei sąsiadów u
            auto w = g->get_matrix(u,v);                //pobieramy wagę danej krawędzi

            if( !visited[v] && path[v] > path[u] + w){

                path[v] = path[u] + w;
                prev[v] = u;

            }

        }



    }

}

void Dijkstra_alg::display_solution() {

    for(int i = 0; i < num_v; i++){





    }


}
