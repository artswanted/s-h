#include <iostream>
#include <string>
using namespace std;

char iChangeSymbol(char cSymbol, int iFormula){
    char cFirstSymbol;
    char cLastSymbol;
    if (cSymbol >= 'A' && cSymbol <= 'Z') {
        cFirstSymbol = 'A';
        cLastSymbol = 'Z';
    } else if (cSymbol >= 'a' && cSymbol <= 'z') {
        cFirstSymbol = 'a';
        cLastSymbol = 'z';
    } else {
        return cSymbol;
    }

    int iMovedSymbol = cSymbol + iFormula % 26;

    if (iMovedSymbol > cLastSymbol) {
        cSymbol = cFirstSymbol + iMovedSymbol % cLastSymbol - 1;
    } else if (iMovedSymbol < cFirstSymbol) {
        cSymbol = cLastSymbol - cLastSymbol % iMovedSymbol + 1;
    } else {
        cSymbol += cSymbol % 26;
    }
    return cSymbol;
}

string encryptCaeser(string sMessage, int iFormula){
    string encMessage;
    for (int i = 0; i < sMessage.length(); i++) {
        encMessage += iChangeSymbol(sMessage[i], iFormula);
    }
    return encMessage;
}

string decryptCaeser(string iMessage, int iFormula){
    string decMessage;
    for (int i = 0; i < iMessage.length(); i++) {
        decMessage += iChangeSymbol(iMessage[i], iFormula);
    }
    return decMessage;
}

int main() {
    std::string sMessage;
    int iShift;
    int iCommand;
    do {
        std::cout << "Press 1 to encrypt." << std::endl;
        std::cout << "Press 2 to decrypt." << std::endl;
        std::cout << "Press 0 to quit." << std::endl;
        std::cin >> iCommand;


        if (iCommand == 1) {
            std::cout << std::endl << "Encrypt!" << std::endl;
            std::cout << "Please, input text:";
            std::cin.ignore(32767, '\n');
            std::getline(std::cin, sMessage);
            std::cout << "Please, input shift:";
            std::cin >> iShift;
            std::cout << "Encrypted text: " <<  encryptCaeser(sMessage, iShift) << std::endl;

        } else if (iCommand == 2) {
            std::cout << std::endl << "Decrypt!" << std::endl;
            std::cout << "Please, input text:";
            std::cin.ignore(32767, '\n');
            std::getline(std::cin,sMessage);
            std::cout << "Please, input shift: ";
            std::cin >> iShift;
            std::cout << "Encrypted text: " << decryptCaeser(sMessage, iShift) << std::endl;
        }

    } while (iCommand != 0);

}
