#include <iostream>
#include <string>
#include <map>

class Phone{
    std::map <std::string, int> addressBook;
};

int main() {
    std::cout << "Input command:";
    std::string choice;
    do {
        std::cin >> choice;
        if (choice == "add"){

        } else if (choice == "call"){

        } else if (choice == "sms") {

        } else if (choice == "exit"){
            break;
        } else {
            std::cout << "Wrong command!" << std::endl;
        }
    } while (true);
}
