#include <iostream>

int main() {
    std::string iEmail;
    bool correct;
    std::cout << "Email validator!" << std::endl;

    do {
        std::cout << "Write email for validate: ";
        std::cin >> iEmail;

        if (correct) {
            std::cout << "Email is correct!";
        } else {
            std::cout << "Email isnt correct!";
        }
    } while (true);

    return 0;
}
