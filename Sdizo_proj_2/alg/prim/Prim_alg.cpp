#include "Prim_alg.h"

Prim_alg::Prim_alg(int number_of_v) : que(new Que) {

    k = new int [number_of_v];             //tablica dróg
    p = new int [number_of_v];             //tablica poprzednika dla każdego wierzchołka
    zwr = new bool [number_of_v];            //zbiór wierzchołków odwiedzonych

}

Prim_alg::~Prim_alg() {
    delete que;
    delete [] k;
    delete [] p;
    delete [] zwr;
}

void Prim_alg::solution(Graf * g) {

    for(int i = 0; i < g->get_number_v(); i++) {
        k[i] = INT_MAX;
        p[i] = INT_MAX;
        zwr[i] = false;
    }

    k[g->get_start_v()] = 0;                                 //oznacza, że wierzchołek startowy nie ma drogi do siebie
    p[g->get_start_v()] = -1;                                // oznacza to, że wierzchołek startowy nie ma poprzednika
    zwr[g->get_start_v()] = true;                       //wierzchołek startowy znajduje się w zbiorze wierzchołków rozpatrzonych

    for(int i = 0; i < g->get_number_v(); i++)              //dodajemy wszystkie wierzchołki do kolejki
        que->push(k[i], i);

    while (!que->empty()){

        auto u = que->pop();                            //pobieramy wierzchołek o najmniejszym kluczu
        auto adj = g->get_adj(u)->get_list();     //pobieramy jego listę sąsiedztwa
        auto size = g->get_adj(u)->get_size();     //pobieramy jej rozmiar


        for(int i = 0; i < size; i++){

            auto v = adj[i];                            //przypisujemy po koleji sąsiadów u
            auto w = g->get_matrix(u,v);                //pobieramy wagę danej krawędzi

            if(!zwr[v] && w < k[v]){                        //sprawdzamy wczy wierzchołek nie jest jeszcze rozważony
                                                            // i czy waga krawędzi jest minimalna
                k[v] = w;
                p[v] = u;

            }

        }

        zwr[u] = true;                                  //wierzchołek został rozpatrzony
    }


}

void Prim_alg::display_solution(Graf * g) {

    int mst = 0;

    std::cout<<"Prim alg"<<std::endl;
    std::cout<<"Edge          "<< "Weight"<<std::endl;

    for(int i = 0; i < g->get_number_v(); i++)
        if (k[i] < INT_MAX && k[i] > 0) {
            std::cout << "(" << p[i] << "," << i << ")     ->     " << k[i] << std::endl;
            mst += k[i];
        }
    std::cout<<"MST: " << mst << std::endl;
}
