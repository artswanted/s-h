#include <iostream>
#include <vector>

bool iValidatorEmail (std::string pKEmail){
    bool iCorrect = true;
    std::vector<char> badSymbol {'!','#', '$', '%', '&', '\'', '*', '+', '-', '/', '=',
                                 '?', '^', '_', '`', '{', '|', '}', '~'};
    for (int i = 0; i < pKEmail.length(); i++){
        for (int j = 0; j < badSymbol.size(); j++){
            if (pKEmail[i] == badSymbol[j]) {
                iCorrect = false;
                break;
            }
        }
        if (!iCorrect) break;
    }

    return iCorrect;
}

int main() {
    std::string iEmail;
    bool correct;
    int iChoice;

    std::cout << "Email validator!" << std::endl;

    do {
        std::cout << "Write email for validate: ";
        std::cin >> iEmail;
        correct = iValidatorEmail(iEmail);

        if (correct) {
            std::cout << "Email is correct!" << std::endl;
        } else {
            std::cout << "Email isnt correct!"<< std::endl;
        }

        std::cout << "Enter 1 for try again or any number for exit: ";
        std::cin >> iChoice;
        if (iChoice != 1) break;
    } while (true);

    return 0;
}
