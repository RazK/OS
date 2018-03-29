//
// Created by heimy4prez on 3/29/18.
//
#include <iostream>
#include "osm.h"

int main(int argc, char** argv){
    if (argc != 2){
        std::cerr << "Must provide the number of iterations as an arguments." << std::endl;
        return -1;
    }
    unsigned int iterations = std::stoi(argv[1]);
    double t;

    std::cout << "Running 3 tests on " << iterations << " iterations." << std::endl;

    std::cout << "Running arithmetic test..." << std::endl;
    t = osm_operation_time(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations) << std::endl;

    std::cout << "Running function call test..." << std::endl;
    t = osm_function_time(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations) << std::endl;

    std::cout << "Running alternate function call test..." << std::endl;
    t = osm_function_time_template(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations) << std::endl;

    std::cout << "Running sys trap test..." << std::endl;
    t = osm_syscall_time(iterations);
    std::cout << "Full interval: " << t << ". Per iteration: " << (t / iterations) << std::endl;

    return 0;
}