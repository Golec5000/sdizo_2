#include "Kruskal_alg.h"

Kruskal_alg::Kruskal_alg(Graf * g) : num_of_v(g->get_number_v()) {

    this->g = g;

    edges = new Dym_arr<Edge>;
    mst = new Dym_arr<Edge>;
    dataset = new Dataset[num_of_v];

}

Kruskal_alg::~Kruskal_alg() {

    delete edges;
    delete mst;
    delete [] dataset;

}

void Kruskal_alg::solution_list() {

    make_set();

    for(int u = 0; u < num_of_v; u++){

        auto adj = g->get_adj(u)->get_list();
        auto size = g->get_adj(u)->get_size();

        if(size == 0) continue;

        for(int i = 0; i < size; i++){

            int v = adj[i].neighbor;
            int w = adj[i].path;

            if(v >= u) edges->add_back(Edge(u,v,w));

        }

    }

    edges->quick_sort_edges(0, edges->get_size() - 1);


    for(int i = 0; i < edges->get_size() ; i++){

        auto edge = edges->get_value(i);

        if(find_set(edge->get_v()) == find_set(edge->get_u())) continue;

        mst->add_back(*edge);
        union_set(*edge);

    }

}

void Kruskal_alg::solution_matrix()  {

    make_set();

    for(int i = 0; i < num_of_v; i++){

        for(int j = i; j < num_of_v; j++){

            if(g->get_matrix(i,j) == 0) continue;
            if(i < j) edges->add_back(Edge(i,j,g->get_matrix(i,j)));


        }

    }

    edges->quick_sort_edges(0, edges->get_size() - 1);


    for(int i = 0; i < edges->get_size() ; i++){

        auto edge = edges->get_value(i);

        if(find_set(edge->get_u()) == find_set(edge->get_v())) continue;

        mst->add_back(*edge);
        union_set(*edge);

    }


}

void Kruskal_alg::make_set() {

    for(int i = 0; i < num_of_v; i++){
        dataset[i].set_power(0);
        dataset[i].set_root(i);
    }

}

int Kruskal_alg::find_set(int v) {

    if(dataset[v].get_root() != v) dataset[v].set_root(find_set(dataset[v].get_root()));

    return dataset[v].get_root();

}

void Kruskal_alg::union_set(Edge e) {

    int u,v;

    u = find_set(e.get_u());
    v = find_set(e.get_v());

    if(u != v){


        if(dataset[u].get_power() > dataset[v].get_power()) dataset[v].set_root(u);
        else{

            dataset[u].set_root(v);

            if(dataset[u].get_power() == dataset[v].get_power()){

                dataset[v].set_power(dataset[v].get_power() + 1);

            }

        }

    }

}

void Kruskal_alg::display_solution() {

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