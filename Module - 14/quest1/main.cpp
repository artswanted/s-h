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
    string iSrcMessage;
    int iFormula;
    std::cout << "Welcome to Caesar Encryptor." << std::endl;
    cout << "Enter your message: " << endl;
    getline(cin, iSrcMessage);

    cout << "Write your enc/dec number:" << endl;
    cout << "(template: 4 or -3 or -7)" << endl;
    cin >> iFormula;
    iSrcMessage = encryptCaeser(iSrcMessage, iFormula);

    cout << iSrcMessage;
    return 0;
}
