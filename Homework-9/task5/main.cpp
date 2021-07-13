#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void newPos(const int &num, int &pos);
bool questionViewer(const int &pos);
int getAnswer(const string &ans, const int &pos);

int sector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

int main()
{
    int viewer = 0;
    int player = 0;
    int pos = 0;

    while(viewer != 6 && player != 6){
        int number;
        do{
            cout << "Please enter a number: ";
            cin >> number;
            if(number <= 0) cout << "WARNING: number must be greater than zero." << endl;
        }while(number <= 0);
        number %= 13;

        newPos(number, pos);
        if(questionViewer(pos)){
            string myAnsver;
            cout << "Please enter your answer: ";
            cin >> myAnsver;
            int result;
            result = getAnswer(myAnsver, pos);
            if(result == 1) ++player;
            else if(result == 0) ++viewer;
        }
        cout << "current score: **Player(" << player << ":" << viewer << ")Viewer**" << endl;
    }

    cout << (player > viewer ? "Player wins." : "Viewer wins.") << endl;

    return 0;
}

void newPos(const int &num, int &pos){
    pos = (pos + num) % 13;
    while(sector[pos] == -1){
        pos = (pos + 1) % 13;
    }
    sector[pos] = -1;
}

bool questionViewer(const int &pos){
    string fileName = "../src/" + std::to_string(pos+1) + "_q.txt";
    std::ifstream in;
    in.open(fileName.c_str(), std::ios::binary);
    if (in.is_open()){
        string line;
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
        in.close();
    }else{
        cout << "This file cannot be opened." << endl;
        return 0;
    }
    return 1;
}

int getAnswer(const string &ans, const int &pos){
    string fileName = "../src/" + std::to_string(pos+1) + "_a.txt";
    std::ifstream in;
    in.open(fileName.c_str(), std::ios::binary);
    string answer;
    if (in.is_open()){
        in >> answer;
        in.close();
    }else{
        cout << "This file cannot be opened." << endl;
        return -1;
    }

    if(answer == ans){
        cout << "Player won" << endl;
        return 1;
    }else{
        cout << "Viewer won" << endl;
        return 0;
    }
}
