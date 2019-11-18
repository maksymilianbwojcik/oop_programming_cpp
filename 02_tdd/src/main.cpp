#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;

    auto wrapper = TextWrapper{};

    wrapper.textToTransform("alfabet");
    std::cout << wrapper.textToTransform(std::string) << std::endl;
    return 0;
}
