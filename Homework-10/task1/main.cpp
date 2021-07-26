#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#define NDEBUG

int main() {
    std::ofstream file ("../final_file.txt", std::ios::app);
    if (file.is_open()){
        do {
            std::string name;
            std::cout << "Please, enter full name:";
            std::getline (std::cin,name);

            std::string date;
            std::cout << "Enter date (DD.MM.YEAR):";
            do {
                std::getline(std::cin, date);
#ifndef NDEBUG
                std::cout << std::stoi(date.substr(0, 2)) << " / " << std::stoi(date.substr(3, 2)) << std::endl;
                std::cout << date.substr(2, 1) << " / " << date.substr(5, 1) << std::endl;
                assert(date.substr(3) != "." && date.substr(6) != ".");
#endif
                if ((std::stoi(date.substr(0, 2)) >= 1 && std::stoi(date.substr(0, 2)) <= 31) &&
                        (std::stoi(date.substr(3, 2)) >= 1 && std::stoi(date.substr(3, 2)) <= 12) &&
                        (date.substr(2, 1) == "." && date.substr(5, 1) == "."))
                {
                    break;
                } else {
                    std::cout << "Wrong format! Try again:";
                }
            }while (true);

            double money;
            std::cout << "Enter salary:";
            std::cin >> money;

            file << name << "\t" << date << "\t" << money << std::endl;

            std::string answer;
            std::cout << "If you want continue, write \"next\", if no, wrine any symbol:";
            std::cin >> answer;
            if(answer != "next"){
                file.close();
                break;
            }
        } while (true);
    } else {
        std::cout << "File is not opened!";
    }
    std::cout << "Have a nice day!";
}
