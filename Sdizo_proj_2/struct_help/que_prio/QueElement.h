#ifndef SDIZO_PROJ_2_QUEELEMENT_H
#define SDIZO_PROJ_2_QUEELEMENT_H


class QueElement {

public:

    QueElement();
    QueElement(unsigned prio, unsigned key);

    int get_key() const;
    int get_prio() const;

private:

    int prio;
    int key;

};


#endif //SDIZO_PROJ_2_QUEELEMENT_H
