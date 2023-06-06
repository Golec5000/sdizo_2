#ifndef SDIZO_PROJ_2_EDGE_H
#define SDIZO_PROJ_2_EDGE_H

#include <iostream>

class Edge {
public:
    Edge();
    Edge(int u, int v, int w);
    int get_v() const;
    int get_u() const;
    int get_w() const;
    void display() const;
private:
    int u,v,w;
};


#endif //SDIZO_PROJ_2_EDGE_H
