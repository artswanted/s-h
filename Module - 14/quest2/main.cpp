#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::vector<char>> xoVec{ {'-','-','-','-','-'},
                                          {'|',' ',' ',' ','|'},
                                          {'|',' ',' ',' ','|'},
                                          {'|',' ',' ',' ','|'},
                                          {'-','-','-','-','-'}};

    std::string iLine;

    std::cout << "You can use .(dot) O and X (template O.X)." << std::endl;
    for (int l = 0; l < 3; l++){
        std::cout << "Write line number "<< l+1 <<": " << std::endl;
        std::cin >> iLine;
        for (int k = 0; k < 3; k++){
            xoVec[1+l][1+k] = iLine[k];
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cout << xoVec[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Have a nice day!" << std::endl;
    return 0;
}