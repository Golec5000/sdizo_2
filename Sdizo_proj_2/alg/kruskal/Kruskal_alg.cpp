#include "Kruskal_alg.h"

Kruskal_alg::Kruskal_alg(Graf * g, std::vector<std::vector<int>> tmp) : ans_size(0), ans(nullptr) {

    num_of_v = g->get_number_v();

    num_of_edges = g->get_number_e();
    edges = new Edge * [num_of_edges];

    tmp.erase(tmp.begin());

    for (int i = 0; i < num_of_edges; i++){
        edges[i] = new Edge(tmp[i][0],tmp[i][1],tmp[i][2]);
    }

}

Kruskal_alg::~Kruskal_alg() {

    for(int i = 0; i < num_of_edges; i++)
        delete edges[i];
    delete [] edges;

    for(int i = 0; i < ans_size; i++)
        delete ans[i];
    delete [] ans;
}

void Kruskal_alg::solution() {

    make_set();

    quick_sort(0, num_of_edges - 1);

    for(int i = 0; i < num_of_edges; i++){

        auto edge = edges[i];

        if(find_set(edge->get_u()) != find_set(edge->get_v())){

            add_edge_to_ans(edge);
            union_set(edge->get_u(),edge->get_v());

        }

    }


}

void Kruskal_alg::make_set() {
    group = new int [num_of_v];
    for (int i = 0; i < num_of_v; i++) group[i] = i;
}

int Kruskal_alg::find_set(int v) {
    return group[v];
}

void Kruskal_alg::union_set(int u, int v) {

    for(int i = 0; i < num_of_v; i++)
        if(group[i] == group[v])
            group[i] = group[u];

}

/*
 * funkcja pomocnicza wzięta ze strony
 * https://eduinf.waw.pl/inf/alg/003_sort/0018.php
 */

void Kruskal_alg::quick_sort(int left, int right) {

    int i,j;

    i = (left + right) / 2;

    auto piwot = edges[i];
    edges[i] = edges[right];

    for(j = i = left; i < right; i++){
        if(edges[i]->get_w() < piwot->get_w()) {
            std::swap(edges[i], edges[j]);
            j++;
        }
    }

    edges[right] = edges[j];
    edges[j] = piwot;

    if(left < j -1) quick_sort(left,j - 1);
    if(j + 1 < right) quick_sort(j + 1, right);
}

void Kruskal_alg::add_edge_to_ans(Edge *edge) {

    if(ans == nullptr){

        ans_size ++;
        ans = new Edge * [ans_size];
        ans[0] = edge;

    } else {

        int tmp_size = ans_size + 1;
        Edge **tmp_tab = new Edge *[tmp_size];

        if (tmp_tab != nullptr) {

            for(int i = 0; i < ans_size; i++){
                tmp_tab[i] = ans[i];
            }

            tmp_tab[ans_size] = edge;

            delete [] ans;
            ans = tmp_tab;
            ans_size = tmp_size;

        }
    }

}

void Kruskal_alg::display_solution() {

    std::cout<<std::endl;

    for(int i = 0; i < ans_size; i++){
        ans[i]->display();
        std::cout<<std::endl;
    }

}
