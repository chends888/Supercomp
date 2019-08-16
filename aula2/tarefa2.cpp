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

    std::tuple<double, double> logdur,pow3dur,pow3multdur,sumdur,sqrtdur;

    logdur = std::make_tuple(veclog.get_duration(), veclog.get_duration());
    pow3dur = std::make_tuple(vecpow3.get_duration(), vecpow3.get_duration());
    pow3multdur = std::make_tuple(vecpow3mult.get_duration(), vecpow3mult.get_duration());
    sumdur = std::make_tuple(vecsum.get_duration(), vecsum.get_duration());
    sqrtdur = std::make_tuple(vecsqrt.get_duration(), vecsqrt.get_duration());

    for (int i = 0; i < 10; i++) {
        veclog.run();
        vecpow3.run();
        vecpow3mult.run();
        vecsum.run();
        vecsqrt.run();

        if (veclog.get_duration() > std::get<0>(logdur)) {
            std::get<0>(logdur) = veclog.get_duration();
        }
        if (veclog.get_duration() < std::get<1>(logdur)) {
            std::get<1>(logdur) = veclog.get_duration();
        }

        if (vecpow3.get_duration() > std::get<0>(pow3dur)) {
            std::get<0>(pow3dur) = vecpow3.get_duration();
        }
        if (vecpow3.get_duration() < std::get<1>(pow3dur)) {
            std::get<1>(pow3dur) = vecpow3.get_duration();
        }

        if (vecpow3mult.get_duration() > std::get<0>(pow3multdur)) {
            std::get<0>(pow3multdur) = vecpow3mult.get_duration();
        }
        if (vecpow3mult.get_duration() < std::get<1>(pow3multdur)) {
            std::get<1>(pow3multdur) = vecpow3mult.get_duration();
        }

        if (vecsum.get_duration() > std::get<0>(pow3multdur)) {
            std::get<0>(pow3multdur) = vecsum.get_duration();
        }
        if (vecsum.get_duration() < std::get<1>(pow3multdur)) {
            std::get<1>(pow3multdur) = vecsum.get_duration();
        }

        if (vecsqrt.get_duration() > std::get<0>(sumdur)) {
            std::get<0>(sumdur) = vecsqrt.get_duration();
        }
        if (vecsqrt.get_duration() < std::get<1>(sumdur)) {
            std::get<1>(sumdur) = vecsqrt.get_duration();
        }
    }
    std::cout << "Min Log time: " << (std::get<0>(logdur)) << std::endl;
    std::cout << "Max Log time: " << (std::get<1>(logdur)) << std::endl;

    std::cout << "Min Pow3 time: " << (std::get<0>(pow3dur)) << std::endl;
    std::cout << "Max Pow3 time: " << (std::get<1>(pow3dur)) << std::endl;

    std::cout << "Min Pow3mult time: " << (std::get<0>(pow3multdur)) << std::endl;
    std::cout << "Max Pow3mult time: " << (std::get<1>(pow3multdur)) << std::endl;

    std::cout << "Min Sqrt time: " << (std::get<0>(sqrtdur)) << std::endl;
    std::cout << "Max Sqrt time: " << (std::get<1>(sqrtdur)) << std::endl;

    std::cout << "Min Sum time: " << (std::get<0>(sumdur)) << std::endl;
    std::cout << "Max Sum time: " << (std::get<1>(sumdur)) << std::endl;


}