//
// Created by heimy4prez on 3/29/18.
//
#include osm.h


int main(int argc, char** argv){
    if (argc != 1){
        std::cerr << "Must provide the number of iterations as an arguments.";
        return -1;
    }
    unsigned int iterations = std::stoi(argv[0]);
    double t;

    std::cout << "Running 3 tests on " << iterations << "iterations.";

    std::cout << "Running arithmetic test...";
    t = osm_operation_time(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations);

    std::cout << "Running function call test...";
    t = osm_function_time(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations);

    std::cout << "Running sys trap test...";
    t = osm_syscall_time(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations);



    return 0;

}