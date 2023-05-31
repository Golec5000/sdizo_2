#include "Ford_bell_alg.h"

Ford_bell_alg::Ford_bell_alg(Graf *g) : que(new Que), num_v(g->get_number_v()), start_v(g->get_start_v()){

    path = new int [num_v];
    prev = new int [num_v];
    visited = new bool [num_v];

    for(int i = 0; i < num_v; i++){

        path[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;

    }

}

Ford_bell_alg::~Ford_bell_alg() {

    delete [] path;
    delete [] prev;

    delete [] visited;

    delete que;

}

void Ford_bell_alg::solution(Graf *g) {

}

void Ford_bell_alg::display_solution() {

}

void Ford_bell_alg::path_of_v(int v) {

}
