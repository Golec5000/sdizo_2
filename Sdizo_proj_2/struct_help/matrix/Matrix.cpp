#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<int>> temp, int size, bool directed) : matrix_size(size){

    tab = new int * [matrix_size]; // utworzenie macierzy

    if(tab != nullptr) {

        for (int i = 0; i < matrix_size; i++)
            tab[i] = new int[matrix_size];


        for (int i = 0; i < matrix_size; i++)  // wyzerowanie całej macierzy
            for (int j = 0; j < matrix_size; j++)
                tab[i][j] = 0;

        for (int i = 0; i < temp.size(); i++){
            tab[temp[i][0]][temp[i][1]] = temp[i][2];
            if(!directed) tab[temp[i][1]][temp[i][0]] = temp[i][2]; //oznacza to, że graf nie jest skierowany
        }
    }
}

Matrix::~Matrix() {

    for(int i = 0; i < matrix_size; i++)
        delete [] tab[i];
    delete[] tab;

}

int Matrix::get_matrix_size() {
    return matrix_size;
}

int **Matrix::get_tab() {
    return tab;
}

void Matrix::display_matrix() {

    for(int i = 0; i < matrix_size; i++){

        for(int j = 0 ; j < matrix_size; j++)
            std::cout<< std::setw(4) << tab[i][j];

        std::cout<<std::endl;
    }

}
