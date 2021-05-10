#include <iostream>

int main() {
    int x = 10;
    int y = 10;
    int number = 1;
    int array [10][10];
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if (i % 2 != 0){
                int b = 9 - j;
                array[i][b] = number;
            } else {
                array[i][j] = number;
            }
            number++;
        }
    }

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
