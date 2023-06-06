#include "Prim_alg.h"

Prim_alg::Prim_alg(Graf * g) : que(new Heap) {

    this->g = g;

    k = new int [g->get_number_v()];                                      //tablica pomocnicza dróg
    p = new int [g->get_number_v()];                                      //tablica pomocnicza poprzednika dla każdego wierzchołka
    visited = new bool [g->get_number_v()];                               //zbiór wierzchołków odwiedzonych

    for(int i = 0; i < g->get_number_v(); i++) {
        k[i] = INT_MAX;
        p[i] = -1;
        visited[i] = false;
    }

    mst = new Dym_arr<Edge>();

}

Prim_alg::~Prim_alg() {

    delete que;
    delete mst;

    delete [] k;
    delete [] p;
    delete [] visited;
}

void Prim_alg::solution_list() {

    k[g->get_start_v()] = 0;                                        //oznacza, że wierzchołek startowy nie ma drogi do siebie
    p[g->get_start_v()] = -1;                                       //oznacza, że wierzchołek startowy nie ma drogi do siebie

    que->push(QueElement(k[g->get_start_v()], g->get_start_v()));


    while (!que->empty()){

        auto u = que->pop();                                    //pobieramy wierzchołek o najmniejszym kluczu

        if(visited[u]) continue;                                         //jeśli dany wierzchołek jest rozwarzony to go pomijamy

        auto adj = g->get_adj(u)->get_list();         //pobieramy jego listę sąsiedztwa
        auto size = g->get_adj(u)->get_size();              //pobieramy jej rozmiar

        for(int i = 0; i < size; i++){

            int v = adj[i].neighbor;                                //przypisujemy sąsiada

            if(visited[v]) continue;                                    //jeśli dany wierzchołek jest rozwarzony to go pomijamy

            int w = adj[i].path;                                    //przypisujemy wagę danej krawędzi

            if(w < k[v]){                                            //sprawdzmy warunek wielkości ścierzek
                                                                        //aktualizujemy dane i dodajemy do kolejki
                k[v] = w;
                p[v] = u;
                que->push(QueElement(w, v));

            }

        }

        visited[u] = true;                                              //wierzchołek został rozpatrzony
    }

    creat_mst(g);

}

void Prim_alg::display_solution() {

    mst->quick_sort_edges(0, mst->get_size() - 1);

    int mst_sum = 0;

    std::cout<<"Prim alg"<<std::endl;
    std::cout<<"Edge          "<< "Weight"<<std::endl;

    for(int i = 0; i < mst->get_size(); i++) {
        std::cout << "(" << mst->get_value(i)->get_u() << "," << mst->get_value(i)->get_v() << ")     ->     " << mst->get_value(i)->get_w() << std::endl;
        mst_sum += mst->get_value(i)->get_w();
    }

    std::cout<<"MST: " << mst_sum << std::endl;

}

void Prim_alg::solution_matrix() {

    que->push(QueElement(0, g->get_start_v()));     //dodajemy wierzchołek startowy do kolejki bo odniego zaczniemy rozwarzania

    int u;                                                         //zmienne pomocnicze przy alg -> wierzchołek obecny i jego sąsiad

    while (!que->empty()){

        u = que->pop();                                //pobieramy wierzchołek o najmniejszym kluczu

        if(visited[u]) continue;                               //jeśli dany wierzchołek jest rozwarzony to go pomijamy

        for(int v = 0; v < g->get_number_v(); v++){

            if(visited[v]) continue;                            //jeśli dany wierzchołek jest rozwarzony to go pomijamy

            int w = g->get_matrix(u,v);                     //pobieramy wagę każdej krawędzi
            if( w == 0) continue;                           //jeśli nie ma połączenia to pomijamy rowarzanego sąsiada

            if(w < k[v]){

                p[v] = u;
                k[v] = w;
                que->push(QueElement(w, v));

            }

        }

        visited[u] = true;

    }

    creat_mst(g);

}

void Prim_alg::creat_mst(Graf *g) {
    for(int i = 0; i < g->get_number_v(); i++)
        if(k[i] < INT_MAX && k[i] > 0)
            mst->add_back(Edge(p[i],i,k[i]));
}