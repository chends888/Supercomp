#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include <iostream>
#include <random>
#include <math.h>
#include <chrono>
#include <tuple>
#include <vector>


class Experiment {
    public:
        std::vector<double> vec1;
        int n;
        Experiment(int size) {
            n = size;
            generate_input();
            std::cout << "Test object and matrix created!\n";
        }
        double duration;
        void generate_input();
        double get_duration();
        virtual void experiment_code();
        std::pair<double, double> run();
        operator double() {
            return duration;
        }
        bool operator < (Experiment &exper) {
            if ((this->duration < exper.duration) && (this->n == exper.n)) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator < (double testnum) {
            if (this->duration < testnum) {
                return true;
            }
            else {
                return false;
            }
        }
};

#endif