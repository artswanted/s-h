#include <iostream>
#include <string>
using namespace std;
/*
string encryptCaeser(string iMessage, int iFormula){
    string encMessage;
    char letter, solution;
    cout << "White + or -" << std::endl; //here you can choice way
    do {
        cin >> solution;
        if (solution == '+') {
            for (int i = 0; i < iMessage.size(); i++){
                if ((iMessage[i] > 'a' && iMessage[i] > 'z') ||
                    (iMessage[i] > 'A' && iMessage[i] > 'Z')){
                    letter = iMessage[i] + iFormula;
                    encMessage += letter;
                } else {
                    encMessage += iMessage[i];
                }
            }
            break;
        } else if (solution == '-'){
            for (int i = 0; i < iMessage.size(); i++){
                if ((iMessage[i] > 'a' && iMessage[i] > 'z') ||
                    (iMessage[i] > 'A' && iMessage[i] > 'Z')) {
                    letter = iMessage[i] - iFormula;
                    encMessage += letter;
                } else {
                    encMessage += iMessage[i];
                }
            }
            break;
        } else cout << "Incorrect." << endl;
    } while (true);

    return encMessage;
}*/
char iChangeSymbol(char iSymbol, int iFormula){
    
    return iSymbol;
}

string encryptCaeser(string iMessage, int iFormula){
    string encMessage;
    for (int i = 0; i < iMessage.size(); i++) {
        encMessage += iChangeSymbol(iMessage[i], iFormula);
    }
    return iMessage;
}

int main() {
    string iSrcMessage;
    int iFormula;
    std::cout << "Welcome to Caesar Encryptor." << std::endl;
    cout << "Enter your message: " << endl;
    getline(cin, iSrcMessage);

    cout << "Write your enc/dec number:" << endl;
    cin >> iFormula;
    iSrcMessage = encryptCaeser(iSrcMessage, iFormula);

    cout << iSrcMessage;
    return 0;
}
