#include "main.h"

void compute(std::string& array)
{
    int sum=0;
    int buffer=stoi(array);
    while (buffer >0)
    {
        sum += buffer % 10;
        buffer /= 10;
    }
    std::cout << sum << std::endl;
}