#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe p;
    if (!p.parseInput(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    p.execute();
    return 0;
}