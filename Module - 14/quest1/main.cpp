#include <iostream>
#include <string>
#include <cassert>
#define _debug;
using namespace std;

string encryptCaeser(string iMessage, int iFormula){
    string encMessage;
    char letter;
    cout << "+ or - ?";
    for (int i = 0; i < iMessage.size(); i++){
        letter = iMessage[i]-iFormula;
        encMessage[i] = letter;
    }
    return encMessage;
}
/*
string decryptCaeser(string iMessage, int iFormula){
    string decMessage;
    char letter, solution;
    cout << "+ or - ?";

    for (int i = 0; i < iMessage.size(); i++){
        letter = iMessage[i]-iFormula;
        decMessage[i] = letter;
    }
    return decMessage;
}*/

int main() {
    string iSrcMessage;
    int iFormula;
    std::cout << "Welcome to Caesar Encryptor." << std::endl;
    cout << "Enter your message: " << endl;
    getline(cin, iSrcMessage);
/*
    cout << "Enter your choice." << endl << "1. Encrypt" << endl << "2. Decrypt" << endl;
    do {
        cin >> iChoice;
        if (iChoice == 1 || iChoice == 2) break;
        else cout << "Incorrect!";
    } while (true);

#ifdef _debug
    assert(iChoice == 1 || iChoice == 2);
#endif
*/
    cout << "Write your enc/dec number:" << endl;
    cin >> iFormula;
    iSrcMessage = encryptCaeser(iSrcMessage, iFormula);
/*
    if (iChoice == 1){
        iSrcMessage = encryptCaeser(iSrcMessage, iFormula);
    }
    else {
        iSrcMessage = decryptCaeser(iSrcMessage, iFormula);
    }
    */

    return 0;
}
