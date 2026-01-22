#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}
Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}
Cat::Cat(const Cat &other):Animal(other)
{
    std::cout << "Cat copy constructor alled" << std::endl;
    this->_brain = new Brain(*(other._brain));
}
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if(this != &other)
    {
        this->type = other.type;
        if(this->_brain)
            delete _brain;
        this->_brain = new Brain(*(other._brain));
    }
    return *this;
}

void Cat::makeSound () const
{
    std::cout << "Miow! Miow!" << std::endl;
}