#include "Graph_gen.h"

Graf *Graph_gen::generate(int size, bool directed, float density, bool not_negative, int start_v, int end_v) {

    Graf * g = nullptr;

    if(density < 0.0f) density = 0.0f;
    if(density > 1.0f) density = 1.0f;

    if(size == 0) return nullptr;

    int max_num_of_edge;
    if(directed) max_num_of_edge = size * size;
    else max_num_of_edge = (size * size - size) / 2;

    std::vector<Edge> edges_prime = random_edges(size,(int)(max_num_of_edge * density), max_num_of_edge, directed, not_negative);

    std::vector<std::vector<int>> data = final_data(size,edges_prime.size(),start_v,end_v,edges_prime);

    g = new Graf(data,directed);

    return g;
}

std::vector<Edge> Graph_gen::all_combinations(int max_v, bool directed, int max_e, bool not_negative) {


    std::vector<Edge> combinations(max_e);
    std::vector<int> weights = radom_num_gen(max_e, ( not_negative ? 0 : 2*CHAR_MIN ), 2*CHAR_MAX);
    long long combination_index = 0;

    for(int i = 0; i < max_v; i++){
        for(int j = 0; j < max_v; j++){
            if(!directed && j <= i) continue;
            combinations[combination_index] = Edge(i, j, weights[combination_index]);
            combination_index++;
        }
    }
    return combinations;

}

std::vector<Edge> Graph_gen::random_edges(int max_v, int edges_count, int max_num_of_edges, bool directed, bool not_negative) {

    std::vector<Edge> combinations = all_combinations(max_v,directed,max_num_of_edges,not_negative);
    std::vector<Edge> chosen_edges(min(edges_count, max_num_of_edges - edges_count));

    std::vector<Edge> requests_e = ensures_conections(combinations,max_v);

    if(chosen_edges.size() < max_v - 1) chosen_edges.resize(max_v - 1);

    for(int i = 0; i < max_v - 1; i++) chosen_edges[i] = requests_e[i];

    int chosen_edge_index;
    for(long long i = max_v-1; i < chosen_edges.size(); i++){
        chosen_edge_index = radom_num_gen(1, 0, combinations.size()-1)[0];
        chosen_edges[i] = combinations[chosen_edge_index];
        combinations.erase(combinations.begin() + chosen_edge_index);
    }

    if(combinations.size() == edges_count) return combinations;
    return chosen_edges;
}

std::vector<Edge> Graph_gen::ensures_conections(std::vector<Edge> &all_edges, int max_v) {


    std::vector<bool> included (max_v,false);

    std::vector<Edge> chosen_edges(max_v-1);
    int chosen_edge;
    int already_chosen_edges = 0;

    chosen_edge = radom_num_gen(1, 0, all_edges.size()-1)[0];

    chosen_edges[already_chosen_edges] = all_edges[chosen_edge];
    all_edges.erase(all_edges.begin() + chosen_edge);

    included[chosen_edges[already_chosen_edges].get_v()] = true;
    included[chosen_edges[already_chosen_edges].get_u()] = true;

    already_chosen_edges++;

    do {
        chosen_edge = radom_num_gen(1, 0, all_edges.size()-1)[0];

        if(!(included[all_edges[chosen_edge].get_v()] ^ included[all_edges[chosen_edge].get_u()]))
            continue;

        chosen_edges[already_chosen_edges] = all_edges[chosen_edge];
        all_edges.erase(all_edges.begin() + chosen_edge);

        included[chosen_edges[already_chosen_edges].get_v()] = true;
        included[chosen_edges[already_chosen_edges].get_u()] = true;
        already_chosen_edges++;

    } while (already_chosen_edges < max_v-1);

    return chosen_edges;
}

std::vector<std::vector<int>> Graph_gen::final_data(int size_v, int size_e, int start_v, int end_v, std::vector<Edge> &combinatios) {

    std::vector<std::vector<int>> data;

    std::vector<int> title;

    title.push_back(size_e);
    title.push_back(size_v);
    title.push_back(start_v);
    title.push_back(end_v);

    data.push_back(title);

    for(int i = 0; i < size_e; i ++){

        std::vector<int> tmp;
        tmp.push_back(combinatios[i].get_u());
        tmp.push_back(combinatios[i].get_v());
        tmp.push_back(combinatios[i].get_w());

        data.push_back(tmp);
    }


    return data;
}

std::vector<int> Graph_gen::radom_num_gen(int num, int min, int max) {
    // Sprawdzam, czy zadana ilość liczb jest niezerowa
    std::vector<int> list;
    if(num == 0) return list;

    // Dokonuję ewentualnej poprawki wybranego przedziału
    if(min > max) std::swap(min, max);

    // Generuję liczby
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<> distribution(min, max);

    for(int i = 0; i < num; i++) list.push_back(distribution(generator));
    return list;
}

int Graph_gen::min(int num1, int num2) {
    if(num1 < num2) return num1;
    return num2;
}
