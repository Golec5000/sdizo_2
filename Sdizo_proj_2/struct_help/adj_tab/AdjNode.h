#ifndef SDIZO_PROJ_2_ADJNODE_H
#define SDIZO_PROJ_2_ADJNODE_H


class AdjNode {
public:
    AdjNode(int path, int neighbor);
    AdjNode();

    int get_path() const;
    int get_neighbor() const;

    int path;
    int neighbor;

    AdjNode * next;

};


#endif //SDIZO_PROJ_2_ADJNODE_H
