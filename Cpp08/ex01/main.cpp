#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "=== TEST DU SUJET ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << " (Attendu: 2)" << std::endl;
        std::cout << "Longest:  " << sp.longestSpan()  << " (Attendu: 14)" << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST AVEC 10 000 ÉLÉMENTS ===" << std::endl;
    try {
        Span bigSpan(10000);
        std::vector<int> randomNumbers;

        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; ++i) {
            randomNumbers.push_back(std::rand());
        }

        bigSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());

        std::cout << "ShortestSpan: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "LongestSpan:  " << bigSpan.longestSpan()  << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}