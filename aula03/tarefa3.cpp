#include "experiment.hpp"
#include "log.hpp"
#include "pow3.hpp"
#include "pow3mult.hpp"
#include "sum.hpp"
#include "sqrt.hpp"

int main() {
    int n = 10000000;

    std::cout << "Vector size: " << n << std::endl;
    std::cout << std::endl;

    Log veclog(n);
    Pow3 vecpow3(n);
    Pow3mult vecpow3mult(n);
    Sum vecsum(n);
    Sqrt vecsqrt(n);

    veclog.run();
    vecpow3.run();
    vecpow3mult.run();
    vecsum.run();
    vecsqrt.run();

    std::cout << std::endl;
    std::cout << "Log time: " << veclog.get_duration() << std::endl;
    std::cout << std::endl;
    std::cout << "Pow3 time: " << vecpow3.get_duration() << std::endl;
    std::cout << std::endl;
    std::cout << "Pow3mult time: " << vecpow3mult.get_duration() << std::endl;
    std::cout << std::endl;
    std::cout << "Sqrt time: " << vecsqrt.get_duration() << std::endl;
    std::cout << std::endl;
    std::cout << "Sum time: " << vecsum.get_duration() << std::endl;


    std::cout << std::endl;
    std::cout << "Log time using 'double' operator: " << double(veclog) << std::endl;
    std::cout << std::endl;

    if (veclog < 0.1) {
        std::cout << "Calc log took less than 0.1 sec" << std::endl;
    }
    if (vecpow3 < 0.1) {
        std::cout << "Calc pow3 took less than 0.1 sec" << std::endl;
    }
    if (vecpow3mult < 0.1) {
        std::cout << "Calc pow3mult took less than 0.1 sec" << std::endl;
    }
    if (vecsqrt < 0.1) {
        std::cout << "Calc sqrt took less than 0.1 sec" << std::endl;
    }
    if (vecsum < 0.1) {
        std::cout << "Calc sum took less than 0.1 sec" << std::endl;
    }
    std::cout << std::endl;

    std::vector<double> results;
    std::pair<double, double> logpair, pow3pair, pow3multpair, sumpair, sqrtpair;

    logpair = veclog.run();
    results.push_back(logpair.first);
    results.push_back(logpair.second);
    pow3pair = vecpow3.run();
    results.push_back(pow3pair.first);
    results.push_back(pow3pair.second);
    pow3multpair = vecpow3mult.run();
    results.push_back(pow3multpair.first);
    results.push_back(pow3multpair.second);
    sumpair = vecsum.run();
    results.push_back(sumpair.first);
    results.push_back(sumpair.second);
    sqrtpair = vecsqrt.run();
    results.push_back(sqrtpair.first);
    results.push_back(sqrtpair.second);

    std::cout << "Log mean: " << results[0] << std::endl << "Log std. dev.: " << results[1] << std::endl << std::endl;
    std::cout << "Pow3 mean: " << results[2] << std::endl << "Pow3 std. dev.: " << results[3] << std::endl << std::endl;
    std::cout << "Pow3mult mean: " << results[4] << std::endl << "Pow3mult std. dev.: " << results[5] << std::endl << std::endl;
    std::cout << "Sum mean: " << results[6] << std::endl << "Sum std. dev.: " << results[7] << std::endl << std::endl;
    std::cout << "Sqrt mean: " << results[8] << std::endl << "Sqrt std. dev.: " << results[9] << std::endl << std::endl;

}