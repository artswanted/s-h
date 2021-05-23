#include <iostream>


int jump (int step)
{
    if (step < 0)
        return 0;
    else
    if (step == 0)
        return 1;

    return (jump(step - 3) + jump(step - 2) + jump(step - 1));
}


int main() {
    std::cout << "Input amount of steps: ";
    int step;
    std::cin >> step;

    std::cout << "He has " << jump(step) << " variables." << std::endl;
}