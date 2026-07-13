#include "Serialization.hpp"
#include <iostream>

int main()
{
    Data myData;
    myData.id = 42;
    myData.name = "simo";
    std::cout << "adress origine " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << " Raw = " << raw << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "adresse final " << ptr << std::endl;

    if(ptr == &myData)
    {
        std::cout << "Succes ! Les adresses correspondent." << std::endl;
        std::cout << "id = " << ptr->id << " name : " << ptr->name << std::endl;
    }
    else{
        std::cout << "Échec... Les adresses sont différentes." << std::endl;   
    }
    return 0;
}