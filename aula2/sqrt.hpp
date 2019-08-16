#ifndef SQRT_H
#define SQRT_H

#include "experiment.hpp"

class Sqrt : public Experiment {
    public:
    Sqrt (int size) : Experiment(size) {
    }
    void experiment_code();
};

#endif