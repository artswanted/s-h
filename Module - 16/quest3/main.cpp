#define NDEBUG
#include <iostream>
#include <vector>
#include <cassert>


std::vector<int> rebuildVec(std::vector<int> myVec, int n){

    int limit = 20, counter = 1;
    std::vector<int> newVec(20);
    for (int i = 0; i < newVec.size(); i++){
#ifndef NDEBUG
        assert(myVec.size() != limit);
        assert(counter > limit);
#endif
        if (counter == limit){
            newVec[i] = n;
        } else {
            newVec[i] = myVec[i+1];
        }
        counter++;
    }
    return newVec;
}

int main() {
    std::vector<int> myVec;
    int n, limitVec = 20;
    std::cout << "Enter your number:" << std::endl;
    std::cin >> n;
    while (n != -1){
        if (myVec.size() == limitVec){
            myVec = rebuildVec(myVec, n);
        } else {
            myVec.push_back(n);
        }
        std::cin >> n;
    }

    for (int i = 0; i < myVec.size(); i++){
        std:: cout << myVec[i] << " ";
    }

    return 0;
}
