#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::vector<char>> xoVec{ {'-','-','-','-','-'},
                                          {'|',' ',' ',' ','|'},
                                          {'|',' ',' ',' ','|'},
                                          {'|',' ',' ',' ','|'},
                                          {'-','-','-','-','-'}};
    std::vector<std::vector<char>> xoFresh = xoVec;
    char choice;
    bool exit = false, reset = false;
    int line, column;
    do {
        std::cout << "Write X or 0 for play or Q for exit or R for reset: " << std::endl;
        do {
            std::cin >> choice;
            if (choice == 'X' || choice == '0') break;
            else if (choice == 'Q'){
                exit = true;
                break;
            } else if (choice == 'R') {
                reset = true;
                break;
            } else {
                std::cout << "Incorrect!" << std::endl;
            }
        } while (true);

        if (exit) break;
        else if (!reset) {
            std::cout << "Write line number (1-3): " << std::endl;
            do {
                std::cin >> line;
                if (line >= 1 && line <= 3) break;
                else std::cout << "Incorrect!" << std::endl;
            } while (true);

            std::cout << "Write column in line (1-3): " << std::endl;
            do {
                std::cin >> column;
                if (column >= 1 && column <= 3) break;
                else std::cout << "Incorrect!" << std::endl;
            } while (true);

            xoVec[line][column] = choice;
        }

        if (reset) xoVec = xoFresh;

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                std::cout << xoVec[i][j];
            }
            std::cout << std::endl;
        }
    } while (true);

    std::cout << "Have a nice day!" << std::endl;
    return 0;
}