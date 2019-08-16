#include <iostream>
// #include <vector>
#include <random>
#include <math.h>
#include <chrono>


// https://discuss.codechef.com/t/how-to-return-an-array-from-a-function/13667/3
double *gera_vetor(int size) {
    double *temp = new double[size];

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    for(int i = 0; i < size; i++) {
        std::uniform_real_distribution<> dis(0.0, 10.0);
        temp[i] = dis(gen);
    }
    return temp;
}
double *log(int size, double *vec1) {
    double *temp = new double[size];
    for(int i = 0; i < size; i++) {
        temp[i] = log(vec1[i]);
    }
    return temp;
}
double *sqrt(int size, double *vec1) {
    double *temp = new double[size];
    for(int i = 0; i < size; i++) {
        temp[i] = sqrt(vec1[i]);
    }
    return temp;
}
double *pow3(int size, double *vec1) {
    double *temp = new double[size];
    for(int i = 0; i < size; i++) {
        temp[i] = pow(vec1[i], 3);
    }
    return temp;
}
double *pow3mult(int size, double *vec1) {
    double *temp = new double[size];
    for(int i = 0; i < size; i++) {
        temp[i] = vec1[i]*vec1[i]*vec1[i];
    }
    return temp;
}
double sum(int size, double *vec1) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += vec1[i];
    }
    return sum;
}


int main() {
    std::chrono::high_resolution_clock::time_point start, finish;
    std::chrono::duration<double> time_span;
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 20000000};
    double vecsum;
    double *vec1;



    for(int i = 0; i < sizes.size(); i++) {
        std::cout << "Size: " << sizes[i] << " doubles" << std::endl;


        // Generating array
        vec1 = new double[sizes[i]];
        start = std::chrono::high_resolution_clock::now();
        vec1 = gera_vetor(sizes[i]);
        finish = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
        std::cout << "Creating array took: " << time_span.count() << " s" << std::endl;
        delete[] vec1;

        // Calculating log
        vec1 = new double[sizes[i]];
        start = std::chrono::high_resolution_clock::now();
        vec1 = log(sizes[i], vec1);
        finish = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
        std::cout << "Calculating log took: " << time_span.count() << " s" << std::endl;
        delete[] vec1;

        // Calculating sqrt
        vec1 = new double[sizes[i]];
        start = std::chrono::high_resolution_clock::now();
        vec1 = sqrt(sizes[i], vec1);
        finish = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
        std::cout << "Calculating sqrt took: " << time_span.count() << " s" << std::endl;
        delete[] vec1;

        // Calculating pow3
        vec1 = new double[sizes[i]];
        start = std::chrono::high_resolution_clock::now();
        vec1 = pow3(sizes[i], vec1);
        finish = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
        std::cout << "Calculating pow3 took: " << time_span.count() << " s" << std::endl;
        delete[] vec1;

        // Calculating pow3mult
        vec1 = new double[sizes[i]];
        start = std::chrono::high_resolution_clock::now();
        vec1 = pow3mult(sizes[i], vec1);
        finish = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
        std::cout << "Calculating pow3mult took: " << time_span.count() << " s" << std::endl;
        delete[] vec1;

        // Calculating sum
        vec1 = new double[sizes[i]];
        start = std::chrono::high_resolution_clock::now();
        vecsum = sum(sizes[i], vec1);
        finish = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start);
        std::cout << "Calculating sum took: " << time_span.count() << " s" << std::endl;
        delete[] vec1;

        std::cout << std::endl;
    }
    // delete[] vec1;
}