#include "QueElement.h"

QueElement::QueElement() {

}

QueElement::QueElement(unsigned int prio, unsigned int key) {

    this->prio = prio;
    this->key = key;

}

int QueElement::get_key() const {
    return key;
}

int QueElement::get_prio() const {
    return prio;
}
