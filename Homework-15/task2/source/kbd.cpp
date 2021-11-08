#include "main.h"

void input (std::string& array)
{
    int amountOfInt=0;
    while (amountOfInt != 8)
    {
        std::cout << "Please enter only 8 integer parts" << std::endl;
        std::cin >> array;
        amountOfInt = array.size();
    }
}