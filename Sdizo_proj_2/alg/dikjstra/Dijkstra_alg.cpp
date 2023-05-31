#include "Dijkstra_alg.h"

Dijkstra_alg::Dijkstra_alg(Graf * g) : que(new Que), num_v(g->get_number_v()), start_v(g->get_start_v()){

    path = new int [num_v];
    prev = new int [num_v];
    visited = new bool [num_v];

    for(int i = 0; i < num_v; i++){

        path[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;

    }

}

Dijkstra_alg::~Dijkstra_alg() {

    delete [] path;
    delete [] prev;

    delete [] visited;

    delete que;

}

void Dijkstra_alg::solution(Graf *g) {

    path[start_v] = 0;                                      //wierzchołek startowy nie ma do siebie drogi
    prev[start_v] = -1;                                     //wierzchołek startowy nie ma poprzednika

    que->push(path[start_v], start_v);              //wprowadzamy wirzchołek startowy do kolejki jako pierwszy do rozpatrzenia

    while (!que->empty()){

        auto u = que->pop();
        auto adj = g->get_adj(u)->get_list();     //pobieramy jego listę sąsiedztwa
        auto size = g->get_adj(u)->get_size();     //pobieramy jej rozmiar

        for(int i = 0; i < size; i++){

            auto v = adj[i];                            //przypisujemy po koleji sąsiadów u
            auto w = g->get_matrix(u,v);                //pobieramy wagę danej krawędzi
            auto tmp_path = path[u] + w;                //tworzymy tymczasową wartość nowej ścierzki

            if(!visited[v] && path[v] > tmp_path){          //sprawdzamy warunek relaksacji

                path[v] = tmp_path;                         //aktualizujemy koszt dojścia
                prev[v] = u;                                //aktualizujemy poprzednika

                que->push(tmp_path,v);              //wprowadzamy do kolejki

            }

        }

        visited[u] = true;                                  //oznaczamy wierzchołek jako rozpatrzony

    }

}

void Dijkstra_alg::display_solution() {

    std::cout<< "Start = " << start_v << std::endl;
    std::cout << "End " << "           Cost  " << "        Path   " << std::endl;

    for(int i = 0; i < num_v; i++){
        std::cout << i <<"       |       "<< path[i] << "      |   ";
        path_of_v(i);
        std::cout << i;
        std::cout << std::endl;
    }


}

void Dijkstra_alg::path_of_v(int v) {

    if(prev[v] != -1 ) path_of_v(prev[v]);
    if(prev[v] != -1)  std::cout << prev[v] << "   ";

}
