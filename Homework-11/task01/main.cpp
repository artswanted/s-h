#include <iostream>
#include <string>
#include <fstream>

struct paidList {
    std::string name = "empty";
    double money = 0;
    std::string date = "empty";
};

void addPaid (paidList* person){
    std::ofstream fileWrite ("./paidlist.txt", std::ios::app);
    if (fileWrite.is_open()){
        fileWrite << person->name << "\t" << person->date << "\t" << person->money << std::endl;
        fileWrite.close();
    } else {
        std::cout << "Error. File cannot be saved!";
    }
}

int main() {
    paidList person;
    std::string choice;
    do {
        std::cout << "Input a command \"list\" or \"add\":" << std::endl;
        //choice what we are doing
        do {
            std::cin >> choice;
            if (choice == "add" || choice == "list") {
                break;
            } else {
                std::cout << "Wrong input. Try again.\n:";
            }
        } while (true);

        //add new paid
        if (choice == "add"){
            std::cout << "Please, enter full name:";
            std::cin.ignore();
            std::getline (std::cin, person.name);
            do {
                //std::string date;
                std::cout << "Enter date (DD.MM.YEAR):";
                std::cin.ignore();
                std::getline(std::cin, person.date);
                person.date = person.date.c_str();
                std::cout << std::stoi(person.date.substr(0, 2)) << " / " << std::stoi(person.date.substr(3, 2)) << std::endl;
                std::cout << person.date.substr(2, 1) << " / " << person.date.substr(5, 1) << std::endl;

                if ((std::stoi(person.date.substr(0, 2)) >= 1 && std::stoi(person.date.substr(0, 2)) <= 31) &&
                (std::stoi(person.date.substr(3, 2)) >= 1 && std::stoi(person.date.substr(3, 2)) <= 12) &&
                (person.date.substr(2, 1) == "." && person.date.substr(5, 1) == "."))
                {
                    //person.date = date;
                    break;
                } else {
                    std::cout << "Wrong format! Try again:";
                }
            } while (true);

            double money;
            std::cout << "Enter salary:";
            std::cin >> person.money;
            addPaid(&person);
        } else if (choice != "list"){
            //saveList(*array);
        }
    } while (true);
    return 0;
}
