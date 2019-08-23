#ifndef SUM_H
#define SUM_H

#include "experiment.hpp"

class Sum : public Experiment {
    public:
    Sum (int size) : Experiment(size) {
    }
    void experiment_code();
};

#endif