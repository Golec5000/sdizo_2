#ifndef SDIZO_PROJ_2_QUENODE_H
#define SDIZO_PROJ_2_QUENODE_H


class QueNode {
public:
    QueNode(long long prio, int num);
    QueNode * next;
    long long prio;
    int key;
};


#endif //SDIZO_PROJ_2_QUENODE_H
