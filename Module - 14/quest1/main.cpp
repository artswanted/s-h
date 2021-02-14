#include <iostream>
#include <string>
using namespace std;

char iChangeSymbol(char iSymbol, int iFormula){
    if ((iSymbol < 'A' && iSymbol > 'Z') && (iSymbol < 'a' && iSymbol > 'z')) {
        cout << "bug 1";
        return iSymbol;
    }

    if(iSymbol > 'A' && iSymbol < 'Z'){
        if (iSymbol + iFormula > 'Z' || iSymbol + iFormula < 'A' ){
            if (iSymbol + iFormula < 'A'){
                return 'Z' - (iFormula - (iSymbol - 'A'));
            } else if (iSymbol + iFormula > 'Z'){
                return 'A' + (iSymbol + iFormula - 'Z');
            }
        } else {
            return iSymbol + iFormula;
        }
    } else if (iSymbol < 'a' && iSymbol > 'z'){
        cout << "bug 2";
        if (iSymbol + iFormula > 'z' || iSymbol + iFormula < 'a' ){
            if (iSymbol + iFormula < 'a'){
                return 'z' - (iFormula - (iSymbol - 'a'));
            } else if (iSymbol + iFormula > 'Z'){
                return 'a' + (iSymbol + iFormula - 'z');
            }
        } else {
            cout << "bug 3";
            return iSymbol + iFormula;
        }
    }
}

string encryptCaeser(string iMessage, int iFormula){
    string encMessage;
    char temp;
    for (int i = 0; i < iMessage.size(); i++) {
        temp = iChangeSymbol(iMessage[i], iFormula);
        encMessage += temp;
        cout << iChangeSymbol(iMessage[i], iFormula);
    }
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
