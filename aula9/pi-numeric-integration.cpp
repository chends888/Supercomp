#include <thread>
#include <vector>
#include <iostream>
#include <chrono>
#include <omp.h>

void calc_parc_pi(int id, double steps, double step, double *res) {
    double x, sum = 0;
    for (int i=id*steps; i<(id*steps)+steps; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }
    res[id] = sum;
}


double pi_seq(double steps) {
    double step;
    double x, sum = 0;
    step = 1.0 / steps;
    for (int i = 0; i < steps; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x * x);
    }

    double pi = step * sum;
    return pi;
}

double pi_threads(double steps) {
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::cout << "\nThreads detected: " << num_threads << std::endl;
    std::vector<std::thread> threads;
    // Setting the numebr of steps for each thread
    double steps_thread = steps / num_threads;
    double step = 1.0 / steps;

    double *res = new double[num_threads];

    for (int i=0; i<num_threads; i++) {
        threads.push_back(std::thread(calc_parc_pi, i, steps_thread, step, res));
    }
    double sum = 0;
    for (int i=0; i<num_threads; i++) {
        threads[i].join();
        sum += res[i];
    }
    double pi = step * sum;
    return pi;
}

double pi_omp_parallel(double steps) {
    unsigned int num_threads = omp_get_max_threads();
    std::cout << "\nOmp threads detected: " << num_threads << std::endl;
    double step = 1.0 / steps;
    // Setting the numebr of steps for each thread
    steps = steps / num_threads;

    double *sums = new double[num_threads];

    #pragma omp parallel
    {
        calc_parc_pi(omp_get_thread_num(), steps, step, sums);
    }
    double sum = 0;
    for (int i=0; i<num_threads; i++) {
        sum += sums[i];
    }
    double pi = step * sum;
    return pi;
}


double pi_omp_parallel_local(double steps) {
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::cout << "\nOmp threads detected: " << num_threads << std::endl;
    std::vector<std::thread> threads;
    double step = 1.0 / steps;
    // Setting the numebr of steps for each thread
    steps = steps / num_threads;

    double *sums = new double[num_threads];

    #pragma omp parallel
    {
        double x, sum = 0;
        for (int i=omp_get_thread_num()*steps; i<(omp_get_thread_num()*steps)+steps; i++) {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
        sums[omp_get_thread_num()] = sum;
    }

    double sum = 0;
    for (int i=0; i<num_threads; i++) {
        sum += sums[i];
    }
    double pi = step * sum;
    return pi;
}


double pi_omp_parallel_atomic(double steps) {
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::cout << "\nOmp threads detected: " << num_threads << std::endl;
    std::vector<std::thread> threads;
    double step = 1.0 / steps;
    // Setting the numebr of steps for each thread
    steps = steps / num_threads;

    double sum = 0;

    #pragma omp parallel
    {
        double x, partsum = 0;
        for (int i=omp_get_thread_num()*steps; i<(omp_get_thread_num()*steps)+steps; i++) {
            x = (i + 0.5) * step;
            partsum += 4.0 / (1.0 + x * x);
        }
        #pragma omp atomic
        sum += partsum;
    }

    double pi = step * sum;
    return pi;
}


double pi_omp_parallel_critical(double steps) {
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::cout << "\nOmp threads detected: " << num_threads << std::endl;
    std::vector<std::thread> threads;
    double step = 1.0 / steps;
    // Setting the numebr of steps for each thread
    steps = steps / num_threads;

    double sum = 0;

    #pragma omp parallel
    #pragma omp critical
    {
        double x, partsum = 0;
        for (int i=omp_get_thread_num()*steps; i<(omp_get_thread_num()*steps)+steps; i++) {
            x = (i + 0.5) * step;
            partsum += 4.0 / (1.0 + x * x);
        }
        #pragma omp atomic
        sum += partsum;
    }

    double pi = step * sum;
    return pi;
}


double pi_omp_parallel_critical_wrong(double steps) {
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::cout << "\nOmp threads detected: " << num_threads << std::endl;
    std::vector<std::thread> threads;
    double step = 1.0 / steps;
    // Setting the numebr of steps for each thread
    steps = steps / num_threads;

    double sum = 0;

    #pragma omp parallel
    #pragma omp critical
    {
        double x, partsum = 0;
        for (int i=omp_get_thread_num()*steps; i<(omp_get_thread_num()*steps)+steps; i++) {
            x = (i + 0.5) * step;
            #pragma omp atomic
            sum += 4.0 / (1.0 + x * x);
        }
    }

    double pi = step * sum;
    return pi;
}


int main() {
    double steps = 100000000;

    auto start_time = std::chrono::high_resolution_clock::now();
    double pi = pi_seq(steps);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Sequential pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi = pi_threads(steps);
    end_time = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Threads pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl << std::endl;


    start_time = std::chrono::high_resolution_clock::now();
    pi = pi_omp_parallel(steps);
    end_time = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Omp parallel pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi = pi_omp_parallel_local(steps);
    end_time = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Omp parallel local pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi = pi_omp_parallel_atomic(steps);
    end_time = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Omp parallel atomic pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi = pi_omp_parallel_critical(steps);
    end_time = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Omp parallel critical pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    pi = pi_omp_parallel_critical_wrong(steps);
    end_time = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    std::cout << "Omp parallel critical wrong pi: ";
    std::cout.precision(17);
    std::cout << pi << std::endl;
    std::cout.precision(3);
    std::cout << "Took: " <<  time_span.count() << " s" << std::endl << std::endl;
}