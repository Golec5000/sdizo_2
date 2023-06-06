#include "Heap.h"

Heap::Heap() {
    heap = new Dym_arr<QueElement>();
}

Heap::~Heap() {

    delete heap;
    heap = nullptr;

}

void Heap::push(QueElement new_element) {

    heap->add_back(new_element);
    repair_heap_up(get_size() - 1);

}

int Heap::pop() {

    if(get_size() > 0) {

        heap->swap(0, get_size() - 1);

        int key = heap->get_value(get_size() - 1)->get_key();

        heap->pop_back();

        if (get_size() > 0) repair_heap_down(0);

        return key;
    }
}

void Heap::repair_heap_up(int index) {

    if(index == 0) return;

    if(index != get_min_index_child(parent_index(index))) return;

    auto curr = heap->get_value(index);
    auto parent = heap->get_value(parent_index(index));

    if(parent->get_prio() <= curr->get_prio()) return;

    heap->swap(index, parent_index(index));
    repair_heap_up(parent_index(index));

}



void Heap::repair_heap_down(int index) {

    int min_index = get_min_index_child(index);

    if(min_index == -1) return;

    auto min = heap->get_value(min_index);
    auto curr = heap->get_value(index);

    if(min->get_prio() >= curr->get_prio()) return;

    heap->swap(min_index,index);
    repair_heap_down(min_index);

}





int Heap::get_min_index_child(int index) {

    auto left = get_left_child(index);
    auto right = get_right_child(index);

    if(!left && !right)
        return -1;

    if(!left) return right_child_index(index);
    if(!right) return left_child_index(index);

    if(left->get_prio() > right->get_prio()) return right_child_index(index);
    else return left_child_index(index);

}


int Heap::parent_index(int index) {
    return (index - 1) / 2;
}

int Heap::left_child_index(int index) {
    return 2 * index + 1;
}

int Heap::right_child_index(int index) {
    return 2 * index + 2;
}

int Heap::get_size() {
    return heap->get_size();
}


QueElement * Heap::get_left_child(int index) {
    if(left_child_index(index) >= get_size())
        return nullptr;
    return heap->get_value(left_child_index(index));
}

QueElement *Heap::get_right_child(int index) {
    if(right_child_index(index) >= get_size())
        return nullptr;
    return heap->get_value(right_child_index(index));
}

bool Heap::empty() {
    return get_size() == 0;
}

