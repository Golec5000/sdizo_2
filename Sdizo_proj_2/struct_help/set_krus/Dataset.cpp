#include "Dataset.h"

Dataset::Dataset() {}

Dataset::~Dataset() {}

int Dataset::get_power() {
    return power;
}

int Dataset::get_root() {
    return root;
}

void Dataset::set_power(int power) {
    this->power = power;
}

void Dataset::set_root(int root) {
    this->root = root;
}
