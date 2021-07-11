#include <iostream>
#include <fstream>
#include <string>

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
    std::ifstream file;
    int counter = 0;
    file.open("../words.txt");
    sInputText = keyWordInput();

    while(!file.eof()){
        std::string tempText;
        file >> tempText;
        if (tempText == sInputText)
        {
            counter++;
        }
    }

    if (counter > 0){
        std::cout << "We are found " << counter << " same words in file!";
    } else {
        std::cout << "We are found " << counter << " words in the file!";
    }

    return 0;
}
