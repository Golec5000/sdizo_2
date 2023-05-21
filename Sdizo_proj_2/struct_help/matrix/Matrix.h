#ifndef SDIZO_PROJ_2_MATRIX_H
#define SDIZO_PROJ_2_MATRIX_H
#include <vector>
#include <iostream>
#include <iomanip>
class Matrix {


public:
    Matrix(std::vector<std::vector<int>> temp, int size, bool directed);
    ~Matrix();
    int get_matrix_size();
    int ** get_tab();
    void display_matrix();
private:
   int  ** tab;
   int matrix_size;
};


#endif //SDIZO_PROJ_2_MATRIX_H
