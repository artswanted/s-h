#include "main.h"

void write(std::string& array)
{
    std::ofstream file("data.txt");
    file << array;
    file.close();
}

void read (std::string& array)
{
    std::ifstream file("data.txt");
    file >> array;
    file.close();
}