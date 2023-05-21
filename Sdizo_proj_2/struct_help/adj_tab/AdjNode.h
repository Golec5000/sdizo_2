#ifndef SDIZO_PROJ_2_ADJNODE_H
#define SDIZO_PROJ_2_ADJNODE_H


class AdjNode {
public:
    AdjNode(int num);
    int find_key(int num);
    int key;
    AdjNode * next;

};


#endif //SDIZO_PROJ_2_ADJNODE_H
