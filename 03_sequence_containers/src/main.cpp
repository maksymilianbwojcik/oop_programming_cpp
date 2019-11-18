#include <iostream>

#include "Dummy.h"

int main(int argc, char* argv[])
{
    Dummy dummy{};

    std::cout << "dummy.add(2, 4) = " << dummy.add(2, 4) << std::endl;

    return 0;
}