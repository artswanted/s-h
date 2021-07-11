#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string fileName;
    cout << "Enter file path:";
    cin >> fileName;
    ifstream file;
    file.open(fileName, std::ios::binary);
    if(file.is_open())
    {
        while(!file.eof())
        {
            char buffer[30];
            file.read(buffer, size(buffer)-1);
            buffer[file.gcount()] = '\0';
            cout << buffer;
        }
        file.close();
    }
    else{
        cerr << "File not found!";
    }
}