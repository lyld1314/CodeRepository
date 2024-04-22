#include <iostream>

extern "C"{
    void dis();
}

void dis()
{
    std::cout << "Hello World" << std::endl;
}