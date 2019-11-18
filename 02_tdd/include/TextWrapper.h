#pragma once

#include <string>
#include <iostream>

class TextWrapper
{
public:
    int c;
    std::string d;
    std::string final;
    int columns(int numberOfColumns);
    std::string textToTransform(std::string data);

    std::string modified(int, std::string);
    std::string arguments(int, std::string);
};