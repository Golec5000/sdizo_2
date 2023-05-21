#ifndef SDIZO_PROJ_2_GRAF_H
#define SDIZO_PROJ_2_GRAF_H

#include "../struct_help/adj_tab/AdjList.h"
#include "../struct_help/matrix/Matrix.h"

class Graf {

public:
    explicit Graf(std::vector<std::vector<int>> temp, bool directed);
    ~Graf();
    int get_matrix(int u, int v);
    void display();
    int get_number_v();
    int get_number_e();
    int get_start_v();
    int get_end_v();
    AdjList * get_adj(int line);

private:
    Matrix * matrix = nullptr;
    AdjList ** adj_tab = nullptr;
    void display_adj();
    int number_V,number_E;
    int start_V, end_V;
    void creat_adj_tab();
};


#endif //SDIZO_PROJ_2_GRAF_H
