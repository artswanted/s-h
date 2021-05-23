#include <iostream>

int jump (int step, int maxJump)
{
    if (step < 0)
        return 0;
    else
    if (step == 0)
        return 1;

    int variables = 0;
    for (int i = maxJump; i > 0; --i)
        variables += (jump(step - i, maxJump));

    return variables;
}

int main() {
    std::cout << "Input amount of steps:";
    int step;
    std::cin >> step;

    std::cout << "Input max jump over steps:";
    int maxJump;
    std::cin >> maxJump;

    std::cout << "Have " << jump(step, maxJump) << " variables" << std::endl;
    return 0;
}