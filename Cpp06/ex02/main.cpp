#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(NULL));

    Base* randomObject = generate();

    std::cout << "Identification via Pointeur : ";
    identify(randomObject);

    std::cout << "Identification via Référence : ";
    identify(*randomObject);

    delete randomObject;
    return 0;
}