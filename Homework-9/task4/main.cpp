#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#define NDEBUG

using namespace std;

bool pngChecker(const string sFilePath);

int main() {
    cout << "Input file path:" << endl;
    string sFilePath;
    getline(cin, sFilePath);
    cout << (pngChecker(sFilePath) ? "This is PNG file!" : "This is not PNG file!");
}

bool pngChecker(const string sFilePath){
    char headNumber;
    string headChars;
    ifstream file (sFilePath, std::ios::binary);
    string fileType = sFilePath.substr(sFilePath.length()-4);
#ifndef NDEBUG
    cerr << "File type:" << fileType << endl;
    assert(fileType == ".png" || fileType == ".PNG");
#endif
    if (fileType != ".png" && fileType != ".PNG"){
        return false;
    }
    if (file.is_open()){
        file >> headNumber;
        for(int i = 0; i < 3; ++i)
        {
            char temp;
            file >> temp;
            headChars += temp;
        }
        file.close();
    } else {
        cerr << "File is not found.";
    }
#ifndef NDEBUG
    int debugNumber = headNumber - '0';
    cerr << debugNumber << endl; //кто составлял задачу? почему тип -119 для png файла? проверил на 3х разных файлах, первый символ -167...
    cerr << headNumber << endl;
    cerr << headChars << endl;
    assert(headNumber != -119 && headChars != "PNG");
#endif
    return ((headNumber == -119 || headNumber == -167) && headChars == "PNG");
}
