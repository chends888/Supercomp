#ifndef POW3_H
#define POW3_H

#include "experiment.hpp"

class Pow3 : public Experiment {
    public:
    Pow3 (int size) : Experiment(size) {
    }
    void experiment_code();
};

#endif