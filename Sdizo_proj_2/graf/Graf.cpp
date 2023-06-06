#include "Graf.h"

Graf::Graf(std::vector<std::vector<int>> temp, bool directed) {

    number_E = temp[0][0];
    number_V = temp[0][1];

    start_V = temp[0][2];
    end_V = temp[0][3];

    temp.erase(temp.begin());

    matrix = new Matrix(temp, number_V,directed);
    creat_adj_tab();

    temp.clear();

}

Graf::~Graf() {
    delete matrix;
    for(int i = 0; i < number_V; i++)
        delete adj_tab[i];
}

int Graf::get_matrix(int u, int v) {
    return matrix->get_tab()[u][v];
}

void Graf::creat_adj_tab() {

    adj_tab = new AdjList * [number_V];

    for(int i = 0; i < number_V; i++) adj_tab[i] = new AdjList;

    for(int i = 0; i < number_V; i++)
        for(int j = number_V - 1; j >= 0; j--)
            if (matrix->get_tab()[i][j] != 0)
                adj_tab[i] -> add(matrix->get_tab()[i][j],j);


}

void Graf::display_adj() {

    for (int i = 0; i < number_V; i++) {
        std::cout << i << " -> ";
        adj_tab[i]->display();
    }

}

void Graf::display() {
    matrix->display_matrix();
    display_adj();
}

int Graf::get_number_v() {
    return number_V;
}

int Graf::get_number_e() {
    return number_E;
}

int Graf::get_start_v() {
    return start_V;
}

int Graf::get_end_v() {
    return end_V;
}

AdjList *Graf::get_adj(int line) {
    return adj_tab[line];
}
