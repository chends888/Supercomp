#ifndef POW3MULT_H
#define POW3MULT_H

#include "experiment.hpp"

class Pow3mult : public Experiment {
    public:
    Pow3mult (int size) : Experiment(size) {
    }
    void experiment_code();
};

#endif