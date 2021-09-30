#include <iostream>
#include <map>
#include <string>

int main() {
    std::map <std::string, std::string> nameToPhone;

    while (true) {
        std::string numberOwner;
        std::string sPhoneNumber;
        int answer;
        std::cout << "1 - add new contact. 2 - found by surname:";
        std::cin >> answer;

        if (answer == 1) {
            std::cout << "Enter phone number:";
            std::cin >> sPhoneNumber;
            std::cout << "Write surname:";
            std::cin >> numberOwner;

            if (sPhoneNumber != nameToPhone[numberOwner]) {
                std::map <std::string, std::string>::iterator it = nameToPhone.find(numberOwner);
                std::string sNewPhonePool = it->second + " " + sPhoneNumber;
                nameToPhone.erase(it);
                nameToPhone.insert(std::make_pair(numberOwner, sNewPhonePool));
            }
            else {
                nameToPhone.insert(std::make_pair(numberOwner, sPhoneNumber));
            }
        }
        else if (answer == 2) {
            std::cout << "Write surname:";
            std::cin >> numberOwner;
            if (nameToPhone[numberOwner].size() > 0){
                std::map <std::string, std::string>::iterator it = nameToPhone.find(numberOwner);
                std::cout << it->first << ": " << it->second << std::endl;
            } else std::cout << "Missing!";
        }
        else {
            break;
        }
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
