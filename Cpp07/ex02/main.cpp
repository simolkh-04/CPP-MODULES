#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;

        std::cout << "numbers[2] = " << numbers[2] << std::endl;

        Array<int> copy = numbers;
        copy[2] = 999;

        std::cout << "Original numbers[2] = " << numbers[2] << " (doit rester 20)" << std::endl;
        std::cout << "Copy numbers[2] = " << copy[2] << " (doit etre 999)" << std::endl;

        std::cout << "Tentative d'acces hors limites :" << std::endl;
        std::cout << numbers[50] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception attrapee : " << e.what() << std::endl;
    }

    return 0;
}