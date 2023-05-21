#include "AdjList.h"

AdjList::AdjList() : head(nullptr), size(0){

}

AdjList::~AdjList() {
    while (head != nullptr){ // kasowanie wszytkich węzłów po zakończeniu kożystania z listy
        auto * p = head -> next;
        delete head;
        head = p;
    }
    size = 0;
}

void AdjList::display() {
    //wyświetla liste od przodu
    auto * p = head;

    std::cout << "[";
    while (p != nullptr){

        std::cout << std::setw(3) << p -> key << std::setw(3);
        p = p -> next;

    }
    std::cout << "]" << std::endl;
}

void AdjList::add(int num) {
    auto * new_node = new AdjNode(num);
    new_node->next = head;
    head = new_node;
    size++;
}

bool AdjList::find_key(int num) {
    auto * p = head;

    while (p != nullptr && p->key != num){

        if(p->key == num) return true;
        p = p->next;

    }

    return false;
}

int AdjList::get_size() {
    return size;
}

int *AdjList::get_list() {

    if(size > 0) {
        int i = 0;
        auto * p = head;
        int *temp = new int[size];

        while (p != nullptr) {

            temp[i] = p->key;
            p = p->next;
            i++;

        }

        return temp;

    }
    return nullptr;
}
