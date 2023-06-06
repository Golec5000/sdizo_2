#include "AdjNode.h"

AdjNode::AdjNode(int path,int neighbor) : path(path), neighbor(neighbor), next(nullptr){

}

AdjNode::AdjNode() {

}

int AdjNode::get_path() const {
    return path;
}

int AdjNode::get_neighbor() const {
    return neighbor;
}




