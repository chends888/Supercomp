#include "experiment.hpp"

// Experiment::Experiment(int n) : n(n) {
//     std::cout << "Objeto Exemplo criado e matriz gerada!\n";
//     vec1 = generate_input();
// }

double *Experiment::generate_input() {
    double *temp = new double[n];

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    for (int i = 0; i < n; i++) {
        std::uniform_real_distribution<> dis(0.0, 10.0);
        temp[i] = dis(gen);
    }
    return temp;
}

void Experiment::experiment_code() {
}

double Experiment::get_duration() {
    return duration;
}

void Experiment::run() {
    experiment_code();
}