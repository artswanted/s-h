#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int textFinder (std::vector<std::string> textVec, std::string keyWord){
    int counter = 0;
    for (int i = 0; i < textVec.size(); i++){
        std::string sTempWord = textVec[i];
        if (sTempWord.size() == keyWord.size()){
           for (int j = 0; j < keyWord.size(); j++){
               if (sTempWord[j] != keyWord[j]){
                   break;
               }
               if (j == keyWord.size()-1){
                   counter++;
               }
           }
        }
    }
    return counter;
}

std::string keyWordInput(){
    std::string keyWord;
    std::cout << "Enter your word:";
    do {
        std::cin >> keyWord;
        if (keyWord.size() > 1) break;
        std::cout << "Ops. Your word is so short!";
    } while (true);
    return keyWord;
}

int main() {
    std::string sInputText;
    std::vector<std::string> vFileRead;
    std::ifstream file;
    file.open("../words.txt");
    while(!file.eof()){
        std::string tempText;
        file >> tempText;
        vFileRead.push_back(tempText);
    }

    sInputText = keyWordInput();
    std::cout << sInputText << std::endl;

    int result = textFinder(vFileRead, sInputText);
    if (result > 0){
        std::cout << "We are found " << result << "same words in file!";
    } else {
        std::cout << "We are found " << result << " worlds in the file!";
    }

    return 0;
}
