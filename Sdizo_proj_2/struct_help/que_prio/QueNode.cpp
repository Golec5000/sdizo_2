#include "QueNode.h"

QueNode::QueNode(long long prio, int num) : next(nullptr) {

    this->prio = prio;
    this->key = num;

}
