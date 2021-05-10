#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector <int> vec = {-100, -70, -43, -13, -5, -2, -1, 0, 1, 3, 6, 7, 15, 25, 30, 50, 71, 99, 130};
    for (int i = 0; i < vec.size(); i++){
        for (int j = i+1; j < vec.size()-1; j++){
            if (abs(vec[i]) > abs(vec[j])){
                int temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            } else {break;}
        }
    }

    for (int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    return 0;
}
