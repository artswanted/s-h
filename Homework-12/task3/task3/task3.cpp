#include <iostream>
#include <map>
#include <string>

using namespace std;

bool compareArrays(std::map <char, char>& arrayFirst, std::map <char, char>& arraySecond) {
    int counter = 0;
    if (arrayFirst.size() != arraySecond.size()) return false;
    for (int i = 0; i < arrayFirst.size();) {
        for (int b = 0; b < arraySecond.size(); ++b) {
            if (arrayFirst[i] != arraySecond[b]) {
                //cout << arrayFirst[i] << " VS " << arraySecond[b] << endl;
                return false;
            }
            i++;
        }
    }
    return true;
}

void arrayInsert(std::map <char, char>& textArray, string sUserText) {
    for (int i = 0; i < sUserText.size(); i++) {
        textArray.insert(make_pair (sUserText[i], sUserText[i]));
    }
}

int main()
{
    std::map <char, char> word01;
    std::map <char, char> word02;
    bool check = true;
    int count = 0;
    string sUserText;

    cout << "Input first word: ";
    cin >> sUserText;
    arrayInsert(word01, sUserText);

    cout << "Input second word: ";
    cin >> sUserText;
    arrayInsert(word02, sUserText);

    check = compareArrays(word01, word02);

    if (check) {
        std::cout << "Its anagram" << endl;
    }
    else cout << "its not anagram" << endl;
}

