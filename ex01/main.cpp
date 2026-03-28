#include "Serializer.hpp"

int main()
{
    Data dt = {42,'a',3.14};

    uintptr_t raw = Serializer::serialize(&dt);
    Data *ptr = Serializer::deserialize(raw);
    // std::cout<< &dt <<std::endl;
    // std::cout<< raw <<std::endl;
    // std::cout << std::showbase << std::hex << raw  << std::endl; 
    if (ptr == &dt)
        std::cout << "the adress in the serialize is the same as in the deserialize" << std::endl;
    else
        std::cout << "the adress in the serialize is not the same as in the deserialize" << std::endl;
}