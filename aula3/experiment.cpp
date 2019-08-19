#include "experiment.hpp"

void Experiment::generate_input() {
    std::vector<double> temp;

    // http://www.cplusplus.com/reference/random/normal_distribution/
    std::default_random_engine gen;  // Will be used to obtain a seed for the random number engine
    std::normal_distribution<double> dis(5, 0.25);


    for(int i = 0; i < n; i++) {
        temp.push_back(dis(gen));
    }
    vec1 = temp;
}

void Experiment::experiment_code() {
}

double Experiment::get_duration() {
    return duration;
}

std::pair<double, double> Experiment::run() {
    double time, var;
    for (int i = 0; i < 10; i++) {
        experiment_code();
        time += duration;
    }
    time = time/10;
    for (int i = 0; i < 10; i++) {
        var += (duration - time) * (duration - time);
    }
    var /= 10;
    double stddev = sqrt(var);
    std::pair<double, double> minmax(time, stddev);
    return minmax;
}