#include "Edge.h"
Edge::Edge() {}

Edge::Edge(int u, int v, int w) {

    this->u = u;
    this->v = v;
    this->w = w;

}

int Edge::get_v() const {
    return v;
}

int Edge::get_u() const{
    return u;
}

int Edge::get_w() const{
    return w;
}

void Edge::display() const {
    std::cout << u << " " << v << " " << w;
}


