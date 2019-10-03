#include <fstream>
#include "experiment.hpp"
#include "log.hpp"
#include "pow3.hpp"
#include "pow3mult.hpp"
#include "sum.hpp"
#include "sqrt.hpp"

int main() {
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 20000000};

    std::vector<double> results;
    std::pair<double, double> logpair, pow3pair, pow3multpair, sumpair, sqrtpair;

    std::ofstream myfile;
    myfile.open ("O2_times.json");
    myfile << "{\n    ";

    myfile << '"' << "log" << '"' << ": [";
    for (int n = 0; n < sizes.size(); n++) {
        Log veclog(sizes[n]);
        logpair = veclog.run();
        if (n == sizes.size()-1) {
            myfile << logpair.first;
        }
        else {
            myfile << logpair.first << ", ";
        }
    }
    myfile << "],\n    ";


    myfile << '"' << "pow3" << '"' << ": [";
    for (int n = 0; n < sizes.size(); n++) {
        Pow3 vecpow3(sizes[n]);
        pow3pair = vecpow3.run();
        if (n == sizes.size()-1) {
            myfile << pow3pair.first;
        }
        else {
            myfile << pow3pair.first << ", ";
        }
    }
    myfile << "],\n    ";

    myfile << '"' << "pow3mult" << '"' << ": [";
    for (int n = 0; n < sizes.size(); n++) {
        Pow3mult vecpow3mult(sizes[n]);
        pow3multpair = vecpow3mult.run();
        if (n == sizes.size()-1) {
            myfile << pow3multpair.first;
        }
        else {
            myfile << pow3multpair.first << ", ";
        }
    }
    myfile << "],\n    ";

    myfile << '"' << "sum" << '"' << ": [";
    for (int n = 0; n < sizes.size(); n++) {
        Sum vecsum(sizes[n]);
        sumpair = vecsum.run();
        if (n == sizes.size()-1) {
            myfile << sumpair.first;
        }
        else {
            myfile << sumpair.first << ", ";
        }
    }
    myfile << "],\n    ";

    myfile << '"' << "sqrt" << '"' << ": [";
    for (int n = 0; n < sizes.size(); n++) {
        Sqrt vecsqrt(sizes[n]);
        sqrtpair = vecsqrt.run();
        if (n == sizes.size()-1) {
            myfile << sqrtpair.first;
        }
        else {
            myfile << sqrtpair.first << ", ";
        }
    }
    myfile << "]\n}";
    myfile.close();




    // results.push_back(logpair.first);
    // results.push_back(logpair.second);

    
    // results.push_back(pow3pair.first);
    // results.push_back(pow3pair.second);

    
    // results.push_back(pow3multpair.first);
    // results.push_back(pow3multpair.second);

    
    // results.push_back(sumpair.first);
    // results.push_back(sumpair.second);

    
    // results.push_back(sqrtpair.first);
    // results.push_back(sqrtpair.second);

    // std::cout << "Log mean: " << results[0] << std::endl << "Log std. dev.: " << results[1] << std::endl << std::endl;
    // std::cout << "Pow3 mean: " << results[2] << std::endl << "Pow3 std. dev.: " << results[3] << std::endl << std::endl;
    // std::cout << "Pow3mult mean: " << results[4] << std::endl << "Pow3mult std. dev.: " << results[5] << std::endl << std::endl;
    // std::cout << "Sum mean: " << results[6] << std::endl << "Sum std. dev.: " << results[7] << std::endl << std::endl;
    // std::cout << "Sqrt mean: " << results[8] << std::endl << "Sqrt std. dev.: " << results[9] << std::endl << std::endl;


}