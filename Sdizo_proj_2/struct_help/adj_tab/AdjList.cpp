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

        std::cout << std::setw(3) <<p->neighbor  <<" : " <<p -> path<< std::setw(3);
        p = p -> next;

    }
    std::cout << "]" << std::endl;
}

void AdjList::add(int path, int neighbor) {
    auto * new_node = new AdjNode(path,neighbor);
    new_node->next = head;
    head = new_node;
    size++;
}

int AdjList::get_size() {
    return size;
}

AdjNode *AdjList::get_list() {

    if(size > 0) {
        int i = 0;
        auto * p = head;
        auto *temp = new AdjNode[size];

        while (p != nullptr) {

            temp[i] = *p;
            p = p->next;
            i++;

        }

        return temp;

    }
    return nullptr;
}
