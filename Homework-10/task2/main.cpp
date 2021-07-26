#include <iostream>
#include <ctime>
#include <fstream>

int main() {
    std::srand(std::time(nullptr));
    int x, y;
    std::cin >> x >> y;
    std::ofstream file ("../pic.txt");
    if (file.is_open()){
        for (int i = 0; i < y; i++){
            for (int j = 0; j < x; j++){
                file << rand() % 2;
            }
            file << std::endl;
        }
        file.close();
    } else {
        std::cout << "File cannot be opened or created!";
    }
}
