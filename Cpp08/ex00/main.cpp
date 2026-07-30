#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    std::cout << "=== TEST AVEC STD::VECTOR ===" << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i * 10);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Valeur trouvée : " << *it << std::endl;

        std::cout << "Recherche d'une valeur inexistante (99)..." << std::endl;
        easyfind(vec, 99);
    }
    catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST AVEC STD::LIST ===" << std::endl;
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    try {
        std::list<int>::iterator it = easyfind(lst, 200);
        std::cout << "Valeur trouvée : " << *it << std::endl;

        std::cout << "Recherche d'une valeur inexistante (-5)..." << std::endl;
        easyfind(lst, -5);
    }
    catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}