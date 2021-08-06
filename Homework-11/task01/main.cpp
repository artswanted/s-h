#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

struct paidList {
    std::string firstNname = "empty";
    std::string lastName = "empty";
    double money = 0;
    std::string date = "empty";
};

void addPaid (paidList* person){
    std::ofstream fileWrite ("./paidlist.txt", std::ios::app);
    if (fileWrite.is_open()){
        fileWrite << person->firstNname << " " << person->lastName << "\t" << person->date << "\t" << person->money << std::endl;
        fileWrite.close();
    } else {
        std::cout << "Error. File cannot be saved!";
    }
}

void loadList (){
    std::ifstream fileRead ("./paidlist.txt");
    paidList person;
    if (fileRead.is_open()){
        while (!fileRead.eof()){
            fileRead >> person.firstNname >> person.lastName >> person.date >> person.money;
            std::cout << person.firstNname << " " << person.lastName << " " << person.date << " " << person.money << std::endl;;
        }
        fileRead.close();
    } else {
        std::cout << "Error. File cannot be opened!";
    }
}

int main() {
    paidList person;
    //std::vector <paidList> array = {};
    std::string choice;
    do {
        std::cout << "Input a command \"list\" or \"add\":" << std::endl;
        do {
            std::cin >> choice;
            if (choice == "add" || choice == "list") {
                break;
            } else {
                std::cout << "Wrong input. Try again.\n:";
            }
        } while (true);

        if (choice == "add"){
            std::cout << "Please, enter first name and after enter last name:";
            std::cin.ignore();
            std::getline (std::cin, person.firstNname);
            std::getline (std::cin, person.lastName);
            do {
                std::cout << "Enter date (DD.MM.YEAR):";
                std::getline(std::cin, person.date);

                if (person.date.substr(2, 1) == "." && person.date.substr(5, 1) == ".")
                {
                    break;
                } else {
                    std::cout << "Wrong format! Try again:";
                }
            } while (true);

            std::cout << "Enter salary:";
            std::cin >> person.money;
            addPaid(&person);
        } else if (choice == "list"){
            loadList();
        } else {
            break;
        }
    } while (true);
    return 0;
}
