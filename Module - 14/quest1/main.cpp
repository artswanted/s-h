#include <iostream>
#include <string>
using namespace std;

char iChangeSymbol(char iSymbol, int iFormula){
    if(iSymbol >= 'A' && iSymbol <= 'Z'){
        if (iSymbol + iFormula > 'Z' || iSymbol + iFormula < 'A' ){
            if (iSymbol + iFormula < 'A'){
                return 'Z' - (iFormula - (iSymbol - 'A')+1);
            } else if (iSymbol + iFormula > 'Z'){
                return 'A' + ((iSymbol + iFormula - 'Z')-1);
            } else {
                return iSymbol;
            }
        } else {
            return iSymbol + iFormula;
        }
    } else if (iSymbol >= 'a' && iSymbol <= 'z'){
        if (iSymbol + iFormula > 'z' || iSymbol + iFormula < 'a' ){
            if (iSymbol + iFormula < 'a'){
                //return 'z' - (iFormula - (iSymbol - 'a')+1);
                return  iSymbol += iFormula + 'z' - 'a' + 1;
            } else if (iSymbol + iFormula > 'z'){
                return 'a' + ((iSymbol + iFormula - 'z')-1);
            } else {
                return iSymbol;
            }
        } else {
            return iSymbol + iFormula;
        }
    } else {
        return iSymbol;
    }
}

string encryptCaeser(string iMessage, int iFormula){
    string encMessage;
    //char temp;
    for (int i = 0; i < iMessage.size(); i++) {
        encMessage += iChangeSymbol(iMessage[i], iFormula);
        //encMessage += temp;
    }
    return encMessage;
}

int main() {
    std::string sMessage;
    int shift;
    int iCommand;
    do {
        std::cout << "Press 1 to encrypt." << std::endl;
        std::cout << "Press 2 to decrypt." << std::endl;
        std::cout << "Press 0 to quit." << std::endl;
        std::cin >> iCommand;


        if (iCommand == 1) {
            std::cout << std::endl<< "Encrypt: ";
            std::cout << "Please, input text: ";
            getline(std::cin, sMessage);
            std::cout << "Please, input shift: ";
            std::cin >> shift;
            std::cout << "Encrypted text: " <<  encryptCaeser(sMessage, shift) << std::endl;

        } else if (iCommand == 2) {
            std::cout << std::endl << "Decrypt: ";
            std::cout << "Please, input text: ";
            std::getline(std::cin, sMessage);
            std::cout << "Please, input shift: ";
            std::cin >> shift;
            std::cout << "Encrypted text: " << decryptCaeser(sMessage, shift) << std::endl;
        }

    } while (iCommand != 0);

}
