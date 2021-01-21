#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> vec;
    std::cout << "Enter your number:";
    std::cin >> n;
    while(n != -1){
        if(!vec.empty()){
            if (n == vec.back()) {
                vec.pop_back();
            } else {
                vec.push_back(n);
            }
        } else {
            vec.push_back(n);
        }
        std::cin >> n;
    }
    for (int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    return 0;
}
