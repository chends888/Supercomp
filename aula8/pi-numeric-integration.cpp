#include <thread>
#include <vector>
#include <iostream>
#include <chrono>

void calc_parc_pi(int id, unsigned int num_steps, double step, double *res) {
    double x, sum = 0;
    for (int i=id*num_steps; i<(id*num_steps)+num_steps; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    res[id] = sum;
}

int main() {
    unsigned int num_steps = 100000000;
    double pi, sum, step = 0;
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::cout << "\nThreads detected: " << num_threads << std::endl;
    std::vector<std::thread> threads;
    // std::cout << "Steps: " << num_steps << std::endl;
    unsigned int num_steps_thread = num_steps / num_threads;
    step = 1.0 / num_steps;

    double *res = new double[num_threads];

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i=0; i<num_threads; i++) {
        threads.push_back(std::thread(calc_parc_pi, i, num_steps_thread, step, res));
    }

    // for (i = 0; i < num_steps; i++) {
    //     x = (i + 0.5) * step;
    //     sum = sum + 4.0 / (1.0 + x * x);
    // }
    for (int i=0; i<num_threads; i++) {
        threads[i].join();
    }
    for (int i=0; i<num_threads; i++) {
        sum += res[i];
    }
    pi = step * sum;

    auto end_time = std::chrono::high_resolution_clock::now();
    // auto runtime = std::chrono::duration_cast<std::chrono::seconds> (end_time - start_time);
    auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);

    std::cout << "\nSteps: " << num_steps << std::endl;
    std::cout << "Time: " <<  time_span.count() << " s" << std::endl;
    std::cout << "Value: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
}