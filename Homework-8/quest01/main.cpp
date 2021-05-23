#include <iostream>
#include <vector>

int b[] = {5,6,7,8};

void swapvec (std::vector<int>& vec, int b[]){
    int t = 0;
    for(int i = 0; i < vec.size(); i++){
        t = vec[i];
        vec[i] = b[i];
        b[i]=t;
    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < (sizeof(b)/sizeof(*b)); i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl << "----swap----" << std::endl;
    swapvec(vec, b);
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < (sizeof(b)/sizeof(*b)); i++){
        std::cout << b[i] << " ";
    }
    return 0;
}
