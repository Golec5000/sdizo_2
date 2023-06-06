#include "Dijkstra_alg.h"

Dijkstra_alg::Dijkstra_alg(Graf * g) :  num_v(g->get_number_v()), start_v(g->get_start_v()), que(new Heap){

    this->g = g;

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

void Dijkstra_alg::solution_list() {

    path[start_v] = 0;                                                      //wierzchołek startowy nie ma do siebie drogi

    que->push(QueElement(path[start_v], start_v));    //wprowadzamy wirzchołek startowy do kolejki jako pierwszy do rozpatrzenia

    while (!que->empty()){

        auto u = que->pop();
        if(visited[u]) continue;

        auto adj = g->get_adj(u)->get_list();
        auto size = g->get_adj(u)->get_size();

        if(size == 0) continue;

        for(int i = 0; i < size; i++){

            int v = adj[i].neighbor;

            if(visited[v]) continue;

            int tmp_path = path[u] + adj[i].path;

            if(path[v] > tmp_path){

                path[v] = tmp_path;
                prev[v] = u;
                que->push(QueElement(tmp_path,v));

            }

        }

        visited[u] = true;

    }

}

void Dijkstra_alg::solution_matrix() {

    path[start_v] = 0;                                                              //wierzchołek startowy nie ma do siebie drogi

    que->push(QueElement(path[start_v], start_v));              //wprowadzamy wirzchołek startowy do kolejki jako pierwszy do rozpatrzenia

    while (!que->empty()){

        auto u = que->pop();
        if(visited[u]) continue;

        for(int v = 0; v < g->get_number_v(); v++){

            if(visited[v]) continue;
            auto w = g->get_matrix(u,v);                                        //pobieramy wagę danej krawędzi

            if(w == 0) continue;                                                    //jeśli nie ma połaczenia to pomijamy
            auto tmp_path = path[u] + w;                                        //tworzymy tymczasową wartość nowej ścierzki

            if(!visited[v] && path[v] > tmp_path){                                  //sprawdzamy warunek relaksacji

                path[v] = tmp_path;                                                 //aktualizujemy koszt dojścia
                prev[v] = u;                                                        //aktualizujemy poprzednika

                que->push(QueElement(tmp_path,v));              //wprowadzamy do kolejki

            }

        }

        visited[u] = true;                                                          //oznaczamy wierzchołek jako rozpatrzony

    }

}

void Dijkstra_alg::display_solution() {

    std::cout<< "Start = " << start_v << std::endl;
    std::cout << " End   " << "           Cost  " << "              Path   " << std::endl;

    for(int i = 0; i < num_v; i++){
        if(path[i] != INT_MAX)
            std::cout<< std::setw(3) << i << std::setw(3)<< "      |       " << std::setw(3)<<path[i] << "      |   "<<std::setw(3);
        else
            std::cout << i <<"       |       "<<"INF" << "      |   ";
        path_of_v(i);
        std::cout << i;
        std::cout << std::endl;
    }


}

void Dijkstra_alg::path_of_v(int v) {

    if(prev[v] != -1 ) path_of_v(prev[v]);
    if(prev[v] != -1)  std::cout << prev[v] << "   ";

}