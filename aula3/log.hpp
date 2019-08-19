#ifndef LOG_H
#define LOG_H

#include "experiment.hpp"

class Log : public Experiment {
    public:
    Log (int size) : Experiment(size) {
    }
    void experiment_code();
};

#endif