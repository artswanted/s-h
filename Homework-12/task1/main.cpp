#include <iostream>
#include <map>
#include <string>

int main() {
    std::map <int, std::string> phoneNumbers;

    while (true) {
        std::string numberOwner;
        int iPhoneNumber;
        int answer;
        std::cout << "Enter phone number (without +):";
        std::cin >> iPhoneNumber;
        std::cout << "Write Name:";
        std::cin.ignore();
        std::getline(std::cin, numberOwner);
        phoneNumbers.insert(std::pair<int, std::string>(iPhoneNumber, numberOwner));
        std::cout << "If you want add another number, write 1 or any other key for exit:";
        std::cin >> answer;
        if (answer != 1) break;
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
