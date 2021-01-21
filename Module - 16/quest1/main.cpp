#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> rebuildVec(std::vector<int> vec, int q){
    std::vector<int> newVec(vec.size());
#ifndef NDEBUG
    assert(vec.size()>0);
#endif
    for (int i = 0; i < vec.size(); i++){
        if(vec[i] != q){
            newVec[i] = vec[i];
        } else {
            for (int c = i; c < vec.size(); c++){
                if(vec[c] != q) {
                    newVec[i] = vec[c];
                    break;
                }
            }
        }
    }
    return newVec;
}

int main() {
    int n=1, c, q;
    std::vector<int> vec(n);
    std::cout << "Enter vector size:";
    std::cin >> n;
    vec.resize(n);
    std::cout << "Enter your number:";
    for (int i = 0; i < n; i++){
        std::cin >> c;
        vec[i]=c;
    }
    std::cout << "Enter number that you want to delete from vector:";
    std::cin >> q;
    vec = rebuildVec(vec, q);
    if (!vec.empty()){
        for (int i = 0; i < vec.size(); i++){
            std::cout << vec[i] << " ";
        }
    } else {
        std::cout << "Now vector is empty!";
    }
    return 0;
}
