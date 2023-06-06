#include "Ford_bell_alg.h"

Ford_bell_alg::Ford_bell_alg(Graf *g) :  num_v(g->get_number_v()), start_v(g->get_start_v()){

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

Ford_bell_alg::~Ford_bell_alg() {

    delete [] path;
    delete [] prev;

    delete [] visited;

}

void Ford_bell_alg::solution_matrix() {


    path[start_v] = 0;

    bool test;

    for(int i = 1 ;i < num_v; i++) {

        test = true;

        for (int u = 0; u < num_v; u++) {

            for (int v = 0; v < num_v; v++) {

                int w = g->get_matrix(u, v);

                if (w == 0) continue;

                if (path[u] != INT_MAX && path[v] > path[u] + w ) {

                    test = false;
                    path[v] = path[u] + w;
                    prev[v] = u;

                }

            }

        }

        if (test) {

            non_neg_cycle = true;
            return;
        }

    }

    for(int u = 0; u < num_v; u++){

        for(int v = 0; v < num_v; v++){

            int w = g->get_matrix(u,v);

            if(w == 0) continue;

            if(path[v] > path[u] + w){

                non_neg_cycle = false;
                return;

            }

        }

    }

    non_neg_cycle = true;

}

void Ford_bell_alg::solution_list() {

    path[start_v] = 0;
    bool test;

    for(int i = 1; i < num_v; i++){

        test = true;

        for(int u = 0; u < num_v; u++){

            auto adj = g->get_adj(u)->get_list();
            auto size = g->get_adj(u)->get_size();

            for(int k = 0; k < size; k++){

                auto v = adj[k].neighbor;
                auto w = adj[k].path;

                if(path[u] != INT_MAX && path[v] > path[u] + w){

                    test = false;
                    path[v] = path[u] + w;
                    prev[v] = u;

                }
            }

        }

        if(test){
            non_neg_cycle = true;
            return;
        }

    }

    for(int u = 0; u < num_v; u++){

        auto adj = g->get_adj(u)->get_list();
        auto size = g->get_adj(u)->get_size();

        for(int k = 0; k < size; k++){

            auto v = adj[k].neighbor;
            auto w = adj[k].path;

            if(path[v] > path[u] + w){

                non_neg_cycle = false;
                return;

            }
        }

    }

    non_neg_cycle = true;

}

void Ford_bell_alg::display_solution() {

    if(non_neg_cycle) {

        std::cout << "Start = " << start_v << std::endl;
        std::cout << " End   " << "           Cost  " << "             Path   " << std::endl;

        for (int i = 0; i < num_v; i++) {
            if(path[i] != INT_MAX)
                std::cout<< std::setw(3) << i << std::setw(3)<< "      |       " << std::setw(3)<<path[i] << "      |   "<<std::setw(3);
            else
                std::cout << i <<"       |       "<<"INF" << "      |   ";
            path_of_v(i);
            std::cout << i;
            std::cout << std::endl;
        }
    } else{
        std::cout<< "Negative cycle !!"<< std::endl;
    }

}

void Ford_bell_alg::path_of_v(int v) {
    if(prev[v] != -1 ) {
        path_of_v(prev[v]);
        std::cout << prev[v] << "   ";
    }
}


