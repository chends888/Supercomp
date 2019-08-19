#include "pow3.hpp"
#include <math.h>
#include <random>
#include <chrono>


void Pow3::experiment_code() {
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::chrono::high_resolution_clock::time_point start, finish;
    std::chrono::duration<double> time_span;
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; i++) {
        vec1[i] = pow(vec1[i], 3);
    }
    finish = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
    duration = time_span.count();
}
