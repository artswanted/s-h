#include <iostream>
#include <vector>

bool iValidatorEmail (std::string pKEmail){
    bool iCorrect = true;
    bool iValid = false;
    bool iMiddle = false;
    int iDogCounter, iDotCounter;
    std::vector<char> iNotBadSymbol {'!','#', '$', '%', '&', '\'', '*', '+', '-', '/', '=',
                                 '?', '^', '_', '`', '{', '|', '}', '~'};
    std::vector<char> corSymbol {'@', '.'};
    for (int i = 0; i < pKEmail.length(); i++){
        if (pKEmail[pKEmail.size()-1] == corSymbol[1] &&
            pKEmail[0] == corSymbol[1]) {
            iCorrect = false;
            break;
        }
        if (pKEmail[i] == corSymbol[1] && pKEmail[i+1] == corSymbol[1]){
            iCorrect = false;
            break;
        }

/*
        for (int j = 0; j < iNotBadSymbol.size(); j++){
            if (pKEmail[i] == iNotBadSymbol[j]) {
                iCorrect = false;
                break;
            }
        }
        */
        if (!iMiddle && pKEmail[i] == corSymbol[0]){
            iMiddle = true;
        } else if (iMiddle && pKEmail[i] == corSymbol[0]) {
            iCorrect == false;
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
