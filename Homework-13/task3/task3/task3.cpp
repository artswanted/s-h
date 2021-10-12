#include <iostream>

//#define WINTER
//#define SPRING
//#define SUMMER
#define FALL


int main()
{
#ifdef WINTER
    std::cout << "Its winter!";
#endif

#ifdef SPRING
    std::cout << "Its spring!";
#endif

#ifdef SUMMER
    std::cout << "Its summer!";
#endif

#ifdef FALL
    std::cout << "Its autumn!";
#endif

}

