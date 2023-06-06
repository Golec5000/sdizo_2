#ifndef SDIZO_PROJ_2_DATASET_H
#define SDIZO_PROJ_2_DATASET_H


class Dataset {

public:

    Dataset();
    ~Dataset();

    int get_power();
    int get_root();

    void set_power(int power);
    void set_root(int root);

private:

    int root;
    int power;

};


#endif //SDIZO_PROJ_2_DATASET_H
