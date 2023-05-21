#include "Que.h"

Que::Que() : head(nullptr), tail(nullptr) {}

Que::~Que() {

    while (head != nullptr){ // kasowanie wszytkich węzłów po zakończeniu kożystania z listy
        auto * p = head -> next;
        delete head;
        head = p;
    }

}

void Que::push(long long prio, int key) {
    auto * new_node = new QueNode(prio,key);

    if(head == nullptr) head = tail = new_node;
    else if (head->prio > prio){
        new_node->next = head;
        head = new_node;
    } else{
        auto * tmp = head;
        while( ( tmp->next ) && ( tmp->next->prio <= prio ) )
            tmp = tmp->next;
        new_node->next = tmp->next;
        tmp->next = new_node;
        if( !new_node->next ) tail = new_node;
    }

}

int Que::pop() {

    if(head != nullptr) {

        auto *p = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;

        int v = p->key;
        delete p;
        return v;
    }
}

bool Que::empty() {
    return !head;
}

bool Que::contains(int key) {

    auto * p = head;

    if(p != nullptr){

        while (p != nullptr){

            if(p->key == key) return true;
            p = p->next;
        }

    }

    return false;
}
