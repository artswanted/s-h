#include <iostream>
#include <string>
using namespace std;

string encryptCaeser(string iMessage, int iFormula){
    string encMessage;
    char letter, solution;
    cout << "+ or - ?" << endl;
    do {
        cin >> solution;
        if (solution == '+') {
            for (int i = 0; i < iMessage.size(); i++){
                letter = iMessage[i] + iFormula;
                encMessage += letter;
            }
            break;
        } else if (solution == '-'){
            for (int i = 0; i < iMessage.size(); i++){
                letter = iMessage[i] - iFormula;
                encMessage += letter;
            }
            break;
        } else cout << "Incorrect." << endl;
    } while (true);

    return encMessage;
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
