#include "Dym_arr.h"
#include "../edge/Edge.h"
#include "../que_prio/QueElement.h"

template class Dym_arr<int>;
template class Dym_arr<Edge>;
template class Dym_arr<QueElement>;

template <typename T> Dym_arr<T>::Dym_arr(){

    tab = nullptr;
    size = 0;

}

template <typename T>  Dym_arr<T>::~Dym_arr(){

    if(!tab) return;

    delete [] tab;
    tab = nullptr;

    size = 0;

}

template <typename T> void Dym_arr<T>::swap(unsigned index1, unsigned index2) {

    if(index1 >= size) return;
    if(index2 >= size ) return;

    T tmp = tab[index1];
    tab[index1] = tab[index2];
    tab[index2] = tmp;

}

template <typename T> void Dym_arr<T>::pop_back() {

    if(size == 0) return;

    int temp_size = size - 1;
    T* temp_tab = new T[temp_size];
    for(int i = 0; i < temp_size; i++)
        temp_tab[i] = tab[i];


    delete[] tab;
    tab = temp_tab;
    size = temp_size;


}

template <typename T> void Dym_arr<T>::pop_front()  {

    if(size == 0) return;

    int tmp_size = size - 1;
    T* tmp_tab = new T[tmp_size];

    for(int i = 0; i < tmp_size; i++)
        tmp_tab[i] = tab[i+1];


    delete[] tab;

    tab = tmp_tab;
    size = tmp_size;
}


template <typename T> void Dym_arr<T>::add_back(T value) {

    if(size == 0){

        size++;
        tab = new T[size];
        tab[0] = value;

    } else {
        int tmp_size = size + 1;
        T *tmp_tab = new T[tmp_size];

        for (int i = 0; i < tmp_size; i++)
            tmp_tab[i] = tab[i];

        tmp_tab[size] = value;

        delete[] tab;

        tab = tmp_tab;
        size = tmp_size;
    }

}


template <typename T> void Dym_arr<T>::add_front(T value) {


    if(size == 0){

        size++;
        tab = new T[size];
        tab[0] = value;

    } else {
        int tmp_size = size + 1;
        T *tmp_tab = new T[tmp_size];

        tmp_tab[0] = value;

        for (int i = 1; i < tmp_size; i++) tmp_tab[i] = tab[i - 1];

        delete[] tab;

        tab = tmp_tab;
        size = tmp_size;
    }

}

template <typename T> int Dym_arr<T>::get_size() {
    return size;
}

template <typename T> T* Dym_arr<T>::get_value(unsigned index) {
    return &(tab[index]);
}

template <> void Dym_arr<int>::display_ints() {

    if(!tab) return;

    for(int i = 0; i < size; i++) std::cout<< tab[i] << " ";

    std::cout<<std::endl;

}

template <> void Dym_arr<Edge>::display_edges() {

    if(!tab) return;

    for(int i = 0; i < size; i++) {
        std::cout<< tab[i].get_u() << " " << tab[i].get_v() << " " << tab[i].get_w();
        std::cout<<std::endl;
    }

    std::cout<<std::endl;

}
template <> void Dym_arr<QueElement>::display_nodes() {


    if(!tab) return;

    for(int i = 0; i < size; i++) std::cout<< tab[i].get_key() << "  |  " << tab[i].get_prio();

    std::cout<<std::endl;

}

template <> void Dym_arr<Edge>::quick_sort_edges(unsigned int left, unsigned int right) {

    if(left >= right) return;

    auto pivot = tab[left];

    int pivot_index;
    int l = left;
    int r = right;

    while (true){

        while (tab[l].get_w() < pivot.get_w()) ++l;
        while (tab[r].get_w() > pivot.get_w()) --r;

        if(l < r){

            swap(l,r);
            ++l;
            --r;

        } else{

            if(r == right) r--;
            pivot_index = r;
            break;
        }

    }

    quick_sort_edges(left,pivot_index);
    quick_sort_edges(pivot_index+1,right);

}